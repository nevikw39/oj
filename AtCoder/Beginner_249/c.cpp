/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#include <atcoder/all>
#include <bits/extc++.h>
#ifndef nevikw39
#define nevikw39 cin.tie(nullptr)->sync_with_stdio(false)
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace atcoder;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

int n, k;
vector<string> s, v;

int f(int x = 0)
{
    if (x == n)
    {
        vector<vector<bool>> vv(26, vector<bool>(v.size()));
        for (int i = 0, n = v.size(); i < n; i++)
            for (const char &j : v[i])
                vv[j - 'a'][i] = true;
        return count_if(ALL(vv), [](const auto &x)
                     { return accumulate(ALL(x), 0) == k; });
    }
    int y = f(x + 1);
    v.push_back(s[x]);
    y = max(y, f(x + 1));
    v.pop_back();
    return y;
}

int main()
{
    nevikw39;
    cin >> n >> k;
    s.resize(n);
    for (auto &i : s)
        cin >> i;
    cout << f() << '\n';
    return 0;
}
