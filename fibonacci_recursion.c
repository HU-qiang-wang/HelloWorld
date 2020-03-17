#include<stdio.h>

int fab(int n)
{
	if((n == 1)||(n == 2))
	{
		return 1;
	}
	else return fab(n-1) + fab(n-2);
}

int main(void)
{
	int n = 0;
	scanf("%d", &n);
	printf("the number is %d\n", fab(n));
	return 0;
}

