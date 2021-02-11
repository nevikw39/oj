#include <iostream>
#include <string>
#include <array>
using namespace std;
using uint = unsigned int;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s[] = {"BCG ", "BGC ", "CBG ", "CGB ", "GBC ", "GCB "};
	while (cin)
	{
		uint t = 0;
		array<uint, 3> b, c, g;
		array<uint, 6> a;
		for (char i = 0; i < 3; i++)
		{
			cin >> b[i] >> g[i] >> c[i];
			t += b[i] + g[i] + c[i];
		}
		if (cin.eof())
			break;
		a[0] = t - b[0] - c[1] - g[2];
		a[1] = t - b[0] - g[1] - c[2];
		a[2] = t - c[0] - b[1] - g[2];
		a[3] = t - c[0] - g[1] - b[2];
		a[4] = t - g[0] - b[1] - c[2];
		a[5] = t - g[0] - c[1] - b[2];
		uint n = 0;
		for (uint i = 1; i < 6; i++)
			if (a[n] > a[i])
				n = i;
		cout << s[n] << a[n] << endl;
	}
	return 0;
}
