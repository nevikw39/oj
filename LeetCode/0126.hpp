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
using _hash = gp_hash_table<K, M, F>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

class Solution
{
private:
    int l;
    bool cmp(const string &x, const string &y)
    {
        int cnt = 0;
        for (int i = 0; i < l; i++)
            if (x[i] != y[i] && ++cnt > 1)
                return false;
        return cnt == 1;
    }
    vector<vector<string>> y;
    deque<int> dq;
    void backtrack(int i, const vector<vector<int>> &p, const vector<string> &wordList)
    {
        if (!~i)
        {
            int n = dq.size();
            y.emplace_back(n);
            for (int i = 1; i < n; i++)
                y.back()[i] = wordList[dq[i]];
            return;
        }
        for (int j : p[i])
        {
            dq.push_front(j);
            backtrack(j, p, wordList);
            dq.pop_front();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        l = beginWord.length();
        int n = wordList.size(), e = -1;
        vector<vector<int>> g(n);
        vector<int> d(n, INT_MAX);
        vector<vector<int>> p(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                if (cmp(wordList[i], wordList[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            if (cmp(beginWord, wordList[i]))
            {
                d[i] = 2;
                p[i].push_back(-1);
                q.push(i);
            }
            if (endWord == wordList[i])
                e = i;
        }
        y.clear();
        if (!~e)
            return y;
        while (q.size())
        {
            int f = q.front();
            q.pop();
            if (f == e)
                continue;
            for (const int &i : g[f])
                if (d[i] > d[f] + 1)
                {
                    d[i] = d[f] + 1;
                    p[i].clear();
                    p[i].push_back(f);
                    q.push(i);
                }
                else if (d[i] == d[f] + 1)
                    p[i].push_back(f);
        }
        dq.push_front(e);
        backtrack(e, p, wordList);
        for (auto &i : y)
            i.front() = beginWord;
        return y;
    }
};
