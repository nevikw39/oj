#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	char c;
	short w = 0, l = 0;
	vector<bool> v;
	while (cin.get(c) && c != 'E')
		if (c == 'W' || c == 'L')
			v.push_back(c == 'W');
	for (bool i : v)
	{
		(i ? w : l)++;
		if ((w >= 11 || l >= 11) && abs(w - l) > 1)
		{
			cout << w << ':' << l << endl;
			w = 0;
			l = 0;
		}
	}
	cout << w << ':' << l << "\n\n";
	w = 0;
	l = 0;
	for (bool i : v)
	{
		(i ? w : l)++;
		if ((w >= 21 || l >= 21) && abs(w - l) > 1)
		{
			cout << w << ':' << l << endl;
			w = 0;
			l = 0;
		}
	}
	cout << w << ':' << l << endl;
	return 0;
}
