#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<string, bool> is_ac;
	map<string, string> m;
	short n, ac = 0, sac = 0;
	cin >> n;
	while (n--)
	{
		string id, state;
		cin >> id >> state;
		if (state == "AC")
			is_ac[id] = true;
		m[id] = state;
	}
	for (auto i : is_ac)
		if (i.second)
		{
			ac++;
			sac += m[i.first] == "AC";
		}
	cout << sac * 100 / ac << '%';
	return 0;
}
