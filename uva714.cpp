#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
long long f(const vector<long long> &v, long long l, long long m)
{
    for (long long i = 0; i < m; i++)
        if (v[i] > l)
            return m + 1;
    long long y = 1;
    for (long long i = m - 1, sum = 0; i >= 0; i--)
    {
        if (sum + v[i] > l)
        {
            y++;
            sum = 0;
        }
        sum += v[i];
    }
    return y;
}
void g(const vector<long long> &v, long long l, long long m, long long k)
{
    long long sum = v[m], s = m - 1;
    while (s >= k && sum + v[s] <= l)
        sum += v[s--];
    if (s != -1)
    {
        g(v, l, s, k - 1);
        cout << " / ";
    }
    for (long long i = s + 1; i < m; i++)
        cout << v[i] << ' ';
    cout << v[m];
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    long long n;
    cin >> n;
    while (n--)
    {
        long long m, k, l = 0, r;
        cin >> m >> k;
        vector<long long> v(m);
        for (long long &i : v)
        {
            cin >> i;
            l = l > i ? l : i;
            r += i;
        }
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (f(v, mid, m) > k)
                l = mid + 1;
            else
                r = mid;
        }
        g(v, l, m - 1, k - 1);
        cout << '\n';
    }
    return 0;
}