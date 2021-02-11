#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short x, y;
	cin >> x >> y;
	y += 30;
	x += 2 + !(y < 60);
	cout << setw(2) << setfill('0') << x % 24 << ':' << setw(2) << setfill('0') << y % 60 << endl;
	return 0;
}
