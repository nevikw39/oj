#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n, m;
    char c;
    cin >> n >> m >> c;
    while (n--)
    {
        unsigned long long s;
        cin >> s;
        for (unsigned long long i = 1 << (m - 1); i; i >>= 1)
            cout.put(s & i ? c : '.'), cout.put(' ');
        cout.put('\n');
    }
    return 0;
}