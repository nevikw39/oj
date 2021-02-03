#include <cmath>
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    map<int, unsigned short> m;
    for (int i = 1; i < 46341; i++)
        m[i * i] = i;
    int n;
    while (cin >> n && n)
        cout << (m[n] ? "yes" : "no") << endl;
    return 0;
}
