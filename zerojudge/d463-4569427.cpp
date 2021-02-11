#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long n;
	while (cin >> n)
		cout << (unsigned long)round(pow(n, 1.0 / 3)) << endl;
	return 0;
}
