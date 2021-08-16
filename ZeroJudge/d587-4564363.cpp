#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	unsigned int n;
	vector<int> v(3);
	cin >> n;
	while (n--)
	{
		char tmp;
		cin >> tmp;
		v[tmp - '1']++;
	}
	for (unsigned int i = 0; i < 3; i++)
		for (int j = 0; j < v[i]; j++)
			cout << i + 1 << ' ';
	return 0;
}
