#ifndef NODE_H
#define NODE_H

#include<sstream>

using namespace std;

template<class T>
class Node
{
    public:
        Node<T>(T newKey): key(newKey), next(NULL), prev(NULL) {}
        Node<T>(): Node(0){}

        void setNext(Node<T> *next)
        {
          this->next = next;
        }

        void setPrev(Node<T> *prev)
        {
          this->prev = prev;
        }

        Node<T> *getNext()const
        {
            return next;
        }

        Node<T> *getPrev()const
        {
            return prev;
        }

        T getKey()const
        {
           return key;
        }


        friend ostream& operator<<(ostream& out, const Node<T>& x)
        {
            out<<x.getKey();
            return out;
        }

    private:
        Node<T> *next, *prev;
        T key;
};

#endif // NODE_H
