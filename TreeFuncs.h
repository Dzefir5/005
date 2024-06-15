#pragma once
#include "Tree.h"


template <typename T> 
void PrintTreeFormat(TreeNode<T> *elem, int* format, int format_size =3 );

template <typename T> 
void WriteTreeFormat(TreeNode<T> *node,  int* format, int format_size=3,T* array = nullptr , int* index = nullptr  );

template <typename T> 
void WriteTreeTraverse(BinaryTree<T>& tree, int* format,int format_size=3,T* array = nullptr);

template <typename T> 
void PrintTreeTraverse(BinaryTree<T>& tree, int* format,int format_size =3 );


template <typename T>
void printTreeHelper
    (
        TreeNode<T>* node,
        const std::string& rightPrefix = "",
        const std::string& centerPrefix = "",
        const std::string& leftPrefix = "",
        const std::string& dataPrefix = "[ ",
        const std::string& dataSuffix = " ]",
        const std::string& horLeftSpace = "L---->",
        const std::string& horRightSpace = "R---->",
        const char vertSpace = '|',
        const char fillerElem = ' '
    ) ;

template <typename T>
void PrintTreeHorizontaly(
    BinaryTree<T>* tree,
    const std::string& dataPrefix = "[ ",
    const std::string& dataSuffix = " ]",
    const std::string& horLeftSpace = "L---->",
    const std::string& horRightSpace = "R---->",
    const char vertSpace = '|',
    const char fillerElem = ' '
);