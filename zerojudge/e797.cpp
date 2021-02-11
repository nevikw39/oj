#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> t >> n;
    bool _and[n], _or[n], _xor[n];
    memset(_and, 1, sizeof(_and));
    memset(_or, 0, sizeof(_or));
    memset(_xor, 0, sizeof(_xor));
    while (t--)
        for (int i = 0; i < n; i++)
        {
            bool b;
            cin >> b;
            if (!b)
                _and[i] = false;
            if (b)
                _or[i] = true;
            _xor[i] ^= b;
        }
    cout << "AND:";
    for (int i = 0; i < n; i++)
        cout << ' ' << _and[i];
    cout << "\n OR:";
    for (int i = 0; i < n; i++)
        cout << ' ' << _or[i];
    cout << "\nXOR:";
    for (int i = 0; i < n; i++)
        cout << ' ' << _xor[i];
    return 0;
}