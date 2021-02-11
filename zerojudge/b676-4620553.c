#include <stdio.h>
int main()
{
	int x;
	char s[] = "UGYTI";
	scanf("%d", &x);
	putchar(s[x % 5]);
	return 0;
}
