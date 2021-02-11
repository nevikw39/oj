#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short t;
	cin >> t;
	cin.ignore(2);
	while (t--)
	{
		int sum = 0;
		map<string, short> m;
		string s;
		while (getline(cin, s) && !s.empty())
		{
			m[s]++;
			sum++;
		}
		for (auto i : m)
			cout << i.first << ' ' << fixed << setprecision(4) << 100.0 * i.second / sum << endl;
		cout << endl;
	}
	return 0;
}
