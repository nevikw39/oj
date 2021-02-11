#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned long n, m;
	while (cin >> n >> m)
	{
		unsigned long i, x;
		if (!m)
		{
			cout << "Go Kevin!!\n";
			continue;
		}
		for (i = 1, x = 1; i < n; x++)
			i += 1 + m * x;
		cout << (i == n ? "Go Kevin!!\n" : "No Stop!!\n");
	}
	return 0;
}
