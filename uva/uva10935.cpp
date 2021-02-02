#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n)
    {
        queue<int> q;
        for (int i = 0; i < n;)
            q.push(++i);
        cout << "Discarded cards:";
        if (n != 1)
            cout.put(' ');
        while (q.size() > 1)
        {
            cout << q.front();
            q.pop();
            int t = q.front();
            q.pop();
            q.push(t);
            if (q.size() != 1)
                cout << ", ";
        }
        cout << "\nRemaining card: " << q.front() << '\n';
    }
    return 0;
}