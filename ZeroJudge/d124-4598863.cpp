#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string n;
	while (cin >> n)
	{
		int sum = 0;
		for (char i : n)
			sum += i - '0';
		cout << (sum % 3 ? "no\n" : "yes\n");
	}
	return 0;
}
