#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define endl '\n'
#pragma GCC optimize("O3")
using namespace std;
int d;
int C(int n, int k)
{
    static map<pair<int, int>, int> m;
    if (2 * k > n)
        k = n - k;
    if (m.count({n, k}))
        return m[{n, k}];
    if (!k)
        return m[{n, k}] = 1;
    return m[{n, k}] = (C(n - 1, k - 1) + C(n - 1, k)) % d;
}
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int l, r = 0;
    string s;
    cin >> d >> s;
    l = s.length();
    map<char, int> m;
    vector<int> letters;
    for (int i = 'A'; i <= 'Z'; i++)
        letters.push_back(i);
    for (int i = 'a'; i <= 'z'; i++)
        letters.push_back(i);
    for (char c : s)
        m[c]++;
    for (int i = 0; i < l; i++)
    {
        for (char j : letters)
        {
            if (s[i] <= j)
                break;
            if (m[j])
            {
                m[j]--;
                int n = l - 1 - i, q = 1;
                for (char k : letters)
                    if (m[k])
                    {
                        q *= C(n, m[k]);
                        q %= d;
                        n -= m[k];
                    }
                r += q;
                r %= d;
                m[j]++;
            }
        }
        m[s[i]]--;
    }
    cout << r;
    return 0;
}