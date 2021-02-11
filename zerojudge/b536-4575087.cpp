#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		int sum = 0;
		char c;
		s.erase(remove_if(s.begin(), s.end(), [](char x) { return !isdigit(x) && x != 'X'; }), s.end());
		if (s.length() == 10)
		{
			for (char i = 0; i < 9; i++)
				sum += (s[i] - '0') * (10 - i);
			c = 11 - sum % 11 + '0';
			c = c > '9' ? 'X' : c;
		}
		else
		{
			for (char i = 0; i < 12; i++)
				sum += (s[i] - '0') * (1 + i % 2 * 2);
			c = 10 - sum % 10 + '0';
			c = c > '9' ? '0' : c;
		}
		cout << (c == s.back() ? "T\n" : "F\n");
	}
	return 0;
}
