#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    unsigned long a, b;
	while (cin >> a >> b)
		cout << (a < b ? b - a : a - b) << '\n';
    return 0;
}