#include <bits/stdc++.h>
using namespace std;
using ul = unsigned long;
struct M
{
    ul a = 0, b = 0, c = 0, d = 0;
    M operator*(const M &r)
    {
        M t;
        t.a = (a * r.a + b * r.c);
        t.b = (a * r.b + b * r.d);
        t.c = (c * r.a + d * r.c);
        t.d = (c * r.b + d * r.d);
        return t;
    }
};
pair<ul, ul> mul(const pair<ul, ul> v, const M m)
{
    pair<ul, ul> c;
    c.first = (v.first * m.a + v.second * m.c);
    c.second = (v.first * m.b + v.second * m.d);
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ul n;
    cin >> n;
    auto v = mul({0, 1}, binexp({0, 1, 1, 1}, n));
    cout << v.first << ':' << v.second << '\n';
    return 0;
}