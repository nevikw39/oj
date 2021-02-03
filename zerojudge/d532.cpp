#include <iostream>
using namespace std;
int main()
{
    short a, b, sum = 0;
    cin >> a >> b;
    for (short i = a; i <= b; i++)
        sum += (!(i % 4) && (i % 100 || !(i % 400)));
    cout << sum << endl;
    return 0;
}
