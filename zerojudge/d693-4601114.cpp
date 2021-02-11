#include <algorithm>
#include <iostream>
using namespace std;
long inline _lcm(long a, long b)
{
	return a * b / __gcd(a, b);
}
int main()
{
	short n;
	while(cin >> n && n)
	{
		long lcm;
		short tmp;
		cin >> lcm;
		n--;
		while (n--)
		{
			cin >> tmp;
			lcm = _lcm(lcm, tmp);
		}
		cout << lcm << endl;
	}
	return 0;
}
