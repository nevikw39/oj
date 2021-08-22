/**                  _ _              _____ ___  
 *  _ __   _____   _(_) | ____      _|___ // _ \ 
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/ 
 **/
#define __builtin_sprintf sprintf
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
    string findDifferentBinaryString(vector<string> &nums)
    {
        _hash<int> hs;
        for (const auto &i : nums)
        hs.insert(stoi(i, 0, 2));
        for (int i = 0, n = nums.size(); i < 1 << n; i++)
        if (hs.find(i) == hs.end())
            return bitset<16>(i).to_string().substr(16 - n, string::npos);
        return "error";
    }
};

#ifdef nevikw39
int main()
{
    vector<string> a = {"01","10"}, b = {"00","01"}, c = {"111","011","001"};
    Solution sln;
    cout << sln.findDifferentBinaryString(a) << '\n'
         << sln.findDifferentBinaryString(b) << '\n'
         << sln.findDifferentBinaryString(c) << '\n';
}
#endif
