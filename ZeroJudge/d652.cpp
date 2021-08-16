#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
template <typename T>
using heap = __gnu_pbds::priority_queue<T>;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int &i : v)
        cin >> i;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != n)
            dp[i][i] = dp[i][i + 1] = 0;
        for (int j = 0; j + i < n; j++)
            for (int k = j; k <= j + i; k++)
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i] + v[j] * v[k] * v[j + i]);
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}