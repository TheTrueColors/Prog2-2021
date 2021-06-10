#ifndef LISTA_H
#define LISTA_H


class Lista
{
    public:
        Lista() {}

        T* Getdata() { return data; }
        void Setdata(T* val) { data = val; }
        Node<T>* Gettail() { return tail; }
        void Settail(Node<T>* val) { tail = val; }
        Node<T>* Gethead() { return head; }
        void Sethead(Node<T>* val) { head = val; }
        Node<T>* Getnil() { return nil; }
        void Setnil(Node<T>* val) { nil = val; }

    protected:

    private:
        Node<T>* data;
        Node<T>* tail;
        Node<T>* head;
        Node<T>* nil;
};

#endif // LISTA_H
