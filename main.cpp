
#include <iostream>
#include "Tree.h"
#include "tests.h"
#include "UiPrint.h"
#include "UiFuncs.h"

// clang++ main.cpp UiFuncs.cpp UiPrint.cpp TreeFuncs.cpp  tests.cpp -Wall -Wextra -o main.exe 

int main()
{
    testTreeFunc();
    testMapFunc();
    testWhereFunc();
    testReduceFunc();
    std::cout<<"Tested successfully"<<std::endl;

    std::string command="yes";
    while(command=="yes"){
        Delimeter(80,'=');
        UiMain(); 
        std::cout<<"Если жедаете продолжить напишите YES"<<std::endl;
        std::cin>>command;
        for(int i = 0 ; i<command.size();i++){
            command[i]=std::tolower(command[i]);
        }
        Delimeter(80,'=');
    }
    
    return 0;
}
