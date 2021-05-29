#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include"Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Library
{
private:
    Node<Book> *head, *tail;

public:
    Library()
    {
        head = new Node<Book>();
        tail = new Node<Book>();
        head->setNext(tail);
        tail->setPrev(head);
    }

    void ins(Book value)
    {
        Node<Book> *toAdd = new Node<Book>(value);

        if(head->getNext()==tail && tail->getPrev()==head)
        {
            head->setNext(toAdd);
            tail->setPrev(toAdd);
            toAdd->setNext(tail);
            toAdd->setPrev(head);
        }
        else
        {
            toAdd->setPrev(tail->getPrev());
            toAdd->setNext(tail);
            tail->getPrev()->setNext(toAdd);
            tail->setPrev(toAdd);
        }

        return;
    }

    void printList()
    {
        Node<Book> *current = head->getNext();
        while(current!=tail)
        {
            Book tmp= current->getValue();
            cout<<tmp;
            current = current->getNext();
        }
        return;
    }


    Node<Book> *getHead()
    {
        return head;
    }

    Node<Book> *getTail()
    {
        return tail;
    }


    friend ostream& operator<<(ostream& out,Library& list)
    {
        list.printList();
    }


};

#endif // LIBRARY_H
