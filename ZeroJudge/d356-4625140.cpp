#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short k;
	while (cin >> k)
	{
		int i;
		double s = 1;
		for (i = 2; s < k; i++)
			s += 1.0L / i;
		cout << i - 1 << endl;
	}
	return 0;
}
