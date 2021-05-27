#define QUEUE_H
#include"Node.h"

using namespace std;

template<class T>
class Queue
{
private:
    /**Puntatori di tipo Node ai nodi che rappresentano la testa
    e la coda della Queue*/
    Node<T> *head, *tail;
    /**Int che definisce la lunghezza attuale della Queue*/
    int length;

public:
    /** Costruttore di defaul senza parametri in ingresso che setta head e tail come due nodi vuoti,
     dove il successivo della Head punta alla Tail e
     il precedente della Tail punta alla Head */
    Queue()
    {
        head = new Node<T>();
        tail = new Node<T>();
        head->setNext(tail);
        tail->setPrev(head);
    }

    /**Metodo che ritorna 1 se la Queue è vuota cioè il successivo della Head è tail
    e il precedente della tail è Head in caso contrario ritorna 0*/
    bool isEmpty()
    {
        if(head->getNext()==tail && tail->getPrev()==head)
            return 1;
        else return 0;
    }

    /** Metodo che ritorna il puntatore alla Head */
    Node<T> *getHead()
    {
        return head;
    }

    /** Metodo che ritorna il puntatore alla Tail */
    Node<T> *getTail()
    {
        return tail;
    }

    /** Metodo che inserisce i nodi in coda(Queue)
        il metodo si suddivide in due casi gestiti dalla condizione di isEmpty()
        nel caso la Queue sia vuota allora inserisco il nodo e aggiorno i link
        nel caso in cui non sia vuota allora inserisco il nodo in coda
    */
    void insertTail(T data)
    {
        Node<T> *toIns = new Node<T>(data);
        if(this->isEmpty())
        {
            toIns->setNext(tail);
            toIns->setPrev(head);
            head->setNext(toIns);
            tail->setPrev(toIns);

            length++;
        }
        else
        {
            toIns->setNext(tail);
            toIns->setPrev(tail->getPrev());
            tail->getPrev()->setNext(toIns);
            tail->setPrev(toIns);
            length++;
        }
    }

    /** Metodo che gestisce la stampa dei nodi
        la stampa parte dal primo elemento fino a quando non si raggiunge la Tail che non viene stampata
    */
    void printQ()
    {
        Node<T> *iter=head->getNext();
        while(iter!=tail)
        {
            cout<<*iter;
            iter=iter->getNext();
        }
    }

    /** Metodo che si occupa della dequeue impostando il successivo di head come il successivo del nodo da rimuovere dalla coda
    e il precedente del successivo del nodo da riumere come head */
    void dequeue()
    {
        Node<T> *toDeq=head->getNext();
        head->setNext(toDeq->getNext());
        toDeq->getNext()->setPrev(head);
    }

    /**Overriding dell <<operator per stampare i dati dei nodi tramite cout della coda*/
    friend ostream& operator<<(ostream& out, Queue<T>& q)
    {
        q.printQ();
    }


    /** Decostruttore dove elimino head, tail e length */
    ~Queue()
    {
        delete head;
        delete tail;
        delete length;
    }

};

