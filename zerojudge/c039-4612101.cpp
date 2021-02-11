#include <algorithm>
#include <iostream>
using namespace std;
int f(int x)
{
	int y = 1;
	while (x != 1)
	{
		x = x % 2 ? 3 * x + 1 : x / 2;
		y++;
	}
	return y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	while (cin >> i >> j)
	{
		int n = 0;
		cout << i << ' ' << j << ' ';
		if (i > j)
			swap(i, j);
		for (int k = i; k <= j; k++)
			n = max(n, f(k));
		cout << n << endl;
	}
	return 0;
}
