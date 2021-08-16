#include <iostream>
#include <string>
#include <deque>
using namespace std;
void f(short x, short n)
{
	deque<char> d;
	for (; x; x /= 2)
		d.push_front(x % 2);
	while (d.size() < n)
		d.push_front(0);
	for (int i : d)
		cout << i;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n;
	while (cin >> n)
	{
		for (short i = 0; i < 1 << n; i++)
		{
			f(i, n);
			cout << endl;
		}
	}
	return 0;
}
