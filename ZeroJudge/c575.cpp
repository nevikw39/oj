#include <iostream>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
vector<int> v;
int n, k;
bool f(int x)
{
    int cnt = 0;
    for (int i = 0; i < n;)
    {
        int t = v[i] + x;
        cnt++;
        if (cnt > k)
            return false;
        do
            i++;
        while (v[i] <= t && i < n);
    }
    return true;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    v.resize(n);
    for (int &i : v)
        cin >> i;
    sort(v.begin(), v.end());
    int l = 1, r = (v.back() - v.front()) / k + 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (f(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l;
    return 0;
}
