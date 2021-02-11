#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	vector<string> v(n);
	for (string &i : v)
		getline(cin, i);
	sort(v.begin(), v.end(), [](string a, string b) {
		int i = 0;
		while (a[i] == b[i] && i < a.length() && i < b.length())
			i++;
		return a[i] < b[i];
	});
	for (string i : v)
		cout << i << '\n';
	return 0;
}
