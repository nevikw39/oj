#include <iostream>
#include <sstream>
#pragma GCC optimize("O3")
using namespace std;
int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    cin.ignore(1, '\n');
    while (m--)
    {
        char c;
        long n, o;
        string s;
        getline(cin, s);
        stringstream ss;
        ss << s;
        ss >> n;
        while (ss >> c >> o)
        {
            switch (c)
            {
            case '+':
                n += o;
                break;
            case '-':
                n -= o;
                break;
            case '*':
                n *= o;
                break;
            case '/':
                n /= o;
                break;
            }
        }
        cout << n << '\n';
    }
    return 0;
}
