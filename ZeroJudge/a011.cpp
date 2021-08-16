#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    while (getline(cin, s))
    {
        int sum = 0;
        bool b = false;
        for (char c : s)
        {
            sum += b && !isalpha(c);
            b = isalpha(c);
        }
        sum += b;
        cout << sum << endl;
    }
    return 0;
}
