#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
using pci = pair<char, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s))
	{
		map<char, int> m;
		vector<pci> v;
		for (char c : s)
			m[c]++;
		move(m.begin(), m.end(), back_inserter(v));
		sort(v.begin(), v.end(), [](pci a, pci b) { return a.second == b.second ? a.first > b.first : a.second < b.second; });
		for (auto i : v)
			cout << (short)i.first << ' ' << i.second << endl;
		cout << endl;
	}
	return 0;
}
