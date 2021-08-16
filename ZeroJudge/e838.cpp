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
    vector<string> v(n), w;
    for (auto &i : v)
        cin >> i;
    w = v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (v[i][j] == '*')
                for (int k = 0; k < n; k++)
                    w[i][k] = w[k][j] = '*';
    for (const auto &i : w)
        cout << i << '\n';
    return 0;
}