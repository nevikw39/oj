#include "2013.hpp"

int main()
{
    DetectSquares *obj = new DetectSquares();
    obj->add({3, 10});
    obj->add({11, 2});
    obj->add({3, 2});
    cout << obj->count({11, 10}) << '\n'
         << obj->count({14, 8}) << '\n';
    obj->add({11, 2});
    cout << obj->count({11, 10}) << '\n';
    delete obj;
    cout << '\n';
    
    obj = new DetectSquares();
    obj->add({5, 10});
    obj->add({10, 5});
    obj->add({10, 10});
    cout << obj->count({5, 5}) << '\n';
    obj->add({3, 0});
    obj->add({8, 0});
    obj->add({8, 5});
    cout << obj->count({3, 5}) << '\n';
    obj->add({9, 0});
    obj->add({9, 8});
    obj->add({1, 8});
    cout << obj->count({1, 0}) << '\n';
    obj->add({0, 0});
    obj->add({8, 0});
    obj->add({8, 8});
    cout << obj->count({0, 8}) << '\n';
    delete obj;
    return 0;
}
