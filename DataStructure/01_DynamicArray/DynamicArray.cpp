#include "DynamicArray.hpp"

Array::Array()
{
    int *p = new int[initialLen];
	m_data = p;
	m_capacity = initialLen;
	m_size = 0;
}

Array::Array(int len)
{
	int *p = new int[len];
	m_data = p;
	m_capacity = len;
	m_size = 0;
}

void Array::reserve(int newLen)
{
	int *p = new int[newLen];
	for (int i = 0; i < m_size; i++)
	{
		p[i] = m_data[i];
	}
	delete[] m_data;
	m_data = p;
	m_capacity = newLen;
}

void Array::insert(int index, int num)
{
	if (index < 0 || index > m_size)
	{
		cout << "Index should be between 0 and " << m_size << "." << endl;
		throw 0;
	}

	for (int i = m_size; i > index; i--)
	{
		m_data[i] = m_data[i - 1];
	}
	m_data[index] = num;
	m_size++;
    if (m_size > (m_capacity * 3 / 4))
	{
		resize(m_capacity * 2);
	}
}

void Array::insertToFirst(int num)
{
	insert(0, num);
}

void Array::insertToLast(int num)
{
    insert(m_size, num);
}

int Array::erase(int index)
{
	if (index < 0 || index >= m_size)
	{
		cout << "Index should be between 0 and " << m_size << "!" << endl;
		throw 0;
	}
    if (m_size == 0)
    {
        cout << "Array is empty!" << endl;
		throw 0;
    }
    
	int res = m_data[index];
	m_size--;
	for (int i = index; i < m_size; i++)
	{
		m_data[i] = m_data[i + 1];
	}
	if (m_size < m_capacity / 4)
	{
		resize(m_capacity / 2);
	}
	return res;
}

int Array::eraseFromFirst()
{
    return erase(0);
}

int Array::eraseFromLast()
{
    if (m_size == 0)
    {
        cout << "Array is empty!" << endl;
		throw 0;
    }
	m_size--;
    int res = m_data[m_size];
	if (m_size < m_capacity / 4)
	{
		resize(m_capacity / 2);
	}
	return res;
}

void Array::eraseElement(int num)
{
	int flag = indexOf(num);
	if (flag != -1)
	{
		erase(flag);
	}
}

void Array::set(int index, int num)
{
	if (index < 0 || index >= m_size)
	{
		cout << "Index should be between 0 and " << m_size << "!" << endl;
		throw 0;
	}
	m_data[index] = num;
}

int Array::get(int index)
{
	if (index < 0 || index >= m_size)
	{
		cout << "Index should be between 0 and " << m_size << "!" << endl;
		throw 0;
	}

	return m_data[index];
}

int Array::indexOf(int num)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == num)
		{
			return i;
		}
	}
	return -1;
}

bool Array::isContains(int num)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] == num)
		{
			return true;
		}
	}
	return false;
}

int Array::capacity()
{
	return m_capacity;
}

int Array::size()
{
	return m_size;
}

bool Array::isEmpty()
{
	return m_size == 0;
}

void Array::print()
{
	cout << "[Array]    ";
	cout << "Capacity = " << m_capacity << "    Size = " << m_size << endl;
	cout << "[";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_data[i];
		if (i != m_size - 1)
		{
			cout << ",";
		}
	}
	cout << "]" << endl;
}
