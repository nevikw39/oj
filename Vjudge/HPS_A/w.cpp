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
    int n;
    while (cin >> n && n)
    {
        for (;;)
        {
            bool flag = true;
            int a = 1, b = 1;
            stack<int> s;
            vector<int> v(n + 1);
            cin >> v[1];
            if (!v[1])
                break;
            for (int i = 2; i <= n; i++)
                cin >> v[i];
            while (b <= n)
            {
                if (a == v[b])
                {
                    a++;
                    b++;
                }
                else if (s.size() && s.top() == v[b])
                {
                    s.pop();
                    b++;
                }
                else if (a <= n)
                    s.push(a++);
                else
                {
                    flag = false;
                    break;
                }
            }
            cout << (flag ? "Yes\n" : "No\n");
        }
        cout << '\n';
    }
    return 0;
}