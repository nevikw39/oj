#include <bits/stdc++.h>
#ifndef nevikw39
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    queue<int> q;
    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        switch (k)
        {
        case 1:
            int x;
            cin >> x;
            q.push(x);
            break;
        case 2:
            cout << (q.size() ? q.front() : -1) << '\n';
            break;
        case 3:
            if (q.size())
                q.pop();
        }
    }
    return 0;
}