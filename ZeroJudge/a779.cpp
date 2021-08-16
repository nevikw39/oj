#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;

    while (getline(cin, s))
    {
        int n = 0, l;
        bool b = true;
        string out = s;
        vector<int> v(26);
        s.erase(remove_if(s.begin(), s.end(), [](auto const &c) -> bool { return !isalnum(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        l = s.length();

        if (l)
            for (int i = 0; i < l; i++)
                b &= (s[i] == s[l - i - 1]);
        else
            b = false;

        cout << out << endl
             << (b ? "-- is a palindrome" : "-- is not a palindrome") << endl;
    }

    return 0;
}
