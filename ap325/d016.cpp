#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int m, n, u;
    cin >> m >> n;
    u = (1 << m) - 1;
    set<int> st;
    while (n--)
    {
        string str;
        cin >> str;
        int x = 0;
        for (int i = 0, l = str.length(); i < l; i++)
            x |= 1 << (str[i] - 'A');
        st.insert(x);
    }
    int r = 0;
    for (const int &i : st)
        r += st.find(u ^ i) != st.end();
    cout << (r >> 1) << '\n';
    return 0;
}