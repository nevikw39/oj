#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		if (!n)
		{
			cout<<"0! = 1 = 1\n";
			continue;
		}
		int sum = 1;
		cout << n << "! = ";
		for (short i = ++n; --i - 1;)
		{
			cout << i << " * ";
			sum *= i;
		}
		cout << "1 = " << sum << endl;
	}
	return 0;
}
