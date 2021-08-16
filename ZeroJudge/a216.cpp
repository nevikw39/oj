#include <iostream>
using namespace std;
int main()
{
    long n;
    while (cin >> n)
    {
        cout << n++ * n / 2 << " " << ++n * --n * --n / 6 << endl;
    }
    return 0;
}
