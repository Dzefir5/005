
#include "Tree.h"
#include <assert.h>


int forMapFunc(int a){
    return a*2;
}
bool forFuncWhere(int a){
    return a<5;
}
int forReduceFunc(int a,int b){
    return a+b;
}

bool cmp(int a , int b){
    return a > b;
}
void testTreeFunc()
{
    int a[] = {1,2,3,4,5,8};
    BinaryTree<int> test1 = BinaryTree<int>(a,6);
    BinaryTree<int> test = BinaryTree<int>(test1);
    assert(test.GetSize() == 6);
    for(int i =0;i<6;i++){
        assert(test.contains(a[i]));
    }
}

void testMapFunc()
{
    int a[] = {1,2,3,4,5,8};
    BinaryTree<int> test = BinaryTree<int>(a,6);
    assert(test.GetSize() == 6);
    for(int i =0;i<6;i++){
        assert(test.contains(a[i]));
    }
    test.map(&forMapFunc);
    assert(test.GetSize() == 6);
    for(int i =0;i<6;i++){
        assert(test.contains(2*a[i]));
    }
}

void testWhereFunc()
{
    int a[] = {1,2,3,4,5,8};
    BinaryTree<int> test = BinaryTree<int>(a,6,&cmp);
    assert(test.GetSize() == 6);
    for(int i =0;i<6;i++){
        assert(test.contains(a[i]));
    }
    assert(test.GetSize() == 6);
    BinaryTree<int> test1 = test.where(&forFuncWhere);
    std::cout<<test1.GetSize() << std::endl;
    assert(test1.GetSize() == 4);
    for(int i =0;i<6;i++){
        if(forFuncWhere(a[i])){
            assert(test1.contains(a[i]));
        }else{
            assert( !test1.contains(a[i]));
        }
    }
}

void testReduceFunc()
{
    int a[] = {1,2,3,4,5,8};
    BinaryTree<int> test = BinaryTree<int>(a,6);
    assert(test.GetSize() == 6);
    for(int i =0;i<6;i++){
        assert(test.contains(a[i]));
    }
    int base =0;
    int result = test.reduce(base,&forReduceFunc);
    assert(result == 23);
}
