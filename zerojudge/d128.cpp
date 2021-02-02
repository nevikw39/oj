#include <bits/stdc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x, y, z;
    while (cin >> x >> y >> z)
    {
        int arr[8];
        arr[0] = x + 10 * y + z;
        arr[1] = 10 * x + y + z;
        arr[2] = x * (10 * y + z);
        arr[3] = (10 * x + y) * z;
        arr[4] = x + y + z;
        arr[5] = x + y * z;
        arr[6] = x * y + z;
        arr[7] = x * y * z;
        cout << *max_element(arr + 0, arr + 8) << '\n';
    }
    return 0;
}