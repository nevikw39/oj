#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin)
	{
		short n, sum = 0;
		array<short, 10> a;
		for (short &i : a)
			cin >> i;
		if (cin.eof())
			break;
		cin >> n;
		n += 30;
		for (short i : a)
			sum += i <= n;
		cout << sum << endl;
	}
	return 0;
}
