#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a, b;
	bool c;
	string str[] = {"AND\n", "OR\n", "XOR\n"};
	while (cin >> a >> b >> c)
	{
		char s = 0;
		if ((a && b) == c)
			s |= 1;
		if ((a || b) == c)
			s |= 2;
		if ((!!a ^ !!b) == c)
			s |= 4;
		if (!s)
			cout << "IMPOSSIBLE\n";
		else
			for (char i = 0; i < 3; i++)
				if ((s & 1 << i) == 1 << i)
					cout << str[i];
	}
	return 0;
}
