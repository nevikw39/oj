#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n)
	{
		array<bool, 2001> a;
		for (bool &i : a)
			i = false;
		a[0] = true;
		while (n--)
		{
			short tmp;
			cin >> tmp;
			a[tmp] = true;
		}
		auto it = a.begin();
		while (*it)
			it++;
		cout << (it - a.begin()) << endl;
	}
	return 0;
}
