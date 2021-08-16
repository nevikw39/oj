#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m, t;
    cin >> m;
    while (cin >> t && t)
        cout << (t % m ? m - (t % m) : t / m) << '\n';
    return 0;
}