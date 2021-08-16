#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s[] = {"µU", "Âû", "ª¯", "½Þ", "¹«", "¤û", "ªê", "¨ß", "Às", "³D", "°¨", "¦Ï"};
	short n;
	while (cin >> n)
	{
		n > 0 ? n += 99 : n += 100;
		cout << s[n % 12] << endl;
	}
	return 0;
}
