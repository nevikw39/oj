#include <iostream>
using namespace std;
int main()
{
    int m;
    while (cin >> m)
    {
        cout << (85 - m) % 60 << endl;
    }
    return 0;
}
