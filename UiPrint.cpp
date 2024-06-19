
#include <iostream>
#include <string.h>
#include "UiPrint.h"
#include "TreeFuncs.h"
#include "UiFuncs.h"

void Delimeter(int count , char symbol){
    std::cout<<std::endl;
    for(int i=0;i<count;i++){
        std::cout<<symbol;
    }
    std::cout<<std::endl;
}
void Delimeter(int count , std::string string){
    std::cout<<std::endl;
    for(int i=0;i<string.length()/count;i++){
        std::cout<<string;
    }
}


void PrintTypes(){
    std::cout<<std::endl;
    std::cout << "Available Types : int , float , double " <<std::endl;
    std::cout<<std::endl;
}

void PrintFuncTree(){
    std::cout<<std::endl;
    std::cout << "Available functions :" <<std::endl;
    std::cout <<  "     Insert" <<std::endl;
    std::cout <<  "     Erase" <<std::endl;
    std::cout <<  "     GetMax" <<std::endl;
    std::cout <<  "     GetMin" <<std::endl;
    std::cout <<  "     GetSubTree" <<std::endl;
    std::cout <<  "     Search" <<std::endl;
    std::cout <<  "     Traverse" <<std::endl;
}


template <typename T>
bool cmp (T a, T b){
    return b < a;
}

template bool cmp<int>(int , int);
template bool cmp<float>(float , float);
template bool cmp<double>(double,double);


template <typename T>
void TreeInsert(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size,&cmp<T>);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Введите количество элементов для insert" << std::endl;
    int sizeInsert = 0;
    SafeCin(sizeInsert);
    while(sizeInsert<0){
        std::cout << "Введите корректное значение"<<std::endl;
        SafeCin(sizeInsert);
    }
    std::cout << "Введите элементы для insert"<<std::endl;

    for (int i = 0; i <sizeInsert; i++)
    { 
        T input ; 
        SafeCin(input);
        tree.insert(input);
        Delimeter(80,'+');
        PrintTreeHorizontaly(
            &tree,
            " >>-[ ",
            " *]> ",
            "\\*~~~",
            "/*~~~",
            '~',
            '~'
        );
        Delimeter(80,'+');
    }
    std::cout << "Ваше дерево после insert : ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(
        &tree,
        "[",
        "]"
    );
    Delimeter(80,'-');
}
template void TreeInsert<int>();
template void TreeInsert<float>();
template void TreeInsert<double>();


template <typename T>
void TreeErase(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Введите количество элементов для delete" << std::endl;
    int sizeDelete= 0;
    SafeCin(sizeDelete);
    while(sizeDelete>tree.GetSize()){
        std::cout << "Введите корректное значение"<<std::endl;
        SafeCin(sizeDelete);
    }
    std::cout << "Введите элементы для delete"<<std::endl;
    for (int i = 0; i <sizeDelete; i++)
    { 
        T input ; 
        std::cin>>input;
        while( tree.erase(input)==nullptr){
            std::cout << "Введите корректное значение"<<std::endl;
            SafeCin(input);
        }
        Delimeter(80,'+');
        PrintTreeHorizontaly(&tree);   
        Delimeter(80,'+');
    }
    std::cout << "Ваше дерево после delete : ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
}
template void TreeErase<int>();
template void TreeErase<float>();
template void TreeErase<double>();

template <typename T>
void TreeSearch(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Введите количество элементов для search" << std::endl;
    int sizeDelete= 0;
    SafeCin(sizeDelete);
    while(sizeDelete>tree.GetSize()){
        std::cout << "Введите корректное значение"<<std::endl;
        SafeCin(sizeDelete);
    }
    
    for (int i = 0; i <sizeDelete; i++)
    { 
        std::cout << "Введите элемент для search"<<std::endl;
        T input ; 
        SafeCin(input);
        TreeNode<T>* node = tree.search(input);
        if( node !=nullptr ){
            std::cout << "Значение найдено , его поддерево"<<std::endl;
            BinaryTree<T>* tree2 = tree.getSubTree(input);
            PrintTreeHorizontaly(tree2);
        }else{
            std::cout << "Значение не найдено"<<std::endl;
        }
    }
}
template void TreeSearch<int>();
template void TreeSearch<float>();
template void TreeSearch<double>();



template <typename T>
void TreeMax(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Максимальный элемент " << tree.max()->GetData() << std::endl;
}
template void TreeMax<int>();
template void TreeMax<float>();
template void TreeMax<double>();

template <typename T>
void TreeMin(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Минимальный элемент " << tree.min()->GetData() << std::endl;
}
template void TreeMin<int>();
template void TreeMin<float>();
template void TreeMin<double>();

