#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long n;
	while (cin >> n)
	{
		int sum = 0;
		while (n /= 5)
		sum += n;
		cout << sum << endl;
	}
	return 0;
}
