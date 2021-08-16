#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
	while (cin >> n && n)
		cout << n * (n + 1) * (2 * n + 1) / 6 << '\n';
    return 0;
}