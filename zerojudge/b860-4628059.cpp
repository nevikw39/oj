#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c = 0;
	cin >> a >> b;
	while (b && a)
	{
		if (a >= 12)
		{
			a -= 11;
			c++;
		}
		else
		{
			a++;
			b--;
		}
	}
	cout << c << endl;
	return 0;
}
