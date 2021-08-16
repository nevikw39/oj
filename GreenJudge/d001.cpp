#include <iostream>
#include <iomanip>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    // cin.tie(0);
    // cout.tie(0);
    // ios::sync_with_stdio(0);
    int r = 0;
    for (int i = 1; i < 99; i++)
        for (int j = 1; j < 987; j++)
        {
            int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
            arr[i % 10]++;
            arr[i / 10]++;
            int c = j / 100, d = j / 10 % 10, e = j % 10, n;
            if (arr[c] || arr[d] || arr[e])
                continue;
            arr[c]++;
            arr[d]++;
            arr[e]++;
            n = i * j;
            if (n < 10000)
                continue;
            arr[n / 10000]++;
            arr[n / 1000 % 10]++;
            arr[n / 100 % 10]++;
            arr[n / 10 % 10]++;
            arr[n % 10]++;
            bool flag = true;
            for (int k = 0; k < 10; k++)
                if (arr[k] > 1)
                    flag = false;
            if (!flag)
                continue;
            cout << setw(2) << setfill('0') << i << " X " << setw(3) << setfill('0') << j << " = " << setw(5) << setfill('0') << n << '\n';
            r++;
        }
    cout << "共" << r << "種運算式";
    return 0;
}