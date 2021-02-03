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

    while (cin >> s)
    {
        int n = 0;
        vector<int> v(26);
        s.erase(remove_if(s.begin(), s.end(), [](auto const &c) -> bool { return !isalpha(c); }), s.end());
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (char const &c : s)
            v[c - 'a']++;

        for (int i : v)
            if (i % 2)
                n++;

        cout << (n < 2 ? "yes !" : "no...") << endl;
    }

    return 0;
}
