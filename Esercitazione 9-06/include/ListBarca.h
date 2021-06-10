#ifndef LISTBARCA_H
#define LISTBARCA_H
#include<iostream>
#include "Nodo.h"
#include "Barca.h"

using namespace std;

class ListBarca
{
public:
    ListBarca()
    {
        Head = Tail = NULL;
        Nil = new Nodo<Barca>();
    }

    Nodo<Barca>* getHead()const
    {
        return Head;
    }
    void setHead(Nodo<Barca> *val)
    {
        Head = val;
    }
    Nodo<Barca>* getTail()const
    {
        return Tail;
    }
    void setTail(Nodo<Barca> *val)
    {
        Tail = val;
    }
    Nodo<Barca>* getNil()const
    {
        return Nil;
    }
    void setNil(Nodo<Barca> *val)
    {
        Nil = val;
    }

    bool isEmpty()
    {
        return (Head == NULL) && (Tail == NULL);
    }

    /** Funzione per l'inserimento */
    void insert(Barca value)
    {
        Nodo<Barca> * n = new Nodo<Barca>(value);

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
        Nodo<Barca>* cur = Head;

        while(cur!=Nil)
        {
            cur->print();
            cur=cur->getNext();
        }
    }

    Barca getData(Nodo<Barca>* tmp)
    {
        Barca b = tmp->getData();
        return b;
    }

private:
    Nodo<Barca>* Head;
    Nodo<Barca>* Tail;
    Nodo<Barca>* Nil;
};

#endif // LISTBARCA_H
