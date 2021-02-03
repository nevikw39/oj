#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int foobar()
{
    string s;
    cin >> s;
    switch (s[0])
    {
    case 'f':
        return 2 * foobar() - 3;
    case 'g':
        return 2 * foobar() + foobar() - 7;
    case 'h':
        return 3 * foobar() - 2 * foobar() + foobar();
    default:
        return stoi(s);
    }
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << foobar() << '\n';
    return 0;
}