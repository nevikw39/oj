#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int x)
{
	int gap = 4;
	if (x == 1 || !x)
		return false;
	else if (x < 4)
		return true;
	else if (!(x % 2) || !(x % 3))
		return false;
	for (int i = 5; i <= ceil(sqrt(x)); gap = 6 - gap, i += gap)
		if (!(x % i))
			return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
		cout << (isprime(n) ? "It's a prime!!!\n" : "It's not a prime!!!\n");
	return 0;
}
