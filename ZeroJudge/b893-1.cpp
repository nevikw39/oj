#include <iostream>
using namespace std;
class F
{
    short a, b, c, d, e, f;

public:
    F(short _a, short _b, short _c, short _d, short _e, short _f)
    {
        this->a = _a, this->b = _b, this->c = _c, this->d = _d, this->e = _e, this->f = _f;
    }
    long long operator()(long long x)
    {
        return a * x * x * x * x * x + b * x * x * x * x + c * x * x * x + d * x * x + e * x + f;
    }
};
int main()
{
    bool _b = false;
    short a, b, c, d, e, f;
    while (cin >> a >> b >> c >> d >> e >> f)
    {
        F foo(a, b, c, d, e, f);
        if (!a && !b && !c && !d && !e && !f)
            cout << "Too many... = =\"" << endl;
        else
        {
            for (int i = -35; i < 36; i++)
            {
                if (!foo(i))
                {
                    cout << i << ' ' << i << endl;
                    _b = true;
                }
                else if (foo(i) > 0 ^ foo(i + 1) > 0 && foo(i + 1))
                {
                    cout << i << ' ' << i + 1 << endl;
                    _b = true;
                }
            }
            if (!_b)
                cout << "N0THING! >\\\\\\<" << endl;
        }
    }
    return 0;
}
