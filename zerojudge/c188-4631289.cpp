#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	short n;
	vector<long> v(201, 0);
	for (long & i : v)
		i = 0;
	v[0] = 1;
	for (int i = 1; i < 201; i++)
		for (int j = i; j < 201; j++)
			v[j] += v[j - i];
	while (cin >> n)
		cout << v[n] << endl;
	return 0;
}
