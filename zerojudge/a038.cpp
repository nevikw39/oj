#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        reverse(s.begin(), s.end());
        while (s[0] == '0')
            s = s.substr(1, s.length() - 1);
        cout << ((s == "") ? "0" : s) << endl;
    }
    return 0;
}
