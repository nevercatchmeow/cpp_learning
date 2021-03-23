#include <stdio.h>

#include "head.h"

int main()
{

	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	
	result1 = add(5,3);
	result2 = sub(5,3);
	result3 = sum(5,3);

	printf("add:%d\n", result1);
	printf("sub:%d\n", result2);
	printf("sum:%d\n", result3);

	return 0;
}
