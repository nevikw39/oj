#include <cmath>
#include <iostream>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
using pii = pair<int, int>;
inline int cross(const pii &a, const pii &b)
{
    return a.first * b.second - a.second * b.first;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> v(n);
    for (auto &i : v)
    {
        int x, y;
        cin >> x >> y;
        i = {x, y};
    }
    v.push_back(v.front());
    // double a = 0;
    // for (int i = 0; i < n; i++)
    //     a += cross(v[i], v[i + 1]);
    // a = abs(a) / 2;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        int c = cross(v[i], v[i + 1]);
        x += c * (v[i].first + v[i + 1].first);
        y += c * (v[i].second + v[i + 1].second);
    }
    // x /= a * 6;
    // y /= a * 6;
    cout << double(y) / double(x);
    return 0;
}
