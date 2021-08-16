#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	map<string, short> m;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		string s;
		stringstream ss;
		getline(cin, s);
		ss.str(s);
		ss >> s;
		m[s]++;
	}
	for (auto i : m)
		cout << i.first << ' ' << i.second << endl;
	return 0;
}
