#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    uint64_t n, m;
    cin >> n >> m;
    m <<= 3;
    if (m < (n << 1))
        cout << "Not enough\n";
    else if (m > n * 3)
        cout << "Too much\n";
    else
        cout << "Yes\n";
    return 0;
}