#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
using ul = unsigned long long;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    __gnu_pbds::priority_queue<ul, greater<ul>> pq;
    pq.push(1);
    set<ul> s;
    s.insert(1);
    constexpr ul arr[] = {2, 3, 5};
    ul x;
    for (ul i = 0; i < 1500; i++)
    {
        x = pq.top();
        pq.pop();
        for (const ul &j : arr)
        {
            ul xp = x * j;
            if (!s.count(xp))
            {
                s.insert(xp);
                pq.push(xp);
            }
        }
    }
    cout << "The 1500'th ugly number is " << x << ".\n";
    return 0;
}