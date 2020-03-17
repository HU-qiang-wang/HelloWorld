#include<stdio.h>

int fabonacci_count(int num)
{
	int f3 = 0;
	int f1 = 0;
	int f2 = 0;
	int i = 0;
	if((num >0)&&(num<3))
	{
		f3 = 1;
	}
	else
	{
		f1 = 1;
		f2 = 1;
		i = num - 2;
		while(i)
		{
			f3 = f2 + f1;
			f1 = f2;
			f2 = f3;
			i--;
		}
	}

	return f3;
}

void fabonacci_show(int for_n)
{
	int i = 1;
	while((for_n - i) >= 0)
	{
		printf("%d %d\n", i, fabonacci_count(i));
		i++;
	}
}


int main(void)
{
	int num = 0;
	printf("Please enter the number: \n");
	scanf("%d", &num);
	printf("Starting show the fibonacci \n");
	fabonacci_show(num);
	return 0;
}

