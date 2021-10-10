#include "2034.hpp"

int main()
{
    StockPrice *obj = new StockPrice();
    obj->update(1, 10);
    obj->update(2, 5);
    cout << obj->current() << '\n'
         << obj->maximum() << '\n';
    obj->update(1, 3);
    cout << obj->maximum() << '\n';
    obj->update(4, 2);
    cout << obj->minimum() << '\n'
         << '\n';
    delete obj;
    obj = new StockPrice();
    obj->update(38, 2308);
    cout << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->minimum() << '\n'
         << obj->maximum() << '\n'
         << obj->maximum() << '\n'
         << obj->maximum() << '\n'
         << obj->minimum() << '\n'
         << obj->minimum() << '\n'
         << obj->maximum() << '\n';
    obj->update(47, 7876);
    cout << obj->maximum() << '\n'
         << obj->minimum() << '\n';
    obj->update(58, 1866);
    cout << obj->maximum() << '\n'
         << obj->minimum() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n';
    obj->update(43, 121);
    cout << obj->minimum() << '\n'
         << obj->maximum() << '\n';
    obj->update(40, 5339);
    cout << obj->maximum() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n';
    obj->update(32, 5339);
    cout << obj->current() << '\n'
         << obj->minimum() << '\n';
    obj->update(43, 6414);
    obj->update(49, 9369);
    cout << obj->minimum() << '\n'
         << obj->minimum() << '\n';
    obj->update(36, 3192);
    cout << obj->current() << '\n';
    obj->update(48, 1006);
    cout << obj->maximum() << '\n';
    obj->update(53, 8013);
    cout << obj->minimum() << '\n'
         << '\n';
    delete obj;
    obj = new StockPrice();
    obj->update(88, 9184);
    cout << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->minimum() << '\n';
    obj->update(83, 343);
    cout << obj->maximum() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n';
    obj->update(87, 693);
    cout << obj->minimum() << '\n'
         << obj->current() << '\n'
         << obj->minimum() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n';
    obj->update(88, 7810);
    obj->update(89, 624);
    cout << obj->maximum() << '\n';
    obj->update(86, 9963);
    obj->update(88, 7345);
    cout << obj->minimum() << '\n'
         << obj->maximum() << '\n'
         << obj->minimum() << '\n';
    obj->update(83, 5533);
    cout << obj->minimum() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->current() << '\n';
    obj->update(85, 4908);
    cout << obj->current() << '\n'
         << obj->maximum() << '\n';
    obj->update(85, 5125);
    cout << obj->maximum() << '\n'
         << obj->current() << '\n'
         << obj->maximum() << '\n'
         << obj->minimum() << '\n'
         << obj->minimum() << '\n';
    delete obj;
    return 0;
}
