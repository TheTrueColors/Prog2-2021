#include <iostream>
#include"Stack.h"

using namespace std;

int main()
{
    Stack<int> *s;
    int toPop=0;
    s = new Stack<int>(5);
    s->push(10);
    s->push(5);
    toPop=s->search(5);
    s->pop(toPop);
    s->push(11);
    s->push(3);
    s->push(6);
    toPop=s->search(11);
    s->pop(toPop);
    //s->pop();
    //s->pop();
    cout<<*s<<endl;
    delete s;
    return 0;
}
