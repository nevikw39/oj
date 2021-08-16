#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	vector<short> v(n + 1);
	for (auto &i : v)
		cin >> i;
	short x = v[0], l = n;
	cout << (x == 1 ? "x" : x == -1 ? "-x" : to_string(x) + "x") << (l == 0 || l == 1 ? "" : "^" + to_string(l));
	v.erase(v.begin());
	for (auto &i : v)
		if (i)
		{
			l = n - (&i - v.data()) - 1;
			cout << (i >= 0 ? '+' : '-') << ((i == 1 || i == -1) && l != 0 ? "" : to_string(abs(i))) << (l == 0 ? "" : l != 1 ? "x^" + to_string(l) : "x");
		}
	return 0;
}
