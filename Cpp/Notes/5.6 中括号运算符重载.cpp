/*
--------------------------------------------------
[]运算符重载：见myArray类实现。
--------------------------------------------------
*/

int& myArray::operator[](int index)
{
	return this->pAddress[index];
}