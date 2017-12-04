#include<stdio.h>

void main()
{
	int num[30];
	int i, n, a, j;
	printf("enter the value of n\n");
	scanf_s("%d",&n);
	printf("enter the number of n\n");
	for (i = 0;i < n;++i)
		scanf_s("%d",&num[i]);
	printf("Enter the position of element to split the array \n");
	scanf_s("%d", &a);
	for (i = 0; i < a; ++i)
	{
		num[n] = num[0];
		for (j = 0; j < n; ++j)
		{
			num[j] = num[j + 1];
		}
	}
	printf("The resultant array is\n");
	for (i = 0; i < n; ++i)
	{
		printf("%d\n", num[i]);
	}
	_getch();
}

