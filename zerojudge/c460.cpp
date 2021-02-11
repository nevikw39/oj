#include <iostream>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    unsigned long n, arr[3][8]; // 每種技能有或沒有共八種組合
    memset(arr, 0, sizeof(arr));
    cin >> n;
    while (n--)
    {
        int t, a, r, d;
        cin >> t >> a >> r >> d;
        arr[t - 1][a + 2 * r + 4 * d]++; // 第一個位元紀錄對空...
    }
    n = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            for (int k = 0; k < 8; k++)
                n += ((i | j | k) == 7) * arr[0][i] * arr[1][j] * arr[2][k];
    cout << n;
    return 0;
}
