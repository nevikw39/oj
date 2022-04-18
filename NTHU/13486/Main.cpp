/**                  _ _              _____ ___
 *  _ __   _____   _(_) | ____      _|___ // _ \
 * | '_ \ / _ \ \ / / | |/ /\ \ /\ / / |_ \ (_) |
 * | | | |  __/\ V /| |   <  \ V  V / ___) \__, |
 * |_| |_|\___| \_/ |_|_|\_\  \_/\_/ |____/  /_/
 **/
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T, typename Cmp = greater<T>, typename Tag = pairing_heap_tag>
using _heap = __gnu_pbds::priority_queue<T, Cmp, Tag>;
template <typename K, typename M = null_type>
using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename Cmp = less<K>, typename T = rb_tree_tag>
using _tree = tree<K, M, Cmp, T, tree_order_statistics_node_update>;

#include "function.h"
#ifdef priority_queue
#undef priority_queue
#endif

_heap<pair<unsigned, string>> pq;
_hash<string, decltype(pq)::point_iterator> ht;
unsigned mx = 0;

template <>
Manager<Node>::Manager() : endTime(UINT_MAX) {}

template <>
void Manager<Node>::cmd_set_endTime(unsigned end)
{
    if (pq.empty() || mx <= end)
    {
        endTime = end;
        cout << "SET_ENDTIME SUCCESS\n";
    }
    else
        cout << "SET_ENDTIME FAIL\n";
}

template <>
void Manager<Node>::cmd_add_task(string s, unsigned cost)
{
    if (pq.empty() || pq.top().ST + cost > endTime)
    {
        cout << "ADD_TASK " << s << ": FAIL\n";
        return;
    }
    auto itr = ht[pq.top().ND];
    pq.modify(itr, {itr->ST + cost, itr->ND});
    cout << "ADD_TASK " << s << ": " << itr->ND << " AT " << itr->ST << '\n';
    mx = max(mx, itr->ST);
}

template <>
void Manager<Node>::cmd_add_ta(string s, unsigned begin)
{
    if (begin < endTime)
    {
        ht[s] = pq.push({begin, s});
        cout << "ADD_TA SUCCESS\n";
        mx = max(mx, begin);
    }
    else
        cout << "ADD_TA FAIL\n";
}

template <>
void Manager<Node>::cmd_check_schedule(unsigned cost, unsigned dead)
{
    if (pq.empty())
        cout << "CHECK_SCHEDULE: NO TA WARNING\n";
    else if (pq.top().ST + cost > min(dead, endTime))
        cout << "CHECK_SCHEDULE: OVERTIME WARNING!\n";
    else
        cout << "CHECK_SCHEDULE: CAN FINISH!\n";
}

template <>
void Manager<Node>::result()
{
    cout << "NUMBER_TA: " << pq.size() << '\n';
    if (pq.size())
        cout << "EARLIEST FINISH TA: " << pq.top().ND << " AT " << pq.top().ST << '\n';
}

// if his start time is equal to the end time, then he cannot be added. \
   if the task would be completed equal to the end time, then it can be accepted \
   if the new end time is equal to the latest task, then the end time can be updated.
