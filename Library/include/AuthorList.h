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
            head->setNext(toAdd);
            tail->setPrev(toAdd);
            toAdd->setNext(tail);
            toAdd->setPrev(head);
        }
        else
        {
            toAdd->setPrev(tail->getPrev());
            toAdd->setNext(tail);
            tail->getPrev()->setNext(toAdd);
            tail->setPrev(toAdd);
        }

    }

    /** Metodo che si occupa di cercare all'interno della lista degli autori, un autore in base ad un nome e un cognome passati per valore, l'algoritmo consiste nello scorrere tutta la lista fino a quando
        non si raggiunge la tail o non si è trovato un autore i cui nome e cognome corrispondono ai dati passati per effetturare la ricerca, se l'autore è stato trovato si restituisce il puntatore ad esso
        nel caso contrario si resituisce NULL*/
    Node<Author> *search(string name, string surname)
    {
        Node<Author> *cur = head->getNext();
        Author curr = cur->getValue();

        try//ho utilizzato il try catch per provare a catturare un eccezzione ma senza risultato, la cosa che è cambiata è che con il try catch il programma mi esegue completamente senza essere interrotto dall errore che compariva
        {while(cur != tail && (cur->getValue().getName() != name || cur->getValue().getSurname() != surname) )
        {
            cur = cur->getNext();
        }
        if(cur==tail)throw "author not found";
       // cout<<curr<<endl;
        return cur;
        }
        catch(const char* e)
        {
            cerr<<e<<endl;
        }
    }

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
        return out;
    }


};

#endif // AUTHORLIST_H
