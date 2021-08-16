#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long n, k;
	while (cin >> n >> k)
	{
		k = (2 * k < n) ? k : (n - k);
		double d = 0;
		for (long i = 0; i < k;)
			d += log10(n--) - log10(++i);
		cout << (int)d + 1 << endl;
	}
	return 0;
}
