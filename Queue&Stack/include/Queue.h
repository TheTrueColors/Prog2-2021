#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<sstream>
#include<fstream>
#include "Node.h"

using namespace std;

template<class T>
class Queue
{
public:
    Queue<T>()
    {
        head = tail = NULL;
        nil = new Node<T>();
        len = 0;
    }

    Node<T> *getHead()const
    {
        return head;
    }

    Node<T> *getTail()const
    {
        return tail;
    }

    Node<T> *getNil()const
    {
        return nil;
    }

    bool isEmpty()const
    {
        if(head == NULL && tail == NULL)return 1;
        return 0;
    }

    void enqueue(T key)
    {
        Node<T> *x = new Node<T>(key);
        if(this->isEmpty())
        {
            x->setNext(nil);
            x->setPrev(nil);
            head = x;
            tail = x;
            nil->setPrev(head);
            nil->setNext(tail);
            len++;
        }
        else
        {
            tail->setNext(x);
            x->setNext(nil);
            nil->setPrev(x);
            x->setPrev(tail);
            tail = x;
            len++;
        }

    }

    Node<T> *search(T Key)
    {
        Node<T> *iter = head;
        try{
        while(iter!=nil && iter->getKey()!=Key)
            iter = iter->getNext();

        if(iter!=nil)return iter;
        else throw "Element not found";
        }catch(const char* e)
        {
            cerr<<e<<endl;
            return nil;
        }
    }

    void canc(T Key)
    {
        Node<T> *x = search(Key);
        if(x==nil)return;
        x->getNext()->setPrev(x->getPrev());
        x->getPrev()->setNext(x->getNext());
        len--;
    }

    void deqeueue(ofstream& out)
    {
        head->getNext()->setPrev(nil);
        out<<*head<<endl;
        head = head->getNext();
        len--;
    }

    friend ostream& operator<<(ostream& out, const Queue<T>& q)
    {
     try{
        if(q.getLen()==0)throw "Empty queue";
        Node<T>* cur= q.getHead();
        while(cur!=q.getNil())
        {
            cout<<*cur<<" ";
            cur=cur->getNext();
        }
        cout<<endl;
     }catch(const char* e)
        {
            cerr<<e<<endl;
        }

    return out;
    }

    int getLen()const
    {
        return len;
    }

private:
    Node<T> *head, *tail, *nil;
    int len;


};

#endif // QUEUE_H
