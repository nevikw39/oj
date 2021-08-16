#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore(1, '\n');
	int a = n * n++, i = 0;
	while (a--)
	{
		char c = cin.get();
		if (!(i % n))
			cout.put(c);
		i++;
	}
	return 0;
}
