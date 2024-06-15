#pragma once
#include <string>
#include "Tree.h"
#include "TreeFuncs.h"

int getType(std::string typeName);
int getFuncTree(std::string funcName);

template <typename T>
BinaryTree<T>& TreeRead(int count);

template <typename T>
BinaryTree<T>& TreeRead(int count,bool (*comparator)(T ,T ));

template<typename T>
void SafeCin(T& input,std::string ErrorMessage="Invalid type of input");