#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int k = (-1 + sqrt(8 * n + 1)) / 2;
	cout << k * (2 * k * k + 3 * k + 1) / 6 + (n - k * (k + 1) / 2) * (k + 1);
	return 0;
}
