#include <iostream>
#include <map>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	map<int, int> m;
	while (cin >> n)
		m[n]++;
	for (auto i : m)
		if (i.second == 2)
		{
			cout << i.first << endl;
			return 0;
		}
	return 0;
}
