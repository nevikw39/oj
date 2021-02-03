#include <cctype>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string pwd, str[] = {"WEAK", "ACCEPTABLE", "GOOD", "STRONG"};
    while (cin >> pwd)
    {
        bool low = false, up = false, sym = false;
        int n = pwd.length() > 7;
        for (char c : pwd)
            if (isalpha(c))
                if (islower(c))
                    low = true;
                else
                    up = true;
            else
                sym = true;
        n += (low && up) + ((low || up) && sym);
        cout << "This password is " << str[n] << endl;
    }
    return 0;
}
