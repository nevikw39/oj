#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	double t1, t2, t3, x1, x3;
	while (cin >> t1 >> t2 >> t3 >> x1 >> x3)
		cout << fixed << x1 + (t2 - t1) / (t3 - t1) * (x3 - x1) << endl;
	return 0;
}
