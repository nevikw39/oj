#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	while (cin >> n >> k)
		cout << ((!n || n >= k && k > 0 && !(n % k)) ? "Ok!\n" : "Impossib1e!\n");
	return 0;
}
