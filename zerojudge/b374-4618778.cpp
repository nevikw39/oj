#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	array<short, 30001> a = {0};
	short n, m = 0;
	cin >> n;
	while (n--)
	{
		short tmp;
		cin >> tmp;
		m = m > ++a[tmp] ? m : a[tmp];
	}
	for (short i = 1; i < 30001; i++)
		if (a[i] == m)
			cout << i << ' ' << m << endl;
	return 0;
}
