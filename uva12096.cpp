#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        vector<set<int>> v;
        map<set<int>, int> m;
        auto f = [&](const set<int> &x) { if (m.count(x)) return m[x]; v.push_back(x); return m[x] = v.size() - 1; };
        stack<int> st;
        int n;
        cin >> n;
        while (n--)
        {
            string str;
            cin >> str;
            switch (str[0])
            {
            case 'P':
                st.push(f(set<int>()));
                break;
            case 'D':
                st.push(st.top());
                break;
            default:
                set<int> x1 = v[st.top()];
                st.pop();
                set<int> x2 = v[st.top()];
                st.pop();
                set<int> x;
                switch (str[0])
                {
                case 'U':
                    set_union(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                    break;
                case 'I':
                    set_intersection(x1.begin(), x1.end(), x2.begin(), x2.end(), inserter(x, x.begin()));
                    break;
                case 'A':
                    x = x2;
                    x.insert(f(x1));
                }
                st.push(f(x));
            }
            cout << v[st.top()].size() << '\n';
        }
        cout << "***\n";
    }
    return 0;
}