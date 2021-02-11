#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, brr[10010];
    cin >> n;
    const string arr[] = {"Pen", "Pineapple", "Apple", "Pineapple pen"};
    for (int i = 0, x = 1; i < 10001; x++)
        for (int k = 0; k < 4 && i < 10001; k++)
            for (int j = 0; j < x && i < 10001; j++)
            {
                i++;
                brr[i] = k;
            }
    cout << arr[brr[n]] << '\n';
    return 0;
}