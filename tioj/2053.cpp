#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long long;
struct M
{
    ul a = 0, b = 0, c = 0, d = 0;
    M operator*(const M &r)
    {
        M t;
        t.a = (a * r.a + b * r.c) % 1000000007;
        t.b = (a * r.b + b * r.d) % 1000000007;
        t.c = (c * r.a + d * r.c) % 1000000007;
        t.d = (c * r.b + d * r.d) % 1000000007;
        return t;
    }
};
pair<ul, ul> mul(const pair<ul, ul> v, const M m)
{
    pair<ul, ul> c;
    c.first = (v.first * m.a + v.second * m.c) % 1000000007;
    c.second = (v.first * m.b + v.second * m.d) % 1000000007;
    return c;
}
M binexp(M a, ul n)
{
    M y{1, 0, 0, 1};
    while (n > 0)
    {
        if (n & 1)
            y = y * a;
        a = a * a;
        n >>= 1;
    }
    return y;
}
int main()
{
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // ios::sync_with_stdio(false);
    ul x, y, a, b, n;
    cin >> x >> y >> a >> b >> n;
    cout << mul({x, y}, binexp({a, 1, b, 0}, n - 1)).first << '\n';
    return 0;
}