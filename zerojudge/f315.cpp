#include <bits/extc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int m, *arr;
int inline lowbit(int x)
{
    return x & -x;
}
void update(int x)
{
    while (x <= m)
    {
        arr[x]++;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int r = 0;
    while (x > 0)
    {
        r += arr[x];
        x -= lowbit(x);
    }
    return r;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> l(n + 1, -1), r(n + 1, -1);
    m = n << 1;
    arr = new int[m + 1];
    for (int i = 1; i <= m; i++)
    {
        int tmp;
        cin >> tmp;
        if (l[tmp] == -1)
            l[tmp] = i;
        else
            r[tmp] = i;
    }
    long long x = 0;
    for (int i = 1; i <= n; i++)
    {
        x += sum(r[i]) - sum(l[i]);
        update(l[i]);
        update(r[i]);
    }
    cout << x << '\n';
    return 0;
}