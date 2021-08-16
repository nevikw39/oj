#include <algorithm>
#include <iostream>
#include <array>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		array<int, 4> a;
		for (int &i : a)
			cin >> i;
		sort(a.begin(), a.end());
		cout << (a[0] == a[3] ? "square\n" : a[0] == a[1] && a[2] == a[3] ? "rectangle\n" : a[0] + a[1] + a[2] > a[3] ? "quadrangle\n" : "banana\n");
	}
	return 0;
}
