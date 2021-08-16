#include <iostream>
using namespace std;
using pci = pair<char, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short t;
	cin >> t;
	while (t--)
	{
		int g, l;
		cin >> g >> l;
		if (l % g)
			cout << "-1\n";
		else
			cout << g << ' ' << l << endl;
	}
	return 0;
}
