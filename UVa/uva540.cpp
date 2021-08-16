#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t, k = 0;
    while (cin >> t && t)
    {
        cout << "Scenario #" << ++k << '\n';
        map<int, int> m;
        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            while (n--)
            {
                int tmp;
                cin >> tmp;
                m[tmp] = i;
            }
        }
        queue<int> q, qq[t];
        for (;;)
        {
            int n, x;
            string s;
            cin >> s;
            switch (s[0])
            {
            case 'S':
                goto label;
            case 'D':
                n = q.front();
                cout << qq[n].front() << '\n';
                qq[n].pop();
                if (qq[n].empty())
                    q.pop();
                break;
            case 'E':
                cin >> x;
                n = m[x];
                if (qq[n].empty())
                    q.push(n);
                qq[n].push(x);
            }
        }
    label:
        cout << '\n';
    }
    return 0;
}