#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		short m, n;
		cin >> m >> n;
		cout << (m / 3) * (n / 3) << endl;
	}
	return 0;
}
