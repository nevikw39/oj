#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	cin >> n;
	while (n--)
	{
		short h1, m1, h2, m2, m3;
		cin >> h1 >> m1 >> h2 >> m2 >> m3;
		cout << (h2 * 60 + m2 >= h1 * 60 + m1 + m3 ? "Yes\n" : "No\n");
	}
	return 0;
}
