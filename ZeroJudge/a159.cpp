#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cin.ignore(1, '\n');
    while (n--)
    {
        int sum = 0, a = 0;
        string s;
        getline(cin, s);
        s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        for (int i = 0; i < 16; i++)
        {
            short c = s[i] - '0';
            if (i % 2)
                sum += c;
            else
                sum += 2 * c - (c < 5 ? 0 : 9);
        }
        cout << (sum % 10 ? "Inv" : "V") << "alid\n";
    }
    return 0;
}
