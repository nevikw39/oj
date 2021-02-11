#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while (cin >> s)
	{
		int sum = 0;
		for (char c : s)
			sum += (c == '0' || c == '6' || c == '9') + (c == '8') * 2;
		cout << sum << endl;
	}
	return 0;
}
