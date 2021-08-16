#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const string s[] = {"morning", "afternoon", "night", "early morning"};
    double arr[4] = {0}, brr[7] = {0};
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 4; j++)
        {
            double tmp;
            cin >> tmp;
            arr[j] += tmp;
            brr[i] += tmp;
        }
    cout << max_element(brr, brr + 7) - brr + 1 << '\n'
         << s[max_element(arr, arr + 4) - arr];
    return 0;
}