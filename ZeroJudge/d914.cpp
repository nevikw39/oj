#include <iostream>
#include <map>
#include <set>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, d = 0;
    cin >> n;
    map<pair<int, int>, int> a, b;
    while (n--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        a[{x, y}] = c;
    }
    cin >> n;
    while (n--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        b[{x, y}] = c;
    }
    for (auto i : a)
    {
        if (b.count(i.first))
        {
            d += (b[i.first] != i.second) * 2;
            b.erase(i.first);
        }
        else
            d++;
    }
    for (auto i : b)
    {
        if (a.count(i.first))
            d += a[i.first] == i.second;
        else
            d++;
    }
    cout << d;
    return 0;
}
