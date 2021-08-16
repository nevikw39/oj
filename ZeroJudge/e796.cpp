#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b, p, mn = INT_MAX, mni = 0, mx = -1, mxi = 0;
    cin >> b >> p;
    int arr[b + 1];
    memset(arr, 0, sizeof(arr));
    while (p--)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        for (int i = x; i <= y; i++)
            arr[i]++;
    }
    for (int i = 1; i <= b; i++)
        if (mn > arr[i])
        {
            mn = arr[i];
            mni = i;
        }
        else if (mx <= arr[i])
        {
            mx = arr[i];
            mxi = i;
        }
    cout << mni << ' ' << mxi << '\n';
    return 0;
}