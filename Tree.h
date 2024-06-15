#pragma once
#include "Complex.h"
#include "Sequence.h"
#include "MySwap.h"


//вынести в cpp файл

//вынести в абстрактный с наследников в tree

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;
public:
    TreeNode()
    {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(T item)
    {
        this->data = item;
        this->left = nullptr;
        this->right = nullptr;
    }
    TreeNode(TreeNode<T> *item)
    {
        this->data = item->data;
        this->left = item->left;
        this->right = item->right;
    }
    TreeNode(TreeNode<T> &item)
    {
        this->data = item.data;
        this->left = item.left;
        this->right = item.right;
    }
    T GetData()
    {
        return this->data;
    }
    TreeNode<T> *GetLeft()
    {
        return this->left;
    }
    TreeNode<T> *GetRight()
    {
        return this->right;
    }
};

template <typename T> 
bool defaultCompare(T a,T b){
    return a < b;
}

template <typename T> 
class BinaryTree
{
private:
    int size =0;
    TreeNode<T>* root=nullptr;
    bool (*comparator)(T ,T ) = &defaultCompare;

    void swap(BinaryTree<T>& toSwap){
        MySwap(root,toSwap.root);
        MySwap(size,toSwap.size);
    }

    void funcMap(TreeNode<T>* startRoot, T (*func)(T))
    {
        if (startRoot == nullptr)
        {
            return;
        }
        funcMap(startRoot->left, func);
        funcMap(startRoot->right, func);
        startRoot->data = func(startRoot->data);
    }
    
    void funcWhere(TreeNode<T>* startRoot, bool (*func)(T))
    {
        if (startRoot == nullptr) return;
        funcWhere(startRoot->left, func);
        funcWhere(startRoot->right, func);
        if (func(startRoot->data) == false)
        {
            this->erase(startRoot->data);
        }
    }
    
    void funcReduce(TreeNode<T>* startRoot, T(*func)(T, T), T* base)
    {
        if (startRoot == nullptr) return;
        funcReduce(startRoot->left, func, base);
        funcReduce(startRoot->right, func, base);
        *base = func(startRoot->data, *base);
    }

    TreeNode<T>* insertHelper(TreeNode<T>* startRoot, T value)
    {
        if (value == startRoot->data) return startRoot;
        if (comparator(value,startRoot->data))
        {   
            if(startRoot->left == nullptr){
                startRoot->left= new TreeNode<T>(value);
                return startRoot->left;
            }
            return insertHelper(startRoot->left, value);
        }
        if ( !(comparator(value,startRoot->data)) )
        {   
            if(startRoot->right == nullptr){
                startRoot->right= new TreeNode<T>(value);
                return startRoot->right;
            }
            return insertHelper(startRoot->right, value);
        }
        return nullptr;
    }

    TreeNode<T>* searchHelper(TreeNode<T>* startRoot, T value)
    {
        if (startRoot == nullptr || startRoot->data == value)
        {
            return startRoot;
        }
        if (comparator(value,startRoot->data))
        {
            return searchHelper(startRoot->left, value);
        }
        if (!comparator(value,startRoot->data))
        {
            return searchHelper(startRoot->right, value);
        }
    }

    TreeNode<T>* deleteHelper(TreeNode<T>* startRoot, T value)
    {
        if (startRoot == nullptr)
        {
            return startRoot;
        }
        if (comparator(value,startRoot->data))
        {
            startRoot->left=  deleteHelper(startRoot->left, value);
        }
        else if (!comparator(value,startRoot->data) && value!=startRoot->data)
        {
            startRoot->right = deleteHelper(startRoot->right, value);
        }
        else if (startRoot->left != nullptr && startRoot->right != nullptr)
        {
            startRoot->data = minimum(startRoot->right)->data;
            startRoot->right = deleteHelper(startRoot->right, startRoot->data);
        }
        else
        {
            size--;
            if (startRoot->left != nullptr)
            {
                startRoot = startRoot->left;
            }
            else if (startRoot->right != nullptr)
            {
                startRoot = startRoot->right;
            }
            else
            {
                startRoot = nullptr;
            }
        }
        return startRoot;
    }

