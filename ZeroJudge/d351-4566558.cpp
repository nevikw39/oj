#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (!cin.eof())
	{
		string s;
		while (getline(cin, s) && s == "___________")
		{
			string t;
			while (getline(cin, s) && s != "___________")
			{
				char c = 0;
				s.erase(s.begin());
				s.erase(s.begin() + 5);
				s.erase(s.end() - 1);
				for (char i = 0; i < 8; i++)
					if (s[i] == 'o')
						c += 1 << (7 - i);
				t.push_back(c);
			}
			cout << t;
		}
	}
	return 0;
}
