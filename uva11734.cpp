#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, i = 0;
	cin >> n;
	cin.ignore(1, '\n');
	while (i < n)
	{
		string a, b;
		getline(cin, a);
		getline(cin, b);
		cout << "Case " << ++i << ": ";
		if (a == b)
			cout << "Yes\n";
		else
		{
			a.erase(remove_if(a.begin(), a.end(), ::isspace), a.end());
			b.erase(remove_if(b.begin(), b.end(), ::isspace), b.end());
			cout << (a == b ? "Output Format Error\n" : "Wrong Answer\n");
		}
	}
    return 0;
}