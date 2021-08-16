#include <iostream>
#include <iomanip>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    double w, h;
    cin >> w >> h;
    cout << fixed << setprecision(1) << w * 10000 / h / h;
    return 0;
}
