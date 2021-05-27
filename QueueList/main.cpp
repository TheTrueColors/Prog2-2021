#include <iostream>
#include"Queue.h"

using namespace std;

int main()
{
    Queue<int> *coda=new Queue<int>();
    coda->insertTail(5);
    coda->insertTail(2);
    coda->insertTail(10);
    coda->insertTail(4);
    coda->insertTail(100);
    coda->insertTail(1);
    //coda->dequeue();

    cout<<*coda;
}
