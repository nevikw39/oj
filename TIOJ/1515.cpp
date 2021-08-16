#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int sa[200002], tmp[2][200002], c[200002], *x = tmp[0], *y = tmp[1], m = 500, n, rk[200002], lcp[200002], val = 0;
    string s;
    cin >> n;
    cin.ignore(1, '\n');
    getline(cin, s);
    for (int i = 0; i < m; ++i)
        c[i] = 0;
    for (int i = 0; i < n; ++i)
        c[x[i] = s[i]]++;
    for (int i = 1; i < m; ++i)
        c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; --i)
        sa[--c[x[i]]] = i;
    for (int k = 1; k < n; k <<= 1)
    {
        for (int i = 0; i < m; ++i)
            c[i] = 0;
        for (int i = 0; i < n; ++i)
            c[x[i]]++;
        for (int i = 1; i < m; ++i)
            c[i] += c[i - 1];
        int p = 0;
        for (int i = n - k; i < n; ++i)
            y[p++] = i;
        for (int i = 0; i < n; ++i)
            if (sa[i] >= k)
                y[p++] = sa[i] - k;
        for (int i = n - 1; i >= 0; --i)
            sa[--c[x[y[i]]]] = y[i];
        y[sa[0]] = p = 0;
        for (int i = 1; i < n; ++i)
        {
            int a = sa[i], b = sa[i - 1];
            if (x[a] == x[b] && a + k < n && b + k < n && x[a + k] == x[b + k])
                ;
            else
                p++;
            y[sa[i]] = p;
        }
        if (n == p + 1)
            break;
        swap(x, y), m = p + 1;
    }
    for (int i = 0; i < n; ++i)
        rk[sa[i]] = i;
    for (int i = 0; i < n; ++i)
        if (rk[i] == 0)
            lcp[rk[i]] = 0;
        else
        {
            if (val)
                --val;
            int p = sa[rk[i] - 1];
            while (val + i < n && val + p < n && s[val + i] == s[val + p])
                val++;
            lcp[rk[i]] = val;
        }
    cout << *max_element(lcp, lcp + n) << '\n';
    return 0;
}