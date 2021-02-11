#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n)
	{
		set<short> s;
		while (n--)
		{
			short tmp;
			cin >> tmp;
			s.insert(tmp);
		}
		cout << s.size() << endl;
		for (short i : s)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}
