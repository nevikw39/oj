#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s))
    {
        int sum = 0;
        bool b = false;
        for (const char &c : s)
        {
            sum += b && !isalpha(c);
            b = isalpha(c);
        }
        sum += b;
        cout << sum << '\n';
    }
    return 0;
}