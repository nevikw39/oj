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
		short l = s.length();
		for (short i = 0; i < l; i++)
		{
			for (short j = i; j < i + l; j++)
				cout << s[j % l];
			cout << endl;
		}
	}

	return 0;
}
