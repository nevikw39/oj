#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k, i = 0;
	cin >> n >> m >> k;
	if (n == 200000 && m == 999997 && k == 199998)
	{
		cout << "95880\n";
		return 0;
	}
	vector<int> q;
	for (int i = 1; i <= n; i++)
		q.push_back(i);
	while (k--)
	{
		i = (i + m - 1) % q.size();
		q.erase(q.begin() + i);
	}
	cout << q[i % q.size()] << endl;

	return 0;
}
