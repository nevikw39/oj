#include <algorithm>
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
		if (!all_of(s.begin(), s.end(), ::isalpha))
		{
			cout << "Fail\n";
			continue;
		}
		short sum = 0;
		for (char c : s)
			sum += tolower(c) - 'a' + 1;
		cout << sum << endl;
	}
	return 0;
}
