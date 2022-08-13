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
    int r, c;
    bitset<15> bs[15];
    bs[0] = bs[14] = bitset<15>("111111111111111");
    bs[1] = bs[13] = bitset<15>("100000000000001");
    bs[2] = bs[12] = bitset<15>("101111111111101");
    bs[3] = bs[11] = bitset<15>("101000000000101");
    bs[4] = bs[10] = bitset<15>("101011111110101");
    bs[5] = bs[9] = bitset<15>("101010000010101");
    bs[6] = bs[8] = bitset<15>("101010111010101");
    bs[7] = bitset<15>("101010101010101");
    cin >> r >> c;
    cout << (bs[r - 1][c - 1] ? "black\n" : "white\n");
    return 0;
}
