#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long n, m;
	while (cin >> n >> m)
		cout << (n * (n + 1) / 2) * (m * (m + 1) / 2) << endl;
	return 0;
}
