#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		int a, f;
		cin >> a >> f;
		while (f--)
		{
			for (int i = 0; i < a; i++)
			{
				for (int j = 0; j < i + 1; j++)
					cout << i + 1;
				cout << endl;
			}
			for (int i = a - 1; i; i--)
			{
				for (int j = 0; j < i; j++)
					cout << i;
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}
