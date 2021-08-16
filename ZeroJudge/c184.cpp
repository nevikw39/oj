#include <iostream>
#include <string>
using namespace std;
int f(int x)
{
    int s = 1;

    for (int i = 2; i < x; i++)
        if (x % i == 0)
            s += i;

    return s;
}
int main()
{
    int n;

    while (cin >> n)
    {
        if (n == 0)
            break;

        int m = f(n);
        cout << (m == n ? string("=") + to_string(n) : (f(m) == n ? to_string(m) : "0")) << endl;
    }

    return 0;
}
