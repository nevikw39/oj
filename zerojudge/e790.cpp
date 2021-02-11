#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long;
ull i, l = 0;
void f(ull x, char a, char b, char c)
{
    if (!x)
        return;
    f(x - 1, a, c, b);
    if (++l == i)
    {
        cout << "move " << x << " from " << a << " to " << c << '\n';
        exit(0);
    }
    f(x - 1, b, a, c);
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull n;
    cin >> n >> i;
    f(n, '1', '2', '3');
    return 0;
}