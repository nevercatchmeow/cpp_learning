#include <stdio.h>

int main()
{

#ifdef DEBUG
	printf("DEBUG hello c\n");
#endif
	printf("hello c\n");

	return 0;
}
