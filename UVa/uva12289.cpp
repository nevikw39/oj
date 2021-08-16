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
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		cout << (s.length() > 3 ? '3' : ((s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e') > 1 ? '1' : '2')) << '\n';
	}
    return 0;
}