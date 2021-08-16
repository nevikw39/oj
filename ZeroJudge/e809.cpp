#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    string s;
    cin >> s;
    gp_hash_table<char, int> ht;
    for (int i = 0; i < s.length(); i++)
        ht[s[i]] = i;
    cin >> s >> q;
    sort(s.begin(), s.end(), [&](char l, char r) { return ht[l] < ht[r]; });
    while (q--)
    {
        int x;
        cin >> x;
        cout << s[x - 1] << '\n';
    }
    return 0;
}
