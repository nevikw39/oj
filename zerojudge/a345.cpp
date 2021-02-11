#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
	long n;
    while (cin >> n)
        cout << (n ? (n % 9 ? n % 9 : 9) : 0) << endl;
	return 0;
}
