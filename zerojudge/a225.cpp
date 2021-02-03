#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> s(n);
        for (auto &i : s)
        {
            cin >> i;
            reverse(i.begin(), i.end());
        }
        sort(s.begin(), s.end(), [](string a, string b) {
            string _a(a), _b(b);
            reverse(_a.begin(), _a.end());
            reverse(_b.begin(), _b.end());
            return (a[0] != b[0] ? a[0] < b[0] : stol(_a) > stol(_b));
        });
        for (auto &i : s)
        {
            reverse(i.begin(), i.end());
            cout << i << (&i != &s.back() ? " " : "");
        }
        cout << endl;
    }
    return 0;
}
