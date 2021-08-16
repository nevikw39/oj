#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x, a[30001] = {0}, c = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x);
		a[x]++;
		c = max(c, a[x]);
	}
	for (int i = 1; i <= 30000; i++)
		if (a[i] == c)
			printf("%d %d\n", i, c);
	return 0;
}
