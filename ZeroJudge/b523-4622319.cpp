#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	set<string> s;
	string str;
	while (getline(cin, str))
	{
		if (s.find(str) != s.end())
			cout << "YES\n";
		else
		{
			s.insert(str);
			cout << "NO\n";
		}
	}
	return 0;
}
