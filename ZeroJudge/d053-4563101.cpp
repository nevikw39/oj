#include <iostream>
using namespace std;
using pci = pair<char, int>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, m;
	while (cin >> n >> m)
		cout << n * m - 1 << endl;
	return 0;
}
