#include <cmath>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int a = 0, b = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2)
                a += s[i] - '0';
            else
                b += s[i] - '0';
        }
        cout << abs(a - b) << endl;
    }
    return 0;
}
