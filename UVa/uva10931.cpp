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
	{
		int sum = 0;
		deque<char> d;
		string s;
		for (; n; n >>= 1)
		{
			d.push_front(n & 1);
			sum += n & 1;
		}
		for (const int &i : d)
			s.push_back(i + '0');
		cout << "The parity of " << s <<  " is " << sum << " (mod 2).\n";
	}
    return 0;
}