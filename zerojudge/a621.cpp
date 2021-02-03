#include <iostream>
using namespace std;
int main()
{
    unsigned short n;
    while (cin >> n)
    {
        cout << "2^0 = 1" << endl;
        for (char i = 1; i <= n; i++)
            cout << "2^" << short(i) << " = " << (2 << (i - 1)) << endl;
    }
    return 0;
}
