#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--)
    {
        int k, p;
        cin >> k;
        if (k & 1)
        {
            cout << "0\n";
            continue;
        }
        p = 1 << (k / 2 - 1);
        cout << p << ' ' << p << ' ' << p << ' ' << p << '\n';
    }
    return 0;
}
