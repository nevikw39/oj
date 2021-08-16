#include <iostream>
using namespace std;
int main()
{
    int i;
    while (cin >> i)
    {
        cout << (i % 2 ? "Odd" : "Even") << endl;
    }
    return 0;
}
