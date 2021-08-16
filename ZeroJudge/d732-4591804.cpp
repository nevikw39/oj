#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	vector<int> v;
	cin >> n >> k;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	while (k--)
	{
		int tmp;
		cin >> tmp;
		auto it = lower_bound(v.begin(), v.end(), tmp);
		cout << (it != v.end() && *it == tmp ? it - v.begin() + 1 : 0) << endl;
	}
	return 0;
}
