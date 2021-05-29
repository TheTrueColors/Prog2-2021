#ifndef AUTHORLIST_H
#define AUTHORLIST_H

#include "Author.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

class AuthorList
{
private:
    Node<Author> *head, *tail;

public:
    /** Default constructor */
    AuthorList()
    {
        head = new Node<Author>();
        tail = new Node<Author>();
        head->setNext(tail);
        tail->setPrev(head);
    }

    void ins(Author value)
    {
        Node<Author> *toAdd = new Node<Author>(value);
        if(head->getNext()==tail && tail->getPrev()==head)
        {
            cout<<*toAdd;
            head->setNext(toAdd);
            tail->setPrev(toAdd);
            toAdd->setNext(tail);
            toAdd->setPrev(head);
        }
        else
        {
            cout<<*toAdd;
            toAdd->setPrev(tail->getPrev());
            toAdd->setNext(tail);
            tail->getPrev()->setNext(toAdd);
            tail->setPrev(toAdd);
        }

        return;
    }

    /*Author *search(string name, string surname)
    {
        Author current = head->getNext()->getValue();
        Node<Author> *tmp = head->getNext();
        while(tmp!=tail && (current.getName()==name || current.getSurname()==surname))
        {
            tmp=tmp->getNext();
        }
        return &current;
    }*/

    Node<Author> *getHead()
    {
        return head;
    }

    Node<Author> *getTail()
    {
        return tail;
    }

    void printList()
    {
        Node<Author> *current = head->getNext();
        while(current!=tail)
        {
            Author tmp= current->getValue();
            cout<<tmp;
            current = current->getNext();
        }
    }


    friend ostream& operator<<(ostream& out,AuthorList& list)
    {
        list.printList();
    }


};

#endif // AUTHORLIST_H
