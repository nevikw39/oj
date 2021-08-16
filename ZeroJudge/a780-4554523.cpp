#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double o, e, a;
	while (cin >> o >> e >> a && o)
	{
		double m = o / e;
		cout << fixed << setprecision(2) << m << ' ' << a / m << endl;
	}
	return 0;
}
