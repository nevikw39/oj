#include <iostream>
#pragma GCC Optimize("Ofast")
using namespace std;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int l = s.length();
        if (l & 1)
            s.push_back('X'), l++;
        for (int i = 0; i + 1 < l; i += 2)
            cout.put((s[i] - 'A' + 3 * (s[i + 1] - 'A')) % 26 + 'A'), cout.put(2 * (s[i + 1] - 'A') % 26 + 'A');
        cout << '\n';
    }
    return 0;
}