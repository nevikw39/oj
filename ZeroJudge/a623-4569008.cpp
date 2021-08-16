#include <iostream>
using namespace std;
int main()
{
	long n, m;
	while (cin >> n >> m)
	{
		long sum = 1;
		for (long i = n; i > (n - m); i--)
			sum *= i;
		for (long i = m; i > 1; i--)
			sum /= i;
		cout << sum << endl;
	}
	return 0;
}
