#include <iostream>
#include <string>
#include "function.h"

using namespace std;
// main function
int main(int argc, char *argv[])
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        string operation;
        cin >> operation;

        if(operation == "PLANT"){
            long long x,y;
            int withFence;
            cin >> x >> y >> withFence;
            plant(x,y,withFence);
        }
        else if(operation == "THIEF"){
            long long x,y;
            cin >> x >> y;
            thief(x,y);
        }
        else if(operation == "SUPER_THIEF"){
            long long x,y;
            cin >> x >> y;
            superThief(x,y);
        }
        else if(operation == "DISPLAY"){
            display();
        }
        else{
            cout << "error" << "\n";
        }
    }
    return 0;
}