template <typename T>
void TreeGetSubTree(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    std::cout << "Введите  элемент для взятия поддерева" << std::endl;
    T item = 0;
    std::cin >> item;
    while(!tree.contains(item)){
        std::cout << "Wrong command - Введите существующий элемент"<<std::endl;
        std::cin >> item;
    }
    BinaryTree<T>* subTree = tree.getSubTree(item);
    std::cout << "Ваше поддерево : ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(subTree);
    Delimeter(80,'-');
}
template void TreeGetSubTree<int>();
template void TreeGetSubTree<float>();
template void TreeGetSubTree<double>();


template <typename T>
void TreeTravers(){
    std::cout << "Введите размер ввода" << std::endl;
    int size = 0;
    SafeCin(size);
    std::cout << "Введите элементы дерева" << std::endl;
    BinaryTree<T> tree = TreeRead<T>(size);
    std::cout << "Ваше дерево ";
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
    bool flag = false;
    std::string traverseType;
    while(flag!=true){
        std::cout << "Введите тип обхода (KLP например)" << std::endl;
        std::cin >> traverseType;
        if(traverseType.length()!=3){
            std::cout << "Введите корректное значение"<<std::endl;
            continue;
        }
        int a[] = {0,0,0};
        for(int i =0;i<3;i++){
            switch(traverseType[i])
            {
                case 'L':
                    a[i]=1;
                    break;
                case 'P':
                    a[i]=1;
                    break;
                case 'K':
                    a[i]=1;
                    break;
                case 'l':
                    a[i]=1;
                    break;
                case 'p':
                    a[i]=1;
                    break;
                case 'k':
                    a[i]=1;
                    break;
            }
        }
        flag = true;
        for(int i=0;i<3;i++){
            if(a[i]==0) flag = false;
        }
    }
    int format[]={0,0,0};
    for (int i = 0; i <3; i++)
    { 
        switch(traverseType[i])
            {
                case 'L':
                    format[i]=1;
                    break;
                case 'P':
                    format[i]=2;
                    break;
                case 'K':
                    format[i]=0;
                    break;
                case 'l':
                    format[i]=1;
                    break;
                case 'p':
                    format[i]=2;
                    break;
                case 'k':
                    format[i]=0;
                    break;
            }
    }
    /*for(int i=0;i<3;i++){
        std::cout<<format[i]<<std::endl;
    }*/
    printTreeFormat(tree.GetRoot(),format,3);
    Delimeter(80,'-');
    PrintTreeHorizontaly(&tree);
    Delimeter(80,'-');
}
template void TreeTravers<int>();
template void TreeTravers<float>();
template void TreeTravers<double>();

void UiMain()
{   
    PrintTypes();
    std::cout<<"Введите название типа : ";
    std::string command;
    int TypeId = 0;
    while(TypeId==0){
        SafeCin(command);
        TypeId = getType(command);
        if(TypeId==0){
            std::cout<<"Wrong command - Try Again"<<std::endl;
        }
    }
    PrintFuncTree();

    std::cout << "Введите название функции : ";
    std::string funcName;
    SafeCin(funcName);
    while (getFuncTree(funcName) == 0)
    {
        std::cout << "Wrong command - Try Again" << std::endl;
        SafeCin(funcName);
    }
    switch (getFuncTree(funcName))
    {
    case 1:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeInsert<int>();
            break;
        case 2:
            TreeInsert<float>();
            break;
        case 3:
            TreeInsert<double>();
            break;
        default:
        }
        break;
    }
    case 2:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeErase<int>();
            break;
        case 2:
            TreeErase<float>();
            break;
        case 3:
            TreeErase<double>();
            break;
        default:
        }
        break;
    }
    case 3:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeMin<int>();
            break;
        case 2:
            TreeMin<float>();
            break;
        case 3:
            TreeMin<double>();
            break;
        default:
        }
        break;
    }
    case 4:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeMax<int>();
            break;
        case 2:
            TreeMax<float>();
            break;
        case 3:
            TreeMax<double>();
            break;
        default:
        }
        break;
    }
    case 5:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeGetSubTree<int>();
            break;
        case 2:
            TreeGetSubTree<float>();
            break;
        case 3:
            TreeGetSubTree<double>();
            break;
        default:
        }
        break;
    }
    case 6:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeSearch<int>();
            break;
        case 2:
            TreeSearch<float>();
            break;
        case 3:
            TreeSearch<double>();
            break;
        default:
        }
        break;
    }
    case 7:
    {
        Delimeter(80, '=');
        switch (TypeId)
        {
        case 1:
            TreeTravers<int>();
            break;
        case 2:
            TreeTravers<float>();
            break;
        case 3:
            TreeTravers<double>();
            break;
        default:
        }
        break;
    }
    }
}