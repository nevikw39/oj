#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n)
		cout << "f91(" << n << ") = " << (n <= 100) * 91 + (n >= 101) * (n - 10) << endl;
	return 0;
}
