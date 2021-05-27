#ifndef NODE_H
#define NODE_H

using namespace std;

template<class T>
class Node
{
private:
    /** Puntatori che puntano al figlio sinistro e destro e al parent */
    Node<T> *left, *right, *parent;
    T key;


public:
    /** Costruttore che riceve in ingresso una key di tipo generico*/
    Node<T>(T key)
    {
        this->key=key;
        left = NULL;
        right = NULL;
        parent = NULL;
    }

    /** Metodo per impostare il figlio sinistro*/
    void setLeft(Node<T> *left)
    {
        this->left=left;
        return;
    }

    /** Metodo per impostare il figlio detro*/
    void setRight(Node<T> *right)
    {
        this->right=right;
        return;
    }

    /** Metodo per impostare il parent*/
    void setParent(Node<T> *parent)
    {
        this->parent=parent;
        return;
    }

    /** Metodo per impostare la key*/
    void setKey(T key)
    {
        this->key=key;
    }

    /** Metodo che ritorna il puntatore al figlio sinistro */
    Node<T> *getLeft()
    {
        return left;
    }


    /** Metodo che ritorna il puntatore al figlio destro */
    Node<T> *getRight()
    {
        return right;
    }


    /** Metodo che ritorna il puntatore al parent */
    Node<T> *getParent()
    {
        return parent;
    }

    /** Metodo che ritorna la key */
    T getKey()
    {
        return key;
    }

    /** Overriding dell operatore << del cout  per stampare un ogetto di tipo Node<T> stampando la key del nodo */
    friend ostream& operator<<(ostream& out, Node<T> &n)
    {
        out<<n.getKey();

        return out;
    }


};

#endif // NODE_H
