#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <map>
using namespace std;
using pci = pair<char, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	short n;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		map<char, int> m;
		string s;
		getline(cin, s);
		s.erase(remove_if(s.begin(), s.end(), [](char c){return !isalpha(c);}), s.end());
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		for (char i : s)
			m[i]++;
		vector<pci> v;
		move(m.begin(), m.end(), back_inserter(v));
		sort(v.begin(), v.end(), [](pair<char, int> a, pair<char, int> b) { return a.second > b.second ? true : a.second == b.second ? a.first < b.first : false; });
		int max = v.front().second;
		for (auto it = v.begin();it->second == max;it++)
			cout << it->first;
		cout << endl;
	}
	return 0;
}
