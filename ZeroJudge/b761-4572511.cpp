#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	while (cin >> n)
		cout << (n % 4 ? "fat\n" : "egg\n");
	return 0;
}
