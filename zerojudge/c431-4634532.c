#include <stdio.h>
int main()
{
	int n;
	short a[101];
	for (char i = 0; i < 101; i++)
		a[i] = 0;
	scanf("%d", &n);
	while (scanf("%d", &n) != EOF)
		a[n]++;
	for (short i = 1; i < 101; i++)
		while (a[i]--)
			printf("%d ", i);
	return 0;
}
