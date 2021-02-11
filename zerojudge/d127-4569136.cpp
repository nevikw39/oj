#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long l;
	while (cin >> l)
	{
		l /= 2;
		cout << (l / 2) * (l / 2 + l % 2) << endl;
	}
	return 0;
}
