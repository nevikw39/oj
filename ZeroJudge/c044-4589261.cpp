#include <functional>
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
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	map<char, int> m;
	vector<pci> v;
	while (n--)
	{
		string s;
		getline(cin, s);
		s.erase(remove_if(s.begin(), s.end(), [](char x) { return !isalpha(x); }), s.end());
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		for (char c : s)
			m[c]++;
	}
	move(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), [](pci a, pci b) { return a.second == b.second ? a.first < b.first : a.second > b.second; });
	for (auto i : v)
		cout << i.first << ' ' << i.second << endl;
	return 0;
}
