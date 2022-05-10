#include <iostream>
#include <string>
#include "function.h"

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

int main(){
    Manager<Node> taskManager = Manager<Node>();
    int cmdCnt = 0;
    std::string command;
    cin >> cmdCnt;
    for(int j=0;j<cmdCnt;j++){
        cin >> command;
        if(command == "SET_ENDTIME"){
            u32 endTime;
            cin >> endTime;
            taskManager.cmd_set_endTime(endTime);
        }
        else if(command == "ADD_TA"){
            std::string id;
            u32 begin;
            cin >> id >> begin;
            taskManager.cmd_add_ta(id,begin);
        }
        else if(command == "ADD_TASK"){
            std::string taskName;
            u32 costTime;
            cin >> taskName >> costTime;
            taskManager.cmd_add_task(taskName,costTime);
        }
        else if(command == "CHECK_SCHEDULE"){
            u32 costTime, endTime;
            cin >> costTime >> endTime;
            taskManager.cmd_check_schedule(costTime,endTime);
        }
    }
    taskManager.result();
    return 0;
}