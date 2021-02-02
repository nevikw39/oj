#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
int n, in[26], out[26], p[26], r[26];
void inline init()
{
    for (int i = 0; i < 26; i++)
        p[i] = i, r[i] = 1;
}
int find(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = find(p[x]);
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    if (r[x] > r[y])
        p[y] = x;
    else
    {
        r[y] += r[x] == r[y];
        p[x] = y;
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        cin >> n;
        init();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            ++in[s.front() - 'a'];
            ++out[s.back() - 'a'];
            unite(s.front() - 'a', s.back() - 'a');
        }
        bool flag = true;
        int cnt = 0, a = 0, b = 0;
        for (int i = 0; i < 26; i++)
            cnt += (in[i] || out[i]) && i == p[i];
        if (cnt != 1)
            flag = false;
        for (int i = 0; i < 26 && flag; i++)
            if (in[i] != out[i])
            {
                if (in[i] - out[i] == 1)
                    a++;
                else if (out[i] - in[i] == 1)
                    b++;
                else
                    flag = false;
            }
        if (a && b && a + b > 2)
            flag = false;
        cout << (flag ? "Ordering is possible.\n" : "The door cannot be opened.\n");
    }
    return 0;
}