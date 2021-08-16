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
	auto a = max_element(v.begin(), v.end()), b = min_element(a, v.end()), _n = min_element(v.begin(), v.end()), m = max_element(v.begin(), _n);
	cout << max(*a - *b, *m - *_n);
	return 0;
}
