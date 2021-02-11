#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	array<unsigned int, 10001> a;
	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i < 10001; i++)
		a[i] = (a[i - 1] + a[i - 2]) % 1000000007;
	int n;
	while (cin >> n)
		cout << a[n] << endl;
	return 0;
}
