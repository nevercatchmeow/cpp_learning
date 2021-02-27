/**
 * @file vector.hpp
 * @author Kevin MRZ (714092359@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef VECTOR_H
#define VECTOR_H

typedef int Rank;
#define DEFAULT_CAPACITY 3 // 默认初始容量

template <typename T>
class Vector
{
protected:
    Rank _size;                                  // 规模
    int _capacity;                               // 容量
    T *_elem;                                    // 数据区
    void copyFrom(T const *A, Rank lo, Rank hi); // 复制数组区间A[lo, hi)
    void expand();                               // 空间不足时扩容
    void shrink();                               // 装填因子过小时压缩
    bool bubble(Rank lo, Rank hi);               // 扫描交换
    void bubbleSort(Rank lo, Rank hi);           // 冒泡排序算法
    Rank max(Rank lo, Rank hi);                  // 选取最大元素
    void selectionSort(Rank lo, Rank hi);        // 选择排序算法
    void merge(Rank lo, Rank mi, Rank hi);       // 归并算法
    void mergeSort(Rank lo, Rank hi);            // 归并排序算法
    Rank partition(Rank lo, Rank hi);            // 轴点构造算法
    void quickSort(Rank lo, Rank hi);            // 快速排序算法
    void heapSort(Rank lo, Rank hi);             // 堆排序算法

public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) // 容量c、规模s、所有元素初始为v
    {
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
        {
        } // s<=c
    }
    Vector(T const *A, Rank n) { copyFrom(A, 0, n); }                           // 数组整体复制
    Vector(T const *A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }               // 数组区间复制
    Vector(Vector<T> const &V) { copyFrom(V._elem, 0, V._size); }               // 向量整体复制
    Vector(Vector<T> const &V, Rank lo, Rank hi) { copyFrom(V._elem, lo, hi); } // 向量区间复制
    // 析构函数
    ~Vector() { delete[] _elem; } // 释放内部空间
    // 只读访问接口
    Rank size() const { return _size; }                                               // 规模
    bool empty() const { return !size; }                                              // 判空
    int disordered() const;                                                           // 是否有序
    Rank find(T const &e) const { return find(e, 0, _size); }                         // 无序向量整体查找
    Rank find(T const &e, Rank lo, Rank hi) const;                                    // 无序向量区间查找
    Rank search(T const &e) const { return (0 >= _size) ? -1 : search(e, 0, _size); } // 有序向量整体查找
    Rank search(T const &e, Rank lo, Rank hi) const;                                  // 有序向量区间查找
    // 可写访问接口
    T &operator[](Rank r) const;                         // 重载下标操作符
    Vector<T> &operator=(Vector<T> const &V);            // 重载赋值运算符
    T remove(Rank r);                                    // 删除秩为r的元素
    int remove(Rank lo, Rank hi);                        // 删除秩在区间[lo, hi)内的元素
    Rank insert(Rank r, T const &e);                     // 插入元素
    Rank insert(T const &e) { return insert(_size, e); } // 默认作为末元素插入
    void sort(Rank lo, Rank hi);                         // 对[lo, hi)排序
    void sort() { sort(0, _size); }                      // 整体排序
    void unsort(Rank lo, Rank hi);                       // 对[lo, hi)置乱
    void unsort() { unsort(0, _size); }                  // 对[lo, hi)置乱
    int deduplicate();                                   // 无序去重
    int uniquify();                                      // 有序去重
    // 遍历
    void traverse(void (*)(T &)); // 遍历(使用函数指针，只读或局部性修改)
    template <typename VST>
    void traverse(VST &); // 遍历(使用函数对象，全局性修改)
};

// copyFrom
template <typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi)
{
    _elem = new T[_capacity = 2 * (hi - lo)];
    _size = 0;
    while (lo < hi)
    {
        _elem[_size] = A[lo++];
    }
}

// operator=
template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> const &V)
{
    if (_elem)
    {
        delete[] _elem;
    }
    copyFrom(V._elem, V.size());
    return *this;
}

// expand
template <typename T>
void Vector<T>::expand()
{
    if (_size < _capacity) // 未满员时不扩容
    {
        return;
    }
    if (_capacity < DEFAULT_CAPACITY) // 不低于最小容量
    {
        _capacity = DEFAULT_CAPACITY;
    }
    T *oldElem = _elem;
    _elem = new T[_capacity <<= 1]; // 容量加倍
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = oldElem[i]; // 复制原向量内容
    }
    delete[] oldElem; // 释放原空间
}

// shrink
template <typename T>
void Vector<T>::shrink()
{
    if (_capacity < DEFAULT_CAPACITY << 1) // 容量小于2*DEFAULT_CAPACITY时不收缩
    {
        return;
    }
    if (_size << 2 > _capacity) // 25%为界
    {
        return;
    }
    T *oldElem = _elem;
    _elem = new T[_capacity >>= 1];
    for (int i = 0; i < _size; i++)
    {
        _elem[i] = oldElem[i];
    }
    delete[] oldElem;
}

// operator[]
template <typename T>
T &Vector<T>::operator[](Rank r) const
{
    return _elem[r]; // assert: 0 <= r < _size
}

// permute 整体置乱
template <typename T>
void permute(Vector<T> &V)
{
    for (int i = V.size(); i > 0; i--)
    {
        swap(V[i - 1], V[rand() % i]);
    }
}

// unsort 区间置乱
template <typename T>
void Vector<T>::unsort(Rank lo, Rank hi)
{
    T *v = _elem + lo; // _elem[lo, hi) ==> V[0, hi-lo)
    for (Rank i = hi - lo; i > 0; i--)
    {
        swap(V[i - 1], V[rand() % i]);
    }
}

template <typename T>
static bool lt(T *a, T *b) { return lt(*a, *b); }
template <typename T>
static bool lt(T &a, T &b) { return a < b; }
template <typename T>
static bool eq(T *a, T *b) { return eq(*a, *b); }
template <typename T>
static bool eq(T &a, T &b) { return a == b; }

template <typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const
{
    while ((lo < hi--) && (e != _elem[hi]))
        ;      // assert: 0 <= lo < hi <= _size
    return hi; // 若 hi < lo，则失败
}

template <typename T>
Rank Vector<T>::insert(Rank r, T const &e)
{
    expand();
    for (int i = _size; i > r; i--)
    {
        _elem[i] = _elem[i - 1];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <typename T>
Rank Vector<T>::remove(Rank lo, Rank hi)
{
    if (lo == hi)
    {
        return 0;
    }
    while (hi < _size)
    {
        _elem[lo++] = _elem[hi++];
    }
    _size = lo;
    shrink();
    return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r)
{
    T e = _elem[r];
    remove(r, r + 1);
    return e;
}

template <typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    Rank i = 1;
    while (i < _size)
    {
        (find(_elem[i], 0, i) < 0) ? i++ : remove(i); // 在其前缀中寻找与其雷同者并删除之
    }
    return oldSize - _size;
}

template <typename T>
void Vector<T>::traverse(void (*visit)(T &)) // 函数指针
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

template <typename T>
template <typename VST>
void Vector<T>::traverse(VST &visit)
{
    for (int i = 0; i < _size; i++)
    {
        visit(_elem[i]);
    }
}

template <typename T> // 函数对象：递增一个T类对象
struct Increase
{
    virtual void operator()(T &e) // 假设T可直接递增或已重载++
    {
        e++;
    }
};

template <typename T>
void increase(Vector<T> &V) // 统一递增向量中的各元素
{
    V.traverse(Increase<T>()); // 以Increase<T>为基本操作进行遍历
}

template <typename T>
int Vector<T>::disordered() const // 返回相邻逆序对的个数
{
    int n = 0;
    for (int i = 1; i < _size; i++)
    {
        if (_elem[i - 1] > _elem[i])
        {
            n++;
        }
    }
    return n;
}

// template <typename T>
// int Vector<T>::uniquify() // 有序向量唯一化（低效版）：每次删除元素需要移动后续所有元素
// {
//     int oldSize = _size;
//     Rank i = 1;
//     while (i < _size)
//     {
//         _elem[i - 1] == _elem[i] ? remove(i) : i++; // 雷同则删除后一元素
//     }
//     return oldSize - _size;
// }

template <typename T>
int Vector<T>::uniquify() // 有序向量唯一化（高效版）
{
    Rank i = 0, j = 0;

    while (++j < _size)
    {
        if (_elem[i] != _elem[j])
        {
            _elem[++i] = _elem[j];
        }        
    }
    _size = ++i;
    shrink();
    return j - i;
}



#endif // VECTOR_H