#include <bits/extc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = less<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pair<long long, long long>>> g(n);
        vector<bool> v(n);
        for (const auto &i : roads)
        {
            g[i[0]].emplace_back(i[1], i[2]);
            g[i[1]].emplace_back(i[0], i[2]);
        }
        vector<long long> d(n, LLONG_MAX), r(n);
        d[0] = 0;
        r[0] = 1;
        std::priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.emplace(0, 0);
        while (pq.size())
        {
            auto f = pq.top();
            pq.pop();
            if (v[f.ND])
                continue;
            v[f.ND] = true;
            for (const auto &i : g[f.ND])
                if (d[i.ST] > d[f.ND] + i.ND)
                {
                    d[i.ST] = d[f.ND] + i.ND;
                    r[i.ST] = r[f.ND] %= 1000000007;
                    pq.emplace(f.ST + i.ND, i.ST);
                }
                else if (d[i.ST] == d[f.ND] + i.ND)
                    r[i.ST] += r[f.ND], r[i.ST] %= 1000000007;
        }
        return r.back();
    }
};

#ifdef nevikw39
int main()
{
    vector<vector<int>> a = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}}, b = {{1, 0, 10}};
    Solution sln;
    cout << sln.countPaths(7, a) << '\n'
         << sln.countPaths(2, b) << '\n';
}
#endif
