/*
--------------------------------------------------
extern C：
第一种：形如extern "C" void show()	（Cpp文件下）
告知编译器用C的方式对show()进行链接。（void show()在c文件中，Cpp不包含show()的头文件）


第二种：对c的头文件进行修改，在c++中调用c文件
原因：c++会对函数名称进行修饰（因为重载），无法找到C中的函数（C中不修饰函数名称）
--------------------------------------------------
*/

//【条件编译】C++中使用C的编译方式。
#ifdef __cplusplus
extern "C" {
#endif
	/*add somethings*/
#ifdef __cplusplus
}
#endif