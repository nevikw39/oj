#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, a, b;
    while (cin >> s)
    {
        int l = s.length();
        a = s.substr(0, l / 2);
        b = (l % 2) ? s.substr(l / 2 + 1, l / 2) : s.substr(l / 2, l / 2);
        reverse(b.begin(), b.end());
        cout << ((a == b) ? "yes" : "no") << endl;
    }
    return 0;
}
