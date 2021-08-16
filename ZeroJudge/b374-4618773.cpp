#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	array<int, 30001> a = {0};
	int n, m = 0;
	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		a[tmp]++;
		m = max(m, a[tmp]);
	}
	for (int i = 1; i < 30001; i++)
		if (a[i] == m)
			cout << i << ' ' << m << endl;
	return 0;
}
