#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		set<string> s;
		while (n--)
		{
			string str;
			cin >> str;
			s.insert(str);
		}
		int q;
		cin >> q;
		while (q--)
		{
			string str;
			cin >> str;
			if (s.find(str) != s.end())
			cout << "yes\n";
			else
			{
				s.insert(str);
				cout << "no\n";
			}
		}
	}
	return 0;
}
