#include<iostream>
#include"queue.h"

using namespace std;

int main()
{
    queue<int> *q;
    int toDeq=0;
    q = new queue<int>(5);
    q->enqueue(10);
    q->enqueue(5);
    toDeq=q->search(5);
    //q->dequeu(toDeq);
    q->enqueue(11);
    q->enqueue(3);
    q->enqueue(6);
    toDeq=q->search(11);
    //q->dequeu(toDeq);
    //q->dequeu();
    //q->dequeu();
    cout<<*q<<endl;
    delete q;
    return 0;
}
