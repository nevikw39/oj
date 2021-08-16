#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		long sum = 0;
		short f;
		cin >> f;
		while (f--)
		{
			long a, b, c;
			cin >> a >> b >> c;
			sum += a * c;
		}
		cout << sum << endl;
	}
	return 0;
}
