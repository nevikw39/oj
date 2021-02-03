#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        int sum;
        if (n >= 40)
            sum = 100;
        else if (n > 20)
            sum = 80 + n - 20;
        else if (n > 10)
            sum = 60 + n * 2 - 20;
        else
            sum = n * 6;
        cout << sum << endl;
    }
    return 0;
}
