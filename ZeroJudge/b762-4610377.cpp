#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	short n, k = 0, d = 0, a = 0, combo = 0;
	hash<string> h;
	string str[9] = {"", "You have slain an enemie.\n", "You have slain an enemie.\n", "KILLING SPREE!\n", "RAMPAGE~\n", "UNSTOPPABLE!\n", "DOMINATING!\n", "GUALIKE!\n", "LEGENDARY!\n"};
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "Get_Kill")
		{
			k++;
			combo = combo == 8 ? 8 : combo + 1;
			cout << str[combo];
		}
		else if (s == "Get_Assist")
			a++;
		else
		{
			d++;
			cout << (combo < 3 ? "You have been slained.\n" : "SHUTDOWN.\n");
			combo = 0;
		}
	}
	cout << k << '/' << d << '/' << a;
	return 0;
}
