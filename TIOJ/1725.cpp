#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
T inline bwmin(T x, T y)
{
    return y ^ ((x ^ y) & -(x < y));
}
template <typename T>
T inline bwmax(T x, T y)
{
    return x ^ ((x ^ y) & -(x < y));
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l = 0, r = 0, len;
    string a, b, s;
    cin >> n >> a >> b;
    s = b + '#' + a + a;
    len = s.length();
    vector<int> z1(len), z2(len), v;
    for (int i = 1; i < len; i++)
    {
        z1[i] = bwmax(bwmin(z1[i - l], r - i), 0);
        while (i + z1[i] < len && s[z1[i]] == s[i + z1[i]])
            ++z1[i];
        if (i + z1[i] - 1 > r)
        {
            l = i;
            r = i + z1[i] - 1;
        }
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    s = b + '#' + a + a;
    l = r = 0;
    for (int i = 1; i < len; i++)
    {
        z2[i] = bwmax(bwmin(z2[i - l], r - i), 0);
        while (i + z2[i] < len && s[z2[i]] == s[i + z2[i]])
            ++z2[i];
        if (i + z2[i] - 1 > r)
        {
            l = i;
            r = i + z2[i] - 1;
        }
    }
    for (int i = n + 1; i < (n << 1 | 1); i++)
        if (z1[i] + z2[3 * n - i + 2] + 1 == n)
            v.push_back(i - n - 1);
    if (v.empty())
    {
        cout << "NIE\n";
        return 0;
    }
    cout << "TAK\n"
         << v.front();
    for (int i = 1, l = v.size(); i < l; i++)
        cout << ' ' << v[i];
    cout << '\n';
    return 0;
}