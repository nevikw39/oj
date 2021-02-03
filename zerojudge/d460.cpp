#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    cout << (a > 5 && a < 12) * 590 + (a > 11 && a < 18) * 790 + (a > 17 && a < 60) * 890 + (a > 59) * 399 << endl;
    return 0;
}
