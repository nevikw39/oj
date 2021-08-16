#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long a, b;
	while (cin >> a >> b)
		cout << (1L << (8 * (a - 1) + b - 1)) << endl;
	return 0;
}
