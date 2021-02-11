#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
bool f(int &w)
{
    int w1, d1, w2, d2;
    cin >> w1 >> d1 >> w2 >> d2;
    bool b1 = true, b2 = true;
    if (!w1)
        b1 = f(w1);
    if (!w2)
        b2 = f(w2);
    w = w1 + w2;
    return b1 && b2 && w1 * d1 == w2 * d2;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int t, w;
    cin >> t;
    while (t--)
        cout << (f(w) ? "YES\n" : "NO\n") << (t ? "\n" : "");
    return 0;
}
