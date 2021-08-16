#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n && n >= 0)
		cout << oct << n << endl;
	cout << "-1\n";
	return 0;
}
