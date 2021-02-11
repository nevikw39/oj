#include <iostream>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    unsigned long long n;
    cin >> n;
    cout << "F=" << 15 * n * (n + 1) / 2 * n * (n + 1) / 2;
    return 0;
}
