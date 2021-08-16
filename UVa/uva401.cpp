#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif
using namespace std;
int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    const string y[] = {"not a palindrome", "a regular palindrome", "a mirrored string", "a mirrored palindrome"};
    auto r = [](char x) {if (isupper(x)) return "A   3  HIL JM O   2TUVWXY51SE Z  8 "[x - 'A']; return  "A   3  HIL JM O   2TUVWXY51SE Z  8 "[x - '0' + 25]; };
    while (cin >> s)
    {
        int l = s.length();
        bool p = true, m = true;
        for (int i = 0; i << 1 < l + 1; i++)
        {
            if (s[i] != s[l - 1 - i])
                p = false;
            if (r(s[i]) != s[l - 1 - i])
                m = false;
        }
        cout << s << " -- is " << y[p + m * 2] << ".\n\n";
    }
    return 0;
}