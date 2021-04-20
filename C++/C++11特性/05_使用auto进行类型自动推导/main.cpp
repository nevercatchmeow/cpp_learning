/*
    auto自动推导类型：
        说明：
            1.auto不代表实际的类型，仅是一个类型声明的占位符，并不适用于所有场景。
            2.使用auto声明的变量必须进行初始化（以便编译器推导类型），在编译时将auto占位符替换为真正的类型。
        使用：
            auto可与指针、引用结合使用，并可用volatile、const限定符，
                a.当变量是指针或引用类型时，推导结果会保留volatile、const。
                b.当变量不是指针或引用类型时，推导结果会忽略volatile、const。
        不允许使用auto的四个场景：
            1.不能作为函数参数使用：auto声明时必须初始化。
            2.不能用于类的非静态成员变量和非常量静态成员变量的初始化：
                类的非静态成员变量属于对象。
                类的非常量静态成员变量不能在类内直接初始化。
            3.不能使用auto关键字定义数组。
            4.不能使用auto推导模板参数。
        auto的应用：
            1.用于STL的容器遍历。
            2.推断模板函数返回值。

    volatile关键字：提示编译器不对该变量做优化，每次使用时都从内存读取。
    C++11之前，auto修饰变量表示变量是自动存储的，与static相对。

    Compile: g++ main.cpp -o main -std=c++11
*/
#include <iostream>
#include <map>

class Test
{
public:
    Test();
    ~Test();

    // auto v1 = 0; // auto不能用于类的非静态成员初始化。
    // static auto v2 = 0;  // 静态非常量成员不能再类内初始化。
    static const auto v3 = 0;
};

class T1
{
public:
    static int get()
    {
        return 10;
    }
};

class T2
{
public:
    static std::string get()
    {
        return "hello MRZ";
    }
};

template <class T>
void func(void)
{
    auto ret = T::get();
    std::cout << "ret: " << ret << std::endl;
}

void test()
{
    auto x = 3.14;
    auto y = 520;
    // auto nb; // 未初始化，无法推导。
    
    int temp1 = 10;

    auto* a1 = &temp1;    // a1: int*
    auto a2 = &temp1;     // a2: int*
    auto& a3 = temp1;     // a3: int
    auto a4 = temp1;      // a4: int

    // const
    int temp2 = 250;
    const auto b1 = temp2;  // b1: int
    auto b2 = b1;           // b2: int
    const auto& b3 = temp2; // b3: const int&
    auto& b4 = b3;          // b4: const int&
    auto* pt4 = &b1;        // pt4: const int*

    // auto应用：遍历容器
    std::map<int, std::string> mp;
    mp.insert(std::make_pair(1, "a"));
    mp.insert(std::make_pair(2, "b"));
    mp.insert(std::make_pair(3, "c"));
    // std::map<int, std::string>::iterator it = mp.begin();
    auto it = mp.begin();
    for (; it != mp.end(); it++)
    {
        std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    }

    // auto应用：推断模板返回值类型
    func<T1>();
    func<T2>();
}

int main(int argc, char* argv[])
{
    test();

    return 0;
}