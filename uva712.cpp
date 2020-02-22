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
    int n, k = 0;
    while (cin >> n && n)
    {
        cout << "S-Tree #" << ++k << ":\n";
        int m;
        string s;
        vector<int> v(n);
        for (int &i : v)
        {
            cin >> s;
            i = stoi(s.substr(1, string::npos));
        }
        cin >> s >> m;
        while (m--)
        {
            string t;
            cin >> t;
            int p = 1;
            for (int i = 0; i < n; i++)
                if (t[v[i] - 1] == '0')
                    p <<= 1;
                else
                    p = p << 1 | 1;
            cout.put(s[p - (1 << n)]);
        }
        cout << "\n\n";
    }
    return 0;
}