#include <iostream>
#include <string>
using namespace std;
bool f(char x, int &n)
{
	switch (x)
	{
	case 'p' ... 'z':
		n++;
		return true;
	case 'N':
		if (n > 0)
			return true;
	case 'C':
	case 'D':
	case 'E':
	case 'I':
		if (n > 1)
		{
			n--;
			return true;
		}
	default:
		return false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		int n = 0;
		bool b = false;
		for (int i = s.length() - 1; i + 1; i--)

			if (!f(s[i], n))
			{
				b = true;
				break;
			}
		cout << (n == 1 && !b ? "YES\n" : "NO\n");
	}
	return 0;
}
