#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, mn = 1000, mx = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        mn = mn < tmp ? mn : tmp;
        mx = mx > tmp ? mx : tmp;
    }
    cout << mn << ' ' << mx << (mx - mn == n - 1 ? "yes" : "no");
    return 0;
}
