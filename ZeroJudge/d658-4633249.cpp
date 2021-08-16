#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, i = 0;
	while (cin >> n && n > 0)
		cout << "Case " << ++i << ": " << ceil(log2(n)) << endl;
	return 0;
}
