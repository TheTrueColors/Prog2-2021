#ifndef LISTMOTO_H
#define LISTMOTO_H
#include<iostream>
#include "Nodo.h"
#include "Moto.h"

using namespace std;

class ListMoto
{
public:
    ListMoto()
    {
        Head = Tail = NULL;
        Nil = new Nodo<Moto>();
    }

    Nodo<Moto>* getHead()const
    {
        return Head;
    }
    void setHead(Nodo<Moto> *val)
    {
        Head = val;
    }
    Nodo<Moto>* getTail()const
    {
        return Tail;
    }
    void setTail(Nodo<Moto> *val)
    {
        Tail = val;
    }
    Nodo<Moto>* getNil()const
    {
        return Nil;
    }
    void setNil(Nodo<Moto> *val)
    {
        Nil = val;
    }

    bool isEmpty()
    {
        return (Head == NULL) && (Tail == NULL);
    }

    /** Funzione per l'inserimento */
    void insert(Moto value)
    {
        Nodo<Moto> * n = new Nodo<Moto>(value);

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
        Nodo<Moto>* cur = Head;

        while(cur!=Nil)
        {
            cur->print();
            cur=cur->getNext();
        }
    }

    Moto getData(Nodo<Moto>* tmp)
    {
        Moto m = tmp->getData();
        return m;
    }

private:
    Nodo<Moto>* Head;
    Nodo<Moto>* Tail;
    Nodo<Moto>* Nil;
};

#endif // LISTMOTO_H
