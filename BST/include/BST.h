#ifndef BST_H
#define BST_H
#include"Node.h"
#include<iostream>

using namespace std;

template<class T>
class BST
{
private:
    Node<T> *root;///Variabile di tipo Node<T> che rappresenta la radice del BST(binary search tree)


    /** Metodo void che si occupa di stampare l'albero secondo una visita postOrder,
        nella quale i nodi dell'abero vengono stampati scorrendo il sotto albero sinistro ,
        il  sottoalbero destro e in fine la root, i sotto alberi vengono attraversati fino a quando non si raggiunge la loro fine cioè un nodo NULL */
    void _postOrder(Node<T> *current)
    {
        if (current != NULL)
        {
            _postOrder(current->getLeft());
            _postOrder(current->getRight());
            cout << *current << " ";
        }
        else return;
    }


    /** Metodo void che si occupa di stampare l'albero secondo una visita preOrder,
        nella quale i nodi dell'abero vengono stampati partedo dalla root per poi scorrere il sottoalbero sinistro e poi
        il sotto albero destro ,i sotto alberi vengono attraversati fino a quando non si raggiunge la loro fine cioè un nodo NULL*/
    void _preOrder(Node<T> *current)
    {
        if (current != NULL)
        {
             cout << *current << " ";
            _preOrder(current->getLeft());
            _preOrder(current->getRight());

        }
        else return;
    }


    /** Metodo void che si occupa di stampare l'albero secondo una visita inOrder,
        nella quale i nodi dell'abero vengono stampati scorrendo il sottoalbero sinistro , la radice e in fine il sottoalbero destro,
        i sotto alberi vengono attraversati fino a quando non si raggiunge la loro fine cioè un nodo NULL */
    void _inOrder(Node<T> *current)
    {
        if (current != NULL)
        {
            _inOrder(current->getLeft());
            cout << *current << " ";
            _inOrder(current->getRight());

        }
        else return;
    }

    /** Metodo che restituisce il puntatore al nodo che contiene la key da trovare(se esiste), oppure un riferimento a NULL se il nodo da trovare non esiste,
        la ricerca viene effettuta in modo ricorsivo, se la key del nodo in cui siamo arrivati è uguale alla key da trovare allora restituiamo questo nodo,
        in caso contrario si fanno due confronti per vedere se dobbiamo effettuare la ricerca nel sotto albero sinistro se la key da trovare è più piccola o nel sottoalbero destro se più grande
        se la key non viene trovata allora restituiamo NULL*/
    Node<T> *_search(Node<T> *tmp,T key)
    {
            if(tmp->getKey()== key)
            {
                return tmp;
            }
            else if(key<tmp->getKey())
            {
                _search(tmp->getLeft(),key);
            }
            else if(key>=tmp->getKey())
            {
                _search(tmp->getRight(),key);
            }

        return NULL;
    }

    /** Metodo che restituisce il puntatore ad un nodo (il max) cioè il nodo che si trova all' estrema destra, tutto effetuato in modo ricorsivo  */
    Node<T> *_getMax(Node<T> *x)
    {
        if (!x) return NULL;
        if (!x->getRight()) return x;
        return _getMax(x->getRight());
    }

    /** Metodo che restituisce il puntatore ad un nodo (il min) cioè il nodo che si trova all' estrema sinistra, tutto effetuato in modo ricorsivo  */
    Node<T> *_getMin(Node<T> *x)
    {
        if (!x) return NULL;
        if (!x->getLeft()) return x;
        return _getMin(x->getLeft());
    }

    /** Metodo che restituisce il puntatore ad un nodo, se il sottoalbero destro esiste allora si prende il min di questo sotto albero tutto effetuato in modo ricorsivo
        se il sottoalbero destro non esiste allora si prende il parent */
    Node<T> *_successor(Node<T> *x)
    {
        if (!x) return NULL;
        if (x->getRight())
            return _getMin(x->getRight());
        Node<T>* tmp = x->getParent();
        while (tmp && tmp->getRight() == x)
        {
            x = tmp;
            tmp = tmp->getParent();
        }
        return tmp;
    }

    /** Metodo che restituisce il puntatore ad un nodo, se il sottoalbero sinistr esiste allora si prende il max di questo sotto albero tutto effetuato in modo ricorsivo
        se il sottoalbero sinistr non esiste allora si prende il parent fino a quando la key non è uguale o maggiore della key del nodo su cui stiamo richiamando il metodo */
    Node<T>* _predecessor(Node<T>* x)
    {
        if (!x) return NULL;
        if (x->getLeft())
            return _getMax(x->getLeft());
        Node<T>* tmp = x->getParent();
        while (tmp && tmp->getKey() >= x->getKey())
            tmp = tmp->getParent();
        return tmp;
    }


    /** Metodo void, che si occupa di eliminare un nodo dall'albero,
        tale metodo si suddivide in 3 casi:
        1° nel caso in cui il nodo da cancellare ha entrambi i figli allora si sostituisce tale nodo con il suo successore.
        2° nel caso in cui esiste solo un figlio si controlla se il nodo da eliminare è la root in questo caso si sostituisce con il figlio, se non è la root
           in base al figlio che esiste  lo si mette come left o right del parent del nodo da cancellare.
        3° nel caso in cui il nodo da elimare non esiste.
         */
    void _canc(T key)
    {
        Node<T>* toDel = _search(root,key);
        if (!toDel) return;
        if (toDel->getLeft() && toDel->getRight()) {
            Node<T>* tmp = _successor(toDel);
            T v = toDel->getKey();
            toDel->setKey(tmp->getKey());
            tmp->setKey(v);
            toDel = tmp;
        }
        Node<T>* tmp = toDel->getLeft();
        if (!tmp) tmp = toDel->getRight();
        Node<T>* p = toDel->getParent();
        if (!p) root = tmp;
        else {
            if (p->getLeft() == toDel)
                p->setLeft(tmp);
            else p->setRight(tmp);
        }
        if (tmp) tmp->setParent(p);
    }

public:
    /** Costruttore di defaul */
    BST<T>()
    {
        root = NULL;
    }

    /** Funzione per l'inserimento di un nodo tramite passaggio di una chiave di tipo generico T
        se l'albero è vuoto allora il nodo creato diventerà la root,
        nel caso in cui l'albero non sia vuoto, allora si farà un confronto per vedere se il nuovo nodo deve essere inserito nel sottoalbero destro o nel sottoalbero sinistro
     */
    void ins(T key)
    {
        Node<T> *newN=new Node<T>(key);
        Node<T> *tmp=root;
        Node<T> *p=NULL;
        while(tmp!=NULL)
        {
            p=tmp;
            if(key <= tmp->getKey()) tmp=tmp->getLeft();
            else tmp=tmp->getRight();
        }
        if(!p) root=newN;
        else
        {
            newN->setParent(p);
            if(key <= p->getKey())p->setLeft(newN);
            else p->setRight(newN);
        }

        return;

    }

    void postOrder()
    {
        cout<<"PostOrder: ";
        _postOrder(root);
        cout<<endl;
        return;
    }

    void preOder()
    {
        cout<<"PreOrder: ";
        _preOrder(root);
        cout<<endl;
        return;
    }

    void inOrder()
    {
        cout<<"InOrder: ";
        _inOrder(root);
        cout<<endl;
        return;
    }

    void canc(T key)
    {
        _canc(key);
        return;
    }

};

#endif // BST_H
