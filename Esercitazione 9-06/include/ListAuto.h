#ifndef LISTAUTO_H
#define LISTAUTO_H
#include<iostream>
#include "Nodo.h"
#include "Auto.h"

using namespace std;

class ListAuto
{
public:
    ListAuto()
    {
        Head = Tail = NULL;
        Nil = new Nodo<Auto>();
    }

    Nodo<Auto>* getHead()const
    {
        return Head;
    }
    void setHead(Nodo<Auto> *val)
    {
        Head = val;
    }
    Nodo<Auto>* getTail()const
    {
        return Tail;
    }
    void setTail(Nodo<Auto> *val)
    {
        Tail = val;
    }
    Nodo<Auto>* getNil()const
    {
        return Nil;
    }
    void setNil(Nodo<Auto> *val)
    {
        Nil = val;
    }

    bool isEmpty()
    {
        return (Head == NULL) && (Tail == NULL);
    }

    /** Funzione per l'inserimento */
    void insert(Auto value)
    {
        Nodo<Auto> * n = new Nodo<Auto>(value);

        if(this->isEmpty())
        {
            n->setNext(Nil);
            n->setPrev(Nil);
            Head = n;
            Tail = n;
            Nil->setNext(Head);
            Nil->setPrev(Tail);
        }
        else
        {

            n->setNext(Head);
            Head->setPrev(n);
            n->setPrev(Nil);
            Nil->setNext(n);
            Head = n;
        }

    }

    void print()
    {
        Nodo<Auto>* cur = Head;

        while(cur!=Nil)
        {
            cur->print();
            cur=cur->getNext();
        }
    }

    Auto getData(Nodo<Auto>* tmp)
    {
        Auto a = tmp->getData();
        return a;
    }

private:
    Nodo<Auto>* Head;
    Nodo<Auto>* Tail;
    Nodo<Auto>* Nil;
};

#endif // LISTAUTO_H
