#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        int n = (a > b) ? a : b;
        cout << ((n > c) ? n : c) << endl;
    }
    return 0;
}
