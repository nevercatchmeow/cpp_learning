#include <iostream>

void removeSpacesFromString()
{
	char str = "[ abc 123 456 ]";
	int num = 0;
	int i;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			++num;
		else
			str[i - num] = str[i];
	}
	str[i - num] = '\0';
	std::cout << str << std::endl;
}

int main()
{
	removeSpacesFromString();

	return 0;
}