#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        string a, b, out;
        cin >> a >> b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < a.length(); i++)
        {
            int n = a[i] + b[i] - 'A';
            if (n > 'Z')
            {
                n -= 26;
                out.push_back(n);
                if (i + 1 != a.length())
                    a[i + 1]++;
                else
                    out.push_back('B');
            }
            else
                out.push_back(n);
        }
        reverse(out.begin(), out.end());
        cout << out << endl;
    }
    return 0;
}
