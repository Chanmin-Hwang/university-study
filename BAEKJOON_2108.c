#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* first, const void* second)
{
	int* a = (int*)first;
	int* b = (int*)second;

	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int arith(int list[], int n)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += (list[i]);
	}

	return round(sum / n);
}

int median(int list[], int n)
{
	if (n == 1)
		return list[0];
	else
		return list[(n + 1) / 2 - 1];
}

int mode(int list[], int n)
{
	int ar[8001] = { 0 };
	int i, index, max = 0, cnt = 0;

	for (i = 0; i < n; i++)
	{
		index = list[i] + 4000;
		ar[index] += 1;
		
		if (ar[index] > max)
			max = ar[index];
	}

	for (i = 0, index = 0; i < 8001 ; i++)
	{
		if (ar[i] == 0)
			continue;

		if (ar[i] == max)
		{
			if (cnt == 0)
			{
				index = i;
				cnt += 1;
			}
			else if (cnt == 1)
			{
				index = i;
				break;
			}
		}
	}
	return index - 4000;

}

int range(int list[], int n)
{
	int max = list[n - 1];
	int min = list[0];

	return max - min;
}

int main()
{
	int i, n;
	int* list;

	scanf("%d", &n);
	list = (int*)calloc(n, sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf(" %d", &list[i]);
	}
	
	qsort(list, n, sizeof(list[0]), compare);

	printf("%d\n", arith(list, n));
	printf("%d\n", median(list, n));
	printf("%d\n", mode(list, n));
	printf("%d\n", range(list, n));
	
	return 0;
}
