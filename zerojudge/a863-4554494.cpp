#include <iostream>
#include <string>
using namespace std;
int foo(int n)
{
	int sum = 0;
	for (char i : to_string(n))
		sum += (i - '0') * (i - '0');
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
	{
		int m = n;
		for (int i = 0; i < 100; i++)
		{
			m = foo(m);
			if (m == 1)
				break;
		}
		cout << n << " is a" << (m == 1 ? " " : "n un") << "happy number\n";
	}
	return 0;
}
