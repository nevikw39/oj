#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if (n <= 2500)
        cout << "1 " << ceil(n / 25.0) << ' ' << (n % 25 ?: 25) << '\n';
    else if (n <= 7500)
        cout << "2 " << ceil((n - 2500) / 50.0) << ' ' << ((n - 2500) % 50 ?: 50) << '\n';
    else
        cout << "3 " << ceil((n - 7500) / 25.0) << ' ' << ((n - 7500) % 25 ?: 25) << '\n';
    return 0;
}