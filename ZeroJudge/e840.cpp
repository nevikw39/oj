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
    int n = 0, a = 0, d = 0, l = s.length(), c = 0;
    for (int i = 0; i < l; i++)
        if (isalpha(s[i]))
            a++, n -= max(c - 1, 0) << 1, c = 0;
        else if (isdigit(s[i]))
            d++, c++;
    n += (-max(c - 1, 0) << 1) + (l >= 8 && a && d ? 10 : -5) + l * 3 + a * 3 + d * 2 - !a * l - !d * l;
    cout << n << '\n';
    return 0;
}