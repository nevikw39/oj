#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		int ans;
		cin >> ans;
		n--;
		while (n--)
		{
			int tmp;
			cin >> tmp;
			ans = __gcd(ans, tmp);
		}
		cout << ans << endl;
	}
	return 0;
}
