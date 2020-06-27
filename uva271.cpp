#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
bool f(char x, int &n)
{
    switch (x)
    {
    case 'p' ... 'z':
        n++;
        return true;
    case 'N':
        if (n > 0)
            return true;
    case 'C':
    case 'D':
    case 'E':
    case 'I':
        if (n > 1)
        {
            n--;
            return true;
        }
    default:
        return false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    while (getline(cin, s))
    {
        int n = 0;
        bool b = false;
        for (int i = s.length() - 1; i + 1; i--)
            if (!f(s[i], n))
            {
                b = true;
                break;
            }
        cout << (n == 1 && !b ? "YES\n" : "NO\n");
    }
    return 0;
}