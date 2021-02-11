#include <iostream>
#include <algorithm>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int b, d, m = 0, p = 1, x = 0;
    string n;
    cin >> b >> n;
    d = n.length();
    reverse(n.begin(), n.end());
    for (int i = 0; i < d; i++, p *= b)
        m += p * (n[i] - '0');
    for (int i = 0; i < d; i++)
    {
        int t = 1;
        for (int j = 0; j < d; j++)
            t *= n[i] - '0';
        x += t;
    }
    cout << (x == m ? "YES" : "NO");
    return 0;
}
