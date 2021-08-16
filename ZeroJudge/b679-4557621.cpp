#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long x;
	while (cin >> x)
		cout << fixed << setprecision(0) << floor(sqrt(2 * x)) << endl;
	return 0;
}
