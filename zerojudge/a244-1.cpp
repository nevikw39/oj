#include <iostream>
using namespace std;
int main()
{
    long (*funcs[])(long, long) = {
        [](long x, long y) { return x + y; },
        [](long x, long y) { return x - y; },
        [](long x, long y) { return x * y; },
        [](long x, long y) { return x / y; },
    };
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            long a, b, o;
            cin >> o >> a >> b;
            cout << funcs[o - 1](a, b) << endl;
        }
    }
    return 0;
}
