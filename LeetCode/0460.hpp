/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
#ifndef nevikw39
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
struct
{
    template <typename T>
    auto &operator<<(const T &x) { return *this; }
} __cerr;
#define cerr __cerr
#define __builtin_sprintf sprintf
#else
#pragma message("hello, nevikw39")
#endif
#pragma message("GL; HF!")
#include <bits/extc++.h>
#define ALL(X) begin(X), end(X)
#define ST first
#define ND second
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type, typename F = typename detail::default_hash_fn<K>::type>
using _hash = cc_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class LFUCache
{
private:
    unordered_map<int, tuple<int, int, list<int>::iterator>> cache;
    unordered_map<int, list<int>> freq_lst;
    const int c;
    int mn = -1;

    void increase(int k)
    {
        auto &[v, f, itr] = cache[k];
        freq_lst[f].erase(itr);
        if (mn == f && freq_lst[f].empty())
            ++mn;
        if (freq_lst[f].empty())
            freq_lst.erase(f);
        ++f;
        itr = freq_lst[f].emplace(freq_lst[f].end(), k);
    }

public:
    LFUCache(int capacity) : c(capacity) {}

    int get(int key)
    {
        auto itr = cache.find(key);
        if (itr == cache.end())
            return -1;
        increase(key);
        return std::get<0>(itr->ND);
    }

    void put(int key, int value)
    {
        if (!c)
            return;
        auto itr = cache.find(key);
        if (itr != cache.end())
        {
            increase(key);
            std::get<0>(itr->ND) = value;
            return;
        }
        if (cache.size() == c)
        {
            cache.erase(freq_lst[mn].front());
            freq_lst[mn].pop_front();
            if (freq_lst[mn].empty())
                freq_lst.erase(mn);
        }
        mn = 1;
        cache[key] = {value, 1, freq_lst[1].emplace(freq_lst[1].end(), key)};
    }
};
