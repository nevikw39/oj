#include <iostream>
using namespace std;
int main()
{
    int n;

    while (cin >> n)
    {
        int s = 1;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                s += i;

        cout << (s > n ? "�ռ�" : (s < n ? "����" : "������")) << endl;
    }

    return 0;
}
