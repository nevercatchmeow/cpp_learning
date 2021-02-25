#include "DynamicArray.hpp"
using namespace std;

void ArrayTest()
{
    cout << "====================" << endl;
    cout << "Dynamic Array Test!" << endl;
    cout << "--------------------" << endl;

    Array arr(8);
    for (int i = 1; i <= 6; i++)
    {
        arr.insert(i-1, i);
    }
    arr.print();

    cout << "下标为3的元素是：" << arr.get(3) << endl;
    cout << "元素6的下标索引是：" << arr.indexOf(6) << endl;
    cout << "是否包含元素7：bool = " << arr.isContains(7) << endl;

    arr.insertToFirst(0);
    arr.print();

    arr.insertToLast(7);
    arr.print();

    arr.eraseFromFirst();
    arr.print();

    arr.eraseFromLast();
    arr.print();

    for (int i = 0; i < 3; i++)
    {
        arr.erase(3);
        arr.print();
    }
    
    arr.eraseElement(2);
    arr.print();

    arr.set(1, 2);
    arr.print();

    cout << "====================" << endl;
    cout << endl;
}

int main()
{
    ArrayTest();

    return 0;
}