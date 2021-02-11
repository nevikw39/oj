#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v)
		cin >> i;
	sort(v.begin(), v.end());
	for (int i : v)
		cout << i << ' ';
	return 0;
}
