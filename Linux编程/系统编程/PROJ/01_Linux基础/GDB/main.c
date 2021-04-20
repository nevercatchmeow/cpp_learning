#include <stdio.h>

int Sum(int n)
{
   int sum = 0;
   int i = 0;
   for(i; i < n; i ++)
   {
      sum += i;
   }
   return sum;
}

int main()
{
   int i;
   int a = 0;
   for(i = 1; i <= 100; i ++)
   {
      a += i;
   }
   printf("a= %d \n", a);
   printf("sum= %d \n", Sum(100) );
}
