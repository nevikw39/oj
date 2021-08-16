#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	while (cin >> a >> b && a && b)
	{
		int n = sqrt(a), m = sqrt(b);
		cout << (m - n + (n * n == a)) << endl;
	}
	return 0;
}
