#include <iostream>
#include <string>
#include <array>
#include <set>
using namespace std;
int main()
{
	array<short, 26> a = {1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3};
	array<short, 26> b = {0, 1, 2, 3, 4, 5, 6, 7, 4, 8, 9, 0, 1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 2, 0, 1, 3};
	short n;
	while (cin >> n)
	{
		short t = 0, o = 0, f = 0;
		set<string> s;
		while (n--)
		{
			char l;
			string n;
			cin >> l >> n;
			short x = l - 'A', sum = a[x] + b[x] * 9;
			for (auto &i : n)
				sum += (i - '0') * (8 - (&i - n.c_str()));
			sum += n[8] - '0';
			n += l;
			if (sum % 10 || n[0] > '2')
				f++;
			else if (s.find(n) == s.end())
			{
				t++;
				s.insert(n);
			}
			else
				o++;
		}
		cout << t << ',' << o << ',' << f << endl;
	}
	return 0;
}
