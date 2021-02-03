#include <iostream>
using namespace std;
int main()
{
    short y;
    while (cin >> y && y)
        cout << ((!(y % 4) && (y % 100 || !(y % 400))) ? "a leap year" : "a normal year") << endl;
    return 0;
}
