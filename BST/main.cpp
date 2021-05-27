#include <iostream>
#include"BST.h"

using namespace std;

int main()
{
    BST<int> *tree = new BST<int>();
    tree->ins(10);
    tree->ins(15);
    tree->ins(5);
    tree->postOrder();
    tree->inOrder();
    tree->preOder();
    tree->canc(10);
    tree->postOrder();
    tree->inOrder();
    tree->preOder();
}
