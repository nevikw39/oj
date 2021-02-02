#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
void f(vector<int> &v, int x)
{
    for (int i = 0; i <= x >> 1; i++)
        swap(v[i], v[x - i]);
    cout << v.size() - x;
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    while (getline(cin, s))
    {
        cout << s << '\n';
        stringstream ss(s);
        vector<int> v;
        int tmp;
        while (ss >> tmp)
            v.push_back(tmp);
        int n = v.size();
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            int m = 0;
            for (int j = 1; j < n - i; j++)
                if (v[j] > v[m])
                    m = j;
            if (m == n - i - 1)
                continue;
            if (flag)
                cout << ' ';
            if (m)
            {
                f(v, m);
                cout << ' ';
            }
            f(v, n - i - 1);
            flag = true;
        }
        if (flag)
            cout << ' ';
        cout << "0\n";
    }
    return 0;
}