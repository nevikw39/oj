#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n)
	{
		vector<short> v(n);
		for (short &i : v)
			cin >> i;
		sort(v.begin(), v.end());
		for (short i : v)
			cout << i << ' ';
		cout << endl;
	}
	return 0;
}
