#include <iostream>
#include <iterator>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long n;
	cin >> n;
	multiset<long> ms;
	ms.insert(n);
	cout << n << endl;
	auto it = ms.begin();
	while (cin >> n)
	{
		ms.insert(n);
		if (ms.size() % 2)
		{
			if (n >= *it)
				cout << *it << endl;
			else
				cout << *--it << endl;
		}
		else
		{
			if (n >= *it)
				cout << (*it + *++it) / 2 << endl;
			else
				cout << (*it + *prev(it)) / 2 << endl;
		}
	}
	return 0;
}
