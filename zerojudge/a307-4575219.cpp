#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		if (s.front() == '-')
		{
			s.erase(s.begin());
			cout << '-';
		}
		reverse(s.begin(), s.end());
		while (*s.begin() == '0')
			s.erase(s.begin());
		cout << s << endl;
	}
	return 0;
}
