#include <iostream>
#include <cstring>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    int arr[5][5], brr[5][5];
    char _;
    for (int i = 0; i < 5; i++)
        cin >> arr[i][0] >> _ >> arr[i][1] >> _ >> arr[i][2] >> _ >> arr[i][3] >> _ >> arr[i][4];
    for (int a = 2; a <= 5; a++)
    {
        int r = 0;
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
            {
                int n = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= 5 || y < 0 || y >= 5)
                        continue;
                    n += arr[x][y];
                }
                brr[i][j] = arr[i][j] ? n == 2 || n == 3 : n == 3;
                r += brr[i][j];
            }
        cout << "第" << a << "代: " << r << "個細胞存活\n";
        // cerr << " " << a << "  " << r << " \n";
        for (int i = 0; i < 5; i++)
            cout << brr[i][0] << _ << brr[i][1] << _ << brr[i][2] << _ << brr[i][3] << _ << brr[i][4] << '\n';
        memcpy(arr, brr, sizeof(arr));
    }
    return 0;
}