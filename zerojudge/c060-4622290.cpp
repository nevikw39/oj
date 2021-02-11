#include <iostream>
#include <string>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	array<short, 9> a;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5] >> a[6] >> a[7] >> a[8])
	{
		auto it = a.begin();
		while (!*it && it != a.end())
			it++;
		if (it == a.end())
		{
			cout << "0\n";
			continue;
		}
		int n = *it, l = 8 - (it - a.begin());
		cout << (n == 1 ? "" : n == -1 ? "-" : to_string(n)) << (l == 0 ? "" : l != 1 ? "x^" + to_string(l) : "x");
		it++;
		for (; it != a.end(); it++)
			if (*it)
			{
				n = *it;
				l = 8 - (it - a.begin());
				cout << (n >= 0 ? " + " : " - ") << (n == 1 && l != 0 ? "" : to_string(abs(n))) << (l == 0 ? "" : l != 1 ? "x^" + to_string(l) : "x");
			}
		cout << endl;
	}
	return 0;
}
