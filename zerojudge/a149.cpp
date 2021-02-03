#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    while (cin >> t)
    {
        for (int i = 0; i < t; i++)
        {
            int sum = 1;
            string s;
            cin >> s;
            for (char c : s)
                sum *= c - '0';
            cout << sum << endl;
        }
    }
    return 0;
}
