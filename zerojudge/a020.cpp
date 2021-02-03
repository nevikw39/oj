#include <iostream>
using namespace std;
int main()
{
    int a[] = {1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3};
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 4, 8, 9, 0, 1, 2, 5, 3, 4, 5, 6, 7, 8, 9, 2, 0, 1, 3};
    char l;
    char n[9];
    while (cin >> l)
    {
        for (auto &i : n)
            cin >> i;
        int t = l - 'A', sum = a[t] + b[t] * 9;
        for (auto &i : n)
            sum += (i - '0') * (8 - (&i - n));
        sum += n[8] - '0';
        cout << ((sum % 10) == 0 ? "real" : "fake") << endl;
    }
    return 0;
}