    void copyHelper(TreeNode<T>* toCopy,TreeNode<T>* Result) 
    {
        if(toCopy->left!=nullptr){
            Result->left= new TreeNode<T>(toCopy->left);
            copyHelper(toCopy->left,Result->left);
        }
        if(toCopy->right!=nullptr){
            Result->right= new TreeNode<T>(toCopy->right);
            copyHelper(toCopy->right,Result->right);
        }
    }
    void getSubTreeSize(TreeNode<T>* node,int* size) 
    {   
        if(node == nullptr){
            return;
        }
        (*size)++;
        if(node->left!=nullptr){
            getSubTreeSize(node->left,size);
        }
        if(node->right!=nullptr){
            getSubTreeSize(node->right,size);
        }
    }
    TreeNode<T>* maximum(TreeNode<T>* startRoot)
    {   
        if (startRoot->left!= nullptr)
        {
            if( !comparator(startRoot->left->data,startRoot->data) ){
                return maximum(startRoot->left);
            }
        }
        if (startRoot->right!= nullptr)
        {
            if( !comparator(startRoot->right->data,startRoot->data) ){
                return maximum(startRoot->right);
            }
        }
        return startRoot;
    }

    TreeNode<T>* minimum(TreeNode<T>* startRoot)
    {   
        if (startRoot->left!= nullptr)
        {
            if( comparator(startRoot->left->data,startRoot->data) ){
                return minimum(startRoot->left);
            }
        }
        if (startRoot->right!= nullptr)
        {
            if( comparator(startRoot->right->data,startRoot->data) ){
                return minimum(startRoot->right);
            }
        }
        return startRoot;
    }

    void deleteTree(TreeNode<T>* node)
    {
        if (node == nullptr) return;
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
public:
    BinaryTree():root(nullptr),size(0){
        
    }
    BinaryTree(bool (*func)(T,T)):root(nullptr),size(0),comparator(func){
        
    }

    BinaryTree(T* array , int count):root(nullptr),size(0){
        for(int i=0; i< count ; i++){
            this->insert(array[i]);
        }
    }
    BinaryTree(T* array , int count,bool (*func)(T,T)):root(nullptr),size(0),comparator(func){
        for(int i=0; i< count ; i++){
            this->insert(array[i]);
        }
    }
    BinaryTree(const BinaryTree<T>& tree):root(nullptr),size(0),comparator(tree.comparator){
        this->root = new TreeNode<T>(tree.root);
        size = tree.size;
        copyHelper(tree.root,this->root);
    }

    BinaryTree(const Sequence<T>& seq):root(nullptr),size(0){
        for(int i=0; i< seq.GetLength() ; i++){
            this->insert(seq.Get(i));
        }
    }
    BinaryTree(const Sequence<T>& seq,bool (*func)(T,T)):root(nullptr),size(0),comparator(func){
        for(int i=0; i< seq.GetLength() ; i++){
            this->insert(seq.Get(i));
        }
    }

    int GetSize() 
    {
        return this->size;
    }
    TreeNode<T>* GetRoot(){
        return root;
    }
    TreeNode<T>* max() 
    {
        return this->maximum(this->GetRoot());
    }

    TreeNode<T>* min() 
    {
        return this->minimum(this->GetRoot());
    }

    TreeNode<T>* insert( T value)
    {   
        if(root == nullptr){
            root = new TreeNode<T>(value);
            size++;
            return root;
        }
        TreeNode<T>* buf = this->insertHelper(root,value);
        if(buf==nullptr){
            return buf;
        }
        size++;
        return buf;
    }

    TreeNode<T>* erase(T value){
        if(root == nullptr){
            return root;
        }
        return this->deleteHelper(root,value);
    }

    bool contains(T value){
        return this->search(value)!=nullptr;
    }

    TreeNode<T>* search(T value) 
    {
        if(root == nullptr){
            return root;
        }
        return this->searchHelper(root,value);
    }
    
    BinaryTree<T>* getSubTree(T value) 
    {
        BinaryTree<T>* result = new BinaryTree<T>();
        TreeNode<T>* node = this->searchHelper(this->root,value);
        if(node==nullptr){
            delete result;
            return nullptr;
        }
        int ressize=0;
        result->root = new TreeNode<T>(node);
        copyHelper(node,result->root);
        getSubTreeSize(node,&ressize);
        result->size = ressize;
        return result;
    }

    void map(T (*func)(T)) 
    {
        this->funcMap(this->root, func);
    }
    
    BinaryTree<T>& where(bool(*func)(T)) 
    {
        BinaryTree<T>* result = new BinaryTree<T>(*this);
        result->funcWhere(this->root, func);
        return *result;
    }
    
    T reduce(T base ,T (*func)(T, T)) 
    {   
        T result = base;
        this->funcReduce(this->root, func, &result);
        return result;
    }
    BinaryTree<T>& operator=(const BinaryTree<T> &tree){
        BinaryTree<T> result (tree);
        swap(result);
        return *this;
    }

    ~BinaryTree()
    {
        deleteTree(this->root);
    }

};

