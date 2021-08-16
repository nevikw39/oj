#include <algorithm>
#include <iostream>
#include <string>
#include <list>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	list<string> l;
	while (cin >> s && s != "SHOW")
	{
		string x;
		cin >> x;
		if (s == "ADD")
			l.push_back(x);
		else if (s == "INSERT")
		{
			cin >> s;
			auto n = find(l.begin(), l.end(), s);
			l.insert(n, x);
		}
		else
			l.remove(x);
	}
	for (auto i : l)
		cout << i << ' ';
	cout << endl;
	return 0;
}
