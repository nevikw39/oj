#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int c = 499; c; c--)
	{
		int a, b;
		for (a = 1, b = 999 - c; a <= b; a++, b--)
			if (a * a + b * b == c * c)
			{
				cout << a * b * c << endl;
				return 0;
			}
	}
	return 0;
}
