#include <bits/extc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    stack<int> s, t;
    long long r = 0;
    while (n--)
    {
        int h;
        cin >> h;
        while (s.size() && s.top() < h)
        {
            r += t.top();
            t.pop();
            s.pop();
        }
        if (s.size() && s.top() == h)
            r += t.top()++;
        else
        {
            s.push(h);
            t.push(1);
        }
        r += s.size() > 1;
    }
    cout << (r << 1) << '\n';
    return 0;
}