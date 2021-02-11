#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	while (cin >> a >> b >> c)
		cout << a << " 個餅乾，" << (b + min(a / 10, c / 2)) << " 盒巧克力，" << c << " 個蛋糕。\n";
	return 0;
}
