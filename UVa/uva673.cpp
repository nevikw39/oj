#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(1, '\n');
    while (t--)
    {
        string str;
        getline(cin, str);
        stack<char> stk;
        for (const char &c : str)
            switch (c)
            {
            case '(':
            case '[':
                stk.push(c);
                break;
            case ')':
                if (stk.size() && stk.top() == '(')
                    stk.pop();
                else
                    stk.push(c);
                break;
            case ']':
                if (stk.size() && stk.top() == '[')
                    stk.pop();
                else
                    stk.push(c);
                break;
            }
        cout << (stk.empty() ? "Yes\n" : "No\n");
    }
    return 0;
}