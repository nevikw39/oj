#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int sum = 0;
		bool *v = (bool *) malloc(1000001);
		memset(v, 0, 1000001);
		while (n--)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			memset(v + a, 1, b - a);
		}
		for (int i = 0; i < 1000001; i++)
			sum += v[i];
		printf("%d\n", sum);
	}
	return 0;
}
