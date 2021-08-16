#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned short t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		cout << (a > b ? '>' : a < b ? '<' : '=') << endl;
	}
	return 0;
}
