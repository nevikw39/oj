#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		short e, f, c, sum = 0;
		cin >> e >> f >> c;
		e += f;
		while (e >= c)
		{
			sum += e / c;
			e = e / c + e % c;
		}
		cout << sum << endl;
	}
	return 0;
}
