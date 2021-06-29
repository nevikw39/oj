#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
deque<int> d;
long long f(int n)
{
    int x = d.front();
    d.pop_front();
    switch (x)
    {
    case 2:
        array<int, 4> arr;
        for (int &i : arr)
            i = f(n >> 1);
        return accumulate(arr.begin(), arr.end(), 0);
    case 1:
        return n * n;
    default:
        return 0;
    }
}
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    int n;
    cin >> s >> n;
    for (const char &c : s)
        d.push_back(c - '0');
    cout << f(n) << '\n';
    return 0;
}