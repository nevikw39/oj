#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ull dp[51][51];
    for (int i = 0; i <= 50; i++)
        dp[i][0] = dp[0][i] = 1;
    for (int i = 1; i <= 50; i++)
        for (int j = 1; j <= 50; j++)
            dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
    int n;
    cin >> n;
    while (n--)
    {
        int d, c;
        cin >> d >> c;
        cout << dp[d][c] << '\n';
    }
    return 0;
}