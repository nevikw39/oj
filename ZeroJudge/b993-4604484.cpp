#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		int a = 0, tmp;
		while (n--)
		{
			cin >> tmp;
			a = tmp > a ? tmp : a;
		}
		cout << a << endl;
	}
	return 0;
}
