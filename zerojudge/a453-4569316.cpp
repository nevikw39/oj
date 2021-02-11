#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		double d = sqrt(b * b - 4 * a * c);
		cout << (ceil(d) == floor(d) ? "Yes\n" : "No\n");
	}
	return 0;
}
