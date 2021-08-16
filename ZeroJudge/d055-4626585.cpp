#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		double ax, ay, bx, by, cx, cy;
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		cout << fixed << setprecision(0) << abs(ax * by - ay * bx + bx * cy - by * cx + cx * ay - cy * ax) / 14 << endl;
	}
	return 0;
}
