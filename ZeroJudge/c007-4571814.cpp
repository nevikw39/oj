#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bool b = false;
	char c;
	while (cin.get(c))
		cout << (c == '"' ? ((b = !b) ? "``" : "''") : string(1, c));
	return 0;
}
