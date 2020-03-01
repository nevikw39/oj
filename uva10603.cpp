#include <bits/extc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif
using namespace std;
using namespace __gnu_pbds;
struct node
{ 
    array<int, 3> arr;
    int s;
    bool operator<(const node &r) const
    {
        return s > r.s;
    }
};
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        array<int, 3> arr;
        cin >> arr[0] >> arr[1] >> arr[2] >> d;
        gp_hash_table<int, int> r;
        tree<pair<int, int>, null_type> s;
        s.insert({0, 0});
        __gnu_pbds::priority_queue<node> q;
        q.push({{0, 0, arr[2]}, 0});
        while (q.size())
        {
            auto t = move(q.top());
            q.pop();
            for (const int &i : t.arr)
                if (r.find(i) == r.end() || r[i] > t.s)
                    r[i] = t.s;
            if (r.find(d) != r.end())
                break;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (i != j && t.arr[i] && t.arr[j] != arr[j])
                    {
                        int x = min(t.arr[i] + t.arr[j], arr[j]) - t.arr[j];
                        auto n = t;
                        n.s += x;
                        n.arr[i] -= x;
                        n.arr[j] += x;
                        if (s.find({n.arr[0], n.arr[1]}) == s.end())
                        {
                            s.insert({n.arr[0], n.arr[1]});
                            q.push(move(n));
                        }
                    }
        }
        while (r.find(d) == r.end())
            d--;
        cout << r[d] << ' ' << d << '\n';
    }
    return 0;
}