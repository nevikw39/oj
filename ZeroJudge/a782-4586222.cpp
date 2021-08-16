#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s) && s != "END")
	{
		stringstream ss(s);
		vector<string> v;
		while (ss >> s)
			v.push_back(s);
		for (auto i : v)
			cout << (char)toupper(i.front());
		cout << ' ' << s << endl;
	}
	return 0;
}
