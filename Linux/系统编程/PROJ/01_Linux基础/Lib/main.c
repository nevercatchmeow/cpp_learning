#include <stdio.h>

#include "head.h"

int main()
{

	int result1 = 0;
	int result2 = 0;
	
	result1 = add(5,3);
	result2 = sub(5,3);

	printf("%d\n", result1);
	printf("%d\n", result2);

	return 0;
}
