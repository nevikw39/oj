#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	while (cin >> a >> b)
		cout << ((b[0] < a[0] ? b[0] + 26 : b[0]) - a[0]) << endl;
	return 0;
}
