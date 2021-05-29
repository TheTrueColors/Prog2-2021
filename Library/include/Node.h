#ifndef NODE_H
#define NODE_H

template<class T>
class Node
{
    T value;
    Node<T> * prev;
    Node<T> * next;

public:

    Node<T>(T value) : value(value), next(NULL), prev(NULL) {}
    Node<T>() : next(NULL), prev(NULL) {}

    void setValue(T value)
    {
        this->value = value;
    }
    void setPrev(Node<T> *prev)
    {
        this->prev = prev;
    }
    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    T getValue()
    {
        return value;
    }

    Node<T>* getPrev()
    {
        return prev;
    }
    Node<T>* getNext()
    {
        return next;
    }


    friend ostream& operator<<(ostream& out, Node<T>& n)
    {
        T a = n.getValue();
        out <<a;
        return out;
    }


};

#endif // NODE_H
