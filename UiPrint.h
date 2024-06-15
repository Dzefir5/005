#pragma once
#include <string>
#include <iostream>
#include <string.h>
#include "Tree.h"

void PrintTypes();

void PrintFuncTree();
void Delimeter(int count , char symbol);
void Delimeter(int count , std::string string);

template <typename T>
bool cmp (T a, T b);
template <typename T>
void TreeInsert();

template <typename T>
void TreeErase();

template <typename T>
void TreeSearch();
template <typename T>
void TreeMax();
template <typename T>
void TreeMin();
template <typename T>
void TreeGetSubTree();

template <typename T>
void TreeTravers();

void UiMain();

