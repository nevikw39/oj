#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using namespace __gnu_pbds;
struct node
{
    int x, y, s;
};
int main()
{
#ifdef ONLINE_JUDGE
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
#endif
    const pair<int, int> d[] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
    string s;
    while (getline(cin, s))
    {
        bool b[8][8];
        memset(b, 0, sizeof(b));
        int sx = s[0] - 'a', sy = s[1] - '1', ex = s[3] - 'a', ey = s[4] - '1';
        queue<node> q;
        q.push({sx, sy, 0});
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            if (t.x == ex && t.y == ey)
            {
                cout << "To get from " << char(sx + 'a') << sy + 1 << " to " << char(ex + 'a') << ey + 1 << " takes " << t.s << " knight moves.\n";
                break;
            }
            if (b[t.x][t.y])
                continue;
            for (const auto &i : d)
                if (t.x + i.first >= 0 && t.x + i.first < 8 && t.y + i.second >= 0 && t.y + i.second < 8)
                    q.push({t.x + i.first, t.y + i.second, t.s + 1});
            b[t.x][t.y] = true;
        }
    }
    return 0;
}