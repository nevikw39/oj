#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long n;
	while (cin >> n)
		cout << (long)log2(n) + 1 << endl;
	return 0;
}
