#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using heap = __gnu_pbds::priority_queue<T>;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        heap<pair<int, int>> h;
        while (n--)
        {
            int a, b;
            cin >> a >> b;
            h.push({b, a});
        }
        int r = 0, s = 0;
        while (h.size())
        {
            s += h.top().second;
            r = max(r, s + h.top().first);
            h.pop();
        }
        cout << r << "\n\n";
    }
    return 0;
}