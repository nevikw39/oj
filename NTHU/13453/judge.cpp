#include <iostream>
#include <string>
#include "function.hpp"

using namespace std;

/*
In partial judge problem, you need to compile two .cpp files and a header file together.
For compile multiple .cpp files and .h headers, please refer to the following tutorial.
Chinese:
https://github.com/htchen/i2p-nthu/blob/master/%E7%A8%8B%E5%BC%8F%E8%A8%AD%E8%A8%88%E4%B8%80/%E5%A6%82%E4%BD%95compile%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88/%E5%A6%82%E4%BD%95%20compile%20%E5%A4%9A%E5%80%8B%E6%AA%94%E6%A1%88.md
English (terminal command):
https://stackoverflow.com/questions/3202136/using-g-to-compile-multiple-cpp-and-h-files

For Dev C++ or other IDE, please search for the Internet.
*/

int main()
{

    int W, H, M;
    int col;
    string command;

    cin >> W >> H;
    cin >> M;

    InitialzeStage(W, H);

    for (int i=0; i<M; i++){
        cin >> command;
        if(command == "SHOOT"){
            cin >> col;
            ShootNormal(col, W);
        }
        else if(command == "SPECIAL"){
            cin >> col;
            ShootSpecial(col, W);
        }
        else if(command == "FRONT_ROW"){
            FrontRow(W);
        }
    }

    ShowResult(W);
    deleteStage();

    return 0;
}
