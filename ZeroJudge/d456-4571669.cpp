#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	cin.ignore(1, '\n');
	while (n--)
	{
		char a, b;
		string s, t, v;
		getline(cin, s);
		getline(cin, v);
		a = v[0];
		b = v[1];
		short x = s.rfind(a), y = s.rfind(b);
		if (x > y)
			swap(x, y);
		x++;
		t = s.substr(x, y - x);
		s.erase(x, y - x);
		cout << s << endl
			 << t << endl;
	}
	return 0;
}
