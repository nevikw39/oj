#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a[] = {1, 10, 19, 28, 37, 46, 55, 64, 39, 73, 82, 2, 11, 20, 48, 29, 38, 47, 56, 65, 74, 83, 21, 3, 12, 30};
    string s;
    while (cin >> s)
    {
        int sum = s[8] - '0';
        for (char &c : s)
            sum += (c - '0') * (&s.back() - &c);
        for (int &i : a)
            if ((sum + i) % 10 == 0)
                cout << (char)((&i - a) + 65);
        cout << endl;
    }
    return 0;
}
