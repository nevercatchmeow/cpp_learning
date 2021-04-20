#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
--------------------------------------------------
模板应用：
	1.char类型数组选择排序（从小到大）。
	2.int类型数组选择排序（从小到大）。

--------------------------------------------------
*/

//template<typename T>
template<class T>
void mySwap(T& a,T& b){
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void mySort(T arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		int min = i;
		for(int j = i+1; j < len; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		if(i != min)
		{
			mySwap(arr[min], arr[i]);
		}
	}
}

template<class T>
void printArr(T arr[], int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test()
{
	char charArray[] = "helloworld";
	int len = strlen(charArray);
	mySort(charArray, len);
	printArr(charArray, len);

	int intArray[] = { 5, 7, 1, 4, 2, 3 };
	len = sizeof(intArray) / sizeof(int);
	mySort(intArray, len);
	printArr(intArray, len);
}


int main()
{
	test();

	system("pause");
	return EXIT_SUCCESS;
}
