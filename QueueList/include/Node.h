#define NODE_H
#include<iostream>

using namespace std;

template<class T>
class Node
{
private:
    /** Tipo di data generico */
    T data;
    /** Puntatori che puntano al nodo successivo e precedente */
    Node<T> *prev, *next;


public:
    /** Costruttore che riceve in ingresso un valore generico*/
    Node(T value)
    {
        this->data=value;
        prev=next=NULL;
    }

    /** Costruttore di default per un Node vuoto*/
    Node()
    {
        prev=next=NULL;
    }

    /** Metodo per impostare il Node successivo*/
    void setNext(Node<T> *next)
    {
        this->next = next;
    }

    /** Metodo per impostare il Node precedente*/
    void setPrev(Node<T> *prev)
    {
        this->prev=prev;
    }

    /** Metodo che ritorna il puntatore al Node successivo */
    Node<T> *getNext()
    {
        return next;
    }

    /** Metodo che ritorna il puntatore al Node precedente */
    Node<T> *getPrev()
    {
        return prev;
    }

    /** Metodo che restituisce il valore del Node*/
    T getData()
    {
        return data;
    }

    /** Overriding dell <<operator per stampare i dati dei nodi tramite cout */
    friend ostream& operator<<(ostream& out, Node<T>& n)
    {
        out<<n.getData()<<endl;
        return out;
    }

    /** Decostruttore per eliminare il nodo*/
    ~Node()
    {
        delete data;
        delete prev;
        delete next;
    }


};

