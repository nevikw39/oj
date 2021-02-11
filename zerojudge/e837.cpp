#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int mx = 1, mxi;
    for (int i = 1, l = s.length(); i < l; i++)
    {
        int lx = 1, lxi = i - 1;
        while (i < l && s[i] == s[i - 1] + 1)
        {
            i++;
            lx++;
        }
        if (mx <= lx)
        {
            mx = lx;
            mxi = lxi;
        }
    }
    if (mx > 1)
        cout << mx << ' ' << s.substr(mxi, mx) << '\n';
    else
        cout << "1 " << s.back() << '\n';
    return 0;
}