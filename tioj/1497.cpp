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
    string s;
    getline(cin, s);
    int sa[100001], tmp[2][100001], c[100001], *x = tmp[0], *y = tmp[1], m = 500, n = s.length();
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
    for (int i = 0; i < n; i++)
        cout << sa[i] << '\n';
    return 0;
}