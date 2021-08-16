#include <iostream>
using namespace std;
int main()
{
    int a, b, sum = 0;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        sum += i % 2 ? 0 : i;
    cout << sum << endl;
    return 0;
}
