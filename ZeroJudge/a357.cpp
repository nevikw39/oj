#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
long f(long x)
{
    if (x == 1)
        return 1;
    if (x & 1)
        return f(x - 1) + f(x + 1);
    return f(x / 2);
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
	long n;
    cin >> n;
    cout << f(n) << endl;
	return 0;
}
