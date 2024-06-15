

#include <iostream>
#include "Tree.h"
#include "TreeFuncs.h"


template <typename T> 
void PrintTreeFormat(TreeNode<T> *elem, int* format, int format_size)
{   
    if (elem == nullptr)
    {
        return;
    }
    for(int i=0; i < format_size ; i++ ){
        if( format[i] == 0 ){
            std::cout << " {" << elem->GetData() << "} ";
        }
        if( format[i]==1 && elem->GetLeft()!=nullptr ){
            std::cout << " (" ;
            PrintTreeFormat(elem->GetLeft(),format,format_size);
            std::cout << ") " ;
        }
        if( format[i]==2 && elem->GetRight()!=nullptr ){
            std::cout << " [" ;
            PrintTreeFormat(elem->GetRight(),format,format_size);
            std::cout << "] " ;
        }
    }
}
template void PrintTreeFormat<int>(TreeNode<int> *elem, int* format, int format_size);
template void PrintTreeFormat<float>(TreeNode<float> *elem, int* format, int format_size);
template void PrintTreeFormat<double>(TreeNode<double> *elem, int* format, int format_size);


template <typename T> 
void WriteTreeFormat(TreeNode<T> *node,  int* format, int format_size,T* array , int* index  ) 
{
    if (node == nullptr || array == nullptr || format == nullptr || *index < 0)
    {
        return;
    }
    for(int i =0; i<format_size ; i++ ){
        if(format[i]==0){
            array[*index] = node->GetData();
            (*index)++;
        }
        if(format[i]==1){
            WriteTreeFormat(node->GetLeft(),format,format_size,array,index);
        }
        if(format[i]==2){
            WriteTreeFormat(node->GetRight(),format,format_size,array,index);
        }
    }
}
template void WriteTreeFormat<int>(TreeNode<int> *node,  int* format, int format_size,int* array , int* index  );
template void WriteTreeFormat<float>(TreeNode<float> *node,  int* format, int format_size,float* array , int* index  );
template void WriteTreeFormat<double>(TreeNode<double> *node,  int* format, int format_size,double* array , int* index  );

template <typename T> 
void WriteTreeTraverse(BinaryTree<T>& tree, int* format,int format_size,T* array ) 
{   
    int index = 0;
    WriteTreeFormat(tree.GetRoot(),format,format_size,array,&index);
}

template void WriteTreeTraverse<int>(BinaryTree<int>& tree, int* format,int format_size,int* array ) ;
template void WriteTreeTraverse<float>(BinaryTree<float>& tree, int* format,int format_size,float* array ) ;
template void WriteTreeTraverse<double>(BinaryTree<double>& tree, int* format,int format_size,double* array ) ;

template <typename T> 
void PrintTreeTraverse(BinaryTree<T>& tree, int* format,int format_size) 
{   
    PrintTreeFormat(tree.GetRoot(),format,format_size);
}
template void PrintTreeTraverse<int>(BinaryTree<int>& tree, int* format, int format_size);
template void PrintTreeTraverse<float>(BinaryTree<float>& tree, int* format, int format_size);
template void PrintTreeTraverse<double>(BinaryTree<double>& tree, int* format, int format_size);



template <typename T>
void printTreeHelper
    (
    TreeNode<T> *node,
    const std::string &rightPrefix,
    const std::string &centerPrefix ,
    const std::string &leftPrefix ,
    const std::string &dataPrefix ,
    const std::string &dataSuffix ,
    const std::string &horLeftSpace,
    const std::string &horRightSpace ,
    const char vertSpace ,
    const char fillerElem
    )
{
    if (!node) return;
    if (node->GetRight())
        printTreeHelper(
            node->GetRight(),
            rightPrefix + std::string(horRightSpace.length()+dataPrefix.length(),fillerElem),
            rightPrefix + std::string(dataPrefix.length(),fillerElem) +horRightSpace,
            rightPrefix + std::string(dataPrefix.length(),fillerElem)+vertSpace+std::string(horRightSpace.length()-1,fillerElem),
            dataPrefix,
            dataSuffix,
            horLeftSpace,
            horRightSpace,
            vertSpace,
            fillerElem
        );

    std::cout << centerPrefix << dataPrefix <<node->GetData() << dataSuffix <<std::endl;

    if (node->GetLeft())
        printTreeHelper(
            node->GetLeft(),
            leftPrefix + std::string(dataPrefix.length(),fillerElem)+vertSpace+std::string(horLeftSpace.length()-1,fillerElem),
            leftPrefix + std::string(dataPrefix.length(),fillerElem) + horLeftSpace,
            leftPrefix + std::string(horLeftSpace.length()+dataPrefix.length(),fillerElem),
            dataPrefix,
            dataSuffix,
            horLeftSpace,
            horRightSpace,
            vertSpace,
            fillerElem
        );
}
template void printTreeHelper<int>(
    TreeNode<int> *node,
    const std::string &rightPrefix,
    const std::string &centerPrefix ,
    const std::string &leftPrefix ,
    const std::string &dataPrefix ,
    const std::string &dataSuffix ,
    const std::string &horLeftSpace,
    const std::string &horRightSpace ,
    const char vertSpace ,
    const char fillerElem);
template void printTreeHelper<float>(
    TreeNode<float> *node,
    const std::string &rightPrefix,
    const std::string &centerPrefix ,
    const std::string &leftPrefix ,
    const std::string &dataPrefix ,
    const std::string &dataSuffix ,
    const std::string &horLeftSpace,
    const std::string &horRightSpace ,
    const char vertSpace ,
    const char fillerElem);
    
template void printTreeHelper<double>(
    TreeNode<double> *node,
    const std::string &rightPrefix,
    const std::string &centerPrefix ,
    const std::string &leftPrefix ,
    const std::string &dataPrefix ,
    const std::string &dataSuffix ,
    const std::string &horLeftSpace,
    const std::string &horRightSpace ,
    const char vertSpace ,
    const char fillerElem);

template <typename T>
void PrintTreeHorizontaly(
    BinaryTree<T>* tree,
    const std::string& dataPrefix,
    const std::string& dataSuffix ,
    const std::string& horLeftSpace ,
    const std::string& horRightSpace ,
    const char vertSpace ,
    const char fillerElem 
)
{   
    if(tree!=nullptr){
        printTreeHelper(tree->GetRoot(),"","","",dataPrefix,dataSuffix,horLeftSpace,horRightSpace,vertSpace,fillerElem);
    }
    else{
      std::cout<<"EMPTY TREE"<<std::endl;  
    } 
};


template void PrintTreeHorizontaly<int>(
    BinaryTree<int>* tree,
    const std::string& dataPrefix,
    const std::string& dataSuffix ,
    const std::string& horLeftSpace ,
    const std::string& horRightSpace ,
    const char vertSpace ,
    const char fillerElem 
);
template void PrintTreeHorizontaly<float>(
    BinaryTree<float>* tree,
    const std::string& dataPrefix ,
    const std::string& dataSuffix ,
    const std::string& horLeftSpace ,
    const std::string& horRightSpace ,
    const char vertSpace ,
    const char fillerElem
);
template void PrintTreeHorizontaly<double>(
    BinaryTree<double>* tree,
    const std::string& dataPrefix ,
    const std::string& dataSuffix ,
    const std::string& horLeftSpace ,
    const std::string& horRightSpace ,
    const char vertSpace,
    const char fillerElem 
);