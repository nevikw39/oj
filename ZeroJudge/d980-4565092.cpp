#include <iostream>
#include <array>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short t;
	cin >> t;
	for (short i = 0; i < t; i++)
	{
		cout << "Case " << i + 1 << ": ";
		array<long, 3> a;
		for (long &i : a)
			cin >> i;
		sort(a.begin(), a.end());
		if (a[0] < 1 || a[1] < 1 || a[2] < 1 || a[0] + a[1] <= a[2])
			cout << "Invalid\n";
		else
			cout << (a[0] == a[1] || a[1] == a[2] ? a[0] == a[2] ? "Equilateral\n" : "Isosceles\n" : "Scalene\n");
	}
	return 0;
}
