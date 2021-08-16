#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
        cout << (n == m ? m : m + 1) << endl;
    return 0;
}
