#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int inline myabs(int x) // absolute value function based on bitwise operation, which is a little bit efficient
{
    return (x ^ (x >> 31)) - (x >> 31);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string plus[] = {"", " + "}, minus[] = {"-", " - "}, symbols[] = {"x^8", "x^7", "x^6", "x^5", "x^4", "x^3", "x^2", "x"};
    while (cin)
    {
        array<int, 9> a;
        for (int &i : a)
            cin >> i;
        if (!cin)
        break;
        bool flag = false;
        for (int i = 0; i < 8; i++)
            if (a[i])
            {
                cout << (a[i] > 0 ? plus[flag] : minus[flag]) << (myabs(a[i]) > 1 ? to_string(myabs(a[i])) : "") << symbols[i];
                flag = true;
            }
        if (a[8])
        {
            if (flag)
                cout << (a[8] > 0 ? " + " : " - ") << myabs(a[8]);
            else
                cout << a[8];
        }
        else if (!flag)
            cout << '0';
        cout << '\n';
    }
    return 0;
}