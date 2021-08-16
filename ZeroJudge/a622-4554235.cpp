#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	vector<size_t> vl;
	vector<string> vs;
	while (getline(cin, s) && s != "END")
	{
		vs.push_back(s);
		vl.push_back(s.length());
	}
	size_t l = *max_element(vl.begin(), vl.end());
	for (int i = 0; i < l; i++)
	{
		for (auto j : vs)
			cout << (i < j.length() ? j[i] : ' ') << "  ";
		cout << endl;
	}
	return 0;
}
