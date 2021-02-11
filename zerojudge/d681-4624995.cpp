#include <iostream>
#include <sstream>
#include <string>
using namespace std;
inline void _and(string &a, const string &b)
{
	for (char i = 0; i < 5; i++)
		a[i] = (a[i] == '1' && b[i] == '1') ? '1' : '0';
}
inline void _or(string &a, const string &b)
{
	for (char i = 0; i < 5; i++)
		a[i] = (a[i] == '0' && b[i] == '0') ? '0' : '1';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s))
	{
		string t, n;
		stringstream ss;
		ss.str(s);
		ss >> n;
		cout << n;
		while (ss >> s >> t)
		{
			if (s == "or")
			{
				cout << "||";
				_or(n, t);
			}
			else
			{
				cout << "&&";
				_and(n, t);
			}
			cout << t;
		}
		cout << " = " << n << endl;
	}
	return 0;
}
