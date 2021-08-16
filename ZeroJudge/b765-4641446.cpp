#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <map>
using namespace std;
int main()
{
    const array<short, 26> a = {1, 10, 19, 28, 37, 46, 55, 64, 39, 73, 82, 2, 11, 20, 48, 29, 38, 47, 56, 65, 74, 83, 21, 3, 12, 30};
    short n;
    cin >> n;
    map<short, string> m;

    while (n--)
    {
        short t, sum, p;
        string s;
        cin >> t >> s;

        if (s[0] == '*')
        {
            s.erase(s.begin());
            sum = s[8] - '0';

            for (char & c : s)
                sum += (c - '0') * (&s.back() - &c);

            for (const short & i : a)
                if ((sum + i) % 10 == 0)
                {
                    char c = (&i - a.begin() + 'A');
                    string str = ".";
                    str[0] = c;
                    m[t] += str + s + " ";
                }

            continue;
        }

        sum = a[s[0] - 'A'] + s[9] - '0';
        char tmp = s[0];
        s.erase(s.begin());

        for (char & c : s)
            sum += c == '*' ? 0 : (c - '0') * (&s.back() - &c);

        s.insert(s.begin(), tmp);
        p = s.find('*');

        for (char i = 0; i < 10; i++)
            if (!((sum + i * (p == 9 ? 1 : 9 - p)) % 10))
            {
                string str = s;
                str[p] = i + '0' + (p == 9) * 4;
                m[t] += str + " ";
            }
    }

    for (auto i : m)
        cout << setw(3) << setfill('0') << i.first << ' ' << i.second << endl;

    return 0;
}
