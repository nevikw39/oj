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

int main()
{
    nevikw39;
    int h, w, cnt = 0;
    cin >> h >> w;
    vector<string> s(h);
    std::copy_n(istream_iterator<string>(cin), h, s.begin());
    for (int h1 : views::iota(0, h))
        for (int h2 : views::iota(h1, h))
            for (int w1 : views::iota(0, w))
                for (int w2 : views::iota(w1, w))
                {
                    bool flag = true;
                    for (int i : views::iota(h1, h2 + 1))
                    {
                        for (int j : views::iota(w1, w2 + 1))
                            if (s[i][j] != s[h1 + h2 - i][w1 + w2 - j])
                            {
                                flag = false;
                                break;
                            }
                        if (!flag)
                            break;
                    }
                    if (flag)
                        ++cnt;
                }
    print("{}", cnt);
    return 0;
}
