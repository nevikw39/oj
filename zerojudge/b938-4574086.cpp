#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<bool> v(n + 1, true);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		if (!v[k])
			cout << "0u0 ...... ?\n";
		else
		{
			int j = k + 1;
			while (!v[j] && v.begin() + j != v.end())
				j++;
			if (v.begin() + j == v.end())
			{
				cout << "0u0 ...... ?\n";
				continue;
			}
			v[j] = false;
			cout << j << '\n';
		}
	}
	return 0;
}
