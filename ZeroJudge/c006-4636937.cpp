#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	short n, a, b, c;
	while (cin >> n >> a >> b >> c && n || a || b || c)
		cout << ((n + 40 - a) % 40 + (b + 40 - a) % 40 + (b + 40 - c) % 40) * 9 + 1080 << endl;
	return 0;
}
