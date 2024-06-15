
#include <iostream>
#include <algorithm>
#include "UiFuncs.h"
#include "UiPrint.h"
#include <string>


int getType(std::string typeName)
{
    std::string lcTypeName = typeName;
    for(int i = 0 ; i<lcTypeName.size();i++){
        lcTypeName[i]=std::tolower(lcTypeName[i]);
    }
    if (lcTypeName == "int") return 1 ; 
    if (lcTypeName == "float") return 2 ; 
    if (lcTypeName == "double") return 3 ; 
    if (lcTypeName == "complex") return 4 ; 
    if (lcTypeName == "char") return 5 ; 

   return 0 ;
}

int getFuncTree(std::string funcName)
{
    std::string lcfuncName = funcName;
    for(int i = 0 ; i<lcfuncName.size();i++){
        lcfuncName[i]=std::tolower(funcName[i]);
    }
    if (lcfuncName == "insert") return 1 ; 
    if (lcfuncName == "erase") return 2 ; 
    if (lcfuncName == "min") return 3 ; 
    if (lcfuncName == "max") return 4 ;
    if (lcfuncName == "getsubtree") return 5 ;  
    if (lcfuncName == "search") return 6 ;  
    if (lcfuncName == "traverse") return 7 ; 

    return 0 ;
}



template <typename T>
BinaryTree<T>& TreeRead(int count){
    T current;
    BinaryTree<T>* tree = new BinaryTree<T>(); 
    for(int i =0 ; i <count;i++){
        //std::cin>>current;
        SafeCin(current);
        if(!tree->contains(current)){
            tree->insert(current);
        }
        Delimeter(80,'+');
        PrintTreeHorizontaly(tree);
        Delimeter(80,'+');
    }
    return *tree;
}
template BinaryTree<int>& TreeRead<int>(int);
template BinaryTree<float>& TreeRead<float>(int);
template BinaryTree<double>& TreeRead<double>(int);

template <typename T>
BinaryTree<T>& TreeRead(int count,bool (*comparator)(T ,T )){
    T current;
    BinaryTree<T>* tree = new BinaryTree<T>(comparator); 
    for(int i =0 ; i <count;i++){
        SafeCin(current);
        if(!tree->contains(current)){
            tree->insert(current);
        }
        Delimeter(80,'+');
        PrintTreeHorizontaly(tree);
        Delimeter(80,'+');
    }
    return *tree;
}
template BinaryTree<int>& TreeRead<int>(int , bool (*comparator)(int ,int ));
template BinaryTree<float>& TreeRead<float>(int , bool (*comparator)(float ,float ));
template BinaryTree<double>& TreeRead<double>(int , bool (*comparator)(double ,double ));

template<typename T>
void SafeCin(T& input,std::string ErrorMessage){
    while ( !(std::cin >> input)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << ErrorMessage<<std::endl;;
    }
}
template void SafeCin<int>(int&,std::string );
template void SafeCin<float>(float&,std::string );
template void SafeCin<double>(double&,std::string );
template void SafeCin<std::string>(std::string&,std::string );