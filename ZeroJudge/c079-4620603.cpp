#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, k;
	while (cin >> n >> k)
	{
		short sum = n;
		while (n >= k)
		{
			sum += n / k;
			n = n / k + n % k;
		}
		cout << sum << endl;
	}
	return 0;
}
