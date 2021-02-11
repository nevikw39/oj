#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s && s != "0")
	{
		short a[2] = {0};
		for (short i = 0; i < s.length(); i++)
			a[i % 2] += s[i] - '0';
		cout << s << ((a[0] - a[1]) % 11 ? " is not " : " is ") << "a multiple of 11.\n";
	}
	return 0;
}
