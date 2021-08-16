#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int64_t X, Y, L, r, n, k = 0;
    cin >> X >> Y >> L >> r >> n;
    r *= r;
    while (n--)
    {
        int64_t x, y, l;
        cin >> x >> y >> l;
        k += l <= L && (x - X) * (x - X) + (y - Y) * (y - Y) <= r;
    }
    cout << k << '\n';
    return 0;
}