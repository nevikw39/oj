#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (getline(cin, s))
	{
		s.push_back('\n');
		vector<string> v;
		for (char c : s)
		{
			string t("|");
			for (short i = 7; i >= 0; i--)
				t.push_back(c & (1 << i) ? 'o' : ' ');
			t.insert(6, 1, '.');
			t.push_back('|');
			v.push_back(t);
		}
		cout << "___________\n";
		for (auto i : v)
			cout << i << endl;
		cout << "___________\n";
	}
	return 0;
}
