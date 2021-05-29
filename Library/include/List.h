#ifndef LIST_H
#define LIST_H

#include"Author.h"

template<class T>
class List
{
 private:
    T *head, *tail;
    int nElements;


 public:
    /** Default constructor */
    List<T>()
    {
      head = new T();
      tail = new T();
      head->setNext(tail);
      tail->setPrev(head);
    }

    void insert(T *toAdd)
    {

        if(head->getNext()==tail && tail->getPrev()==head)
        {
            nElements++;
            head->setNext(toAdd);
            tail->setPrev(toAdd);
            toAdd->setNext(tail);
            toAdd->setPrev(head);
        }
        else
        {
            nElements++;
            toAdd->setPrev(tail->getPrev());
            toAdd->setNext(tail);
            tail->getPrev()->setNext(toAdd);
            tail->setPrev(toAdd);
        }

    }

};

#endif // LIST_H
