#ifndef NODO_H
#define NODO_H
#include<iostream>
#include<sstream>

using namespace std;

template<class T>
class Nodo
{
public:
    Nodo<T>(T data): data(data), next(NULL), prev(NULL) {}
    Nodo<T>(): next(NULL), prev(NULL) {};

    T getData()
    {
        return data;
    }
    void setData(T val)
    {
        data = val;
    }
    Nodo<T>* getNext()
    {
        return next;
    }
    void setNext(Nodo<T>* val)
    {
        next = val;
    }
    Nodo<T>* getPrev()
    {
        return prev;
    }
    void setPrev(Nodo<T>* val)
    {
        prev = val;
    }

    void print()
    {
        cout<<data;
    }

private:
    T data;
    Nodo<T>* next;
    Nodo<T>* prev;
};

#endif // NODO_H
