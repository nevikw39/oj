#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		int sum = 0;
		string t(s);
		t.erase(remove_if(t.begin(), t.end(), [](char x) { return !isdigit(x); }), t.end());
		for (char i = 0; i < 9;)
			sum += (t[i] - '0') * ++i;
		char c = sum % 11 + '0';
		c = c > '9' ? 'X' : c;
		if (c == s.back())
			t = "Right\n";
		else
		{
			t = s;
			t.back() = c;
			t.push_back('\n');
		}
		cout << t;
	}
	return 0;
}
