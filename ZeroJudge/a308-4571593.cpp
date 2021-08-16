#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s, str;
	cin >> s;
	cin.ignore(1, '\n');
	getline(cin, str);
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	s.push_back(' ');
	s.insert(0, " ");
	str.push_back(' ');
	str.insert(0, " ");
	size_t x = str.find(s);
	if (str.find(s) != string::npos)
	{
		short c = 0;
		size_t i = 0;
		while ((i = str.find(s, i)) != string::npos)
		{
			c++;
			i += s.length() - 2;
		}
		cout << c << ' ' << x << endl;
	}
	else
		cout << "-1\n";
	return 0;
}
