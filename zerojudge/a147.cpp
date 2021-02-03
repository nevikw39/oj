#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 1; i < n; i++)
            cout << (i % 7 != 0 ? to_string(i) + " " : "");
        cout << endl;
    }
    return 0;
}
