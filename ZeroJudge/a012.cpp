#include <iostream>
using namespace std;
int main()
{
    unsigned long a, b;
    while (cin >> a >> b)
        cout << (a < b ? b - a : a - b) << endl;
    return 0;
}
