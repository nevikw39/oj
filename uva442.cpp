#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    pair<int, int> p[26];
    int n;
    cin >> n;
    while (n--)
    {
        char c;
        cin >> c >> p[c - 'A'].first >> p[c - 'A'].second;
    }
    string str;
    while (cin >> str)
    {
        bool flag = false;
        int r = 0;
        stack<pair<int, int>> stk;
        for (const char &i : str)
        {
            if (isalpha(i))
                stk.push(p[i - 'A']);
            else if (i == ')')
            {
                auto b = stk.top();
                stk.pop();
                auto a = stk.top();
                stk.pop();
                if (a.second != b.first)
                {
                    flag = true;
                    break;
                }
                r += a.first * a.second * b.second;
                stk.push({a.first, b.second});
            }
        }
        if (flag)
            cout << "error\n";
        else
            cout << r << '\n';
    }
    return 0;
}