#ifndef BOOK_H
#define BOOK_H

#include "AuthorList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Book
{
private:
    string title;
    int books_stock;
    string genre;
    string nameA, surnameA;
    string published;
    AuthorList aList;

public:
    Book(string title, string nameA, string surnameA, int books_stock, string genre, string published) : title(title), nameA(nameA), surnameA(surnameA), books_stock(books_stock), genre(genre), published(published) {}
    Book() {}

    bool outOfOrder()
    {
        if(books_stock==0)return 1;
        else return 0;
    }

    void setTitle(string title)
    {
        this->title = title;
        return;
    }

    void setGenre(string genre)
    {
        this->genre = genre;
        return;
    }

    void setStock(int stock)
    {
        this->books_stock = stock;
        return;
    }

    void setDate(string date)
    {
        this->published = date;
        return;
    }

    string getTitle()const
    {
        return title;
    }

    string getNameA()const
    {
        return nameA;
    }

    string getSurnameA()const
    {
        return surnameA;
    }

    string getGenre()const
    {
        return genre;
    }

    string getDate()const
    {
        return published;
    }

    int getStock()const
    {
        return books_stock;
    }

    AuthorList getList()const
    {
      return aList;
    }

    void setList(AuthorList &aList)
    {
        this->aList = aList;
    }

    void setSurnameA(string surnameA)
    {
        this->surnameA = surnameA;
    }

    void setNameA(string nameA)
    {
        this->nameA = nameA;
    }


    friend ostream& operator<<(ostream& out,const Book& b)
    {
        cout<<"Book:"<<endl<<"Title: "<<b.getTitle()<<endl<<"Genre: "<<b.getGenre()<<endl<<"Published on: "<<b.getDate()<<endl;
        string name,surname;
        name = b.getNameA();
        surname = b.getSurnameA();
        //cout<<b.aList;
        //cout<<name<<" "<<surname<<endl;
         Node<Author> *a =b.getList().search("Sandro","Ladro");
         //Author found = a->getValue();
         //cout<<found<<endl<<endl;
        return out;
    }



    friend istream& operator>>(istream& in, Book& b)
    {
        string stock,nameA,surnameA,title,date,genre;
        int book_stock;

        getline(in, nameA, '-');
        getline(in, surnameA, '-');
        getline(in, title, '-');
        getline(in, genre,'-');
        getline(in, date, '-');
        getline(in, stock,'\n');
        b.setNameA(nameA);
        b.setSurnameA(surnameA);
        b.setTitle(title);
        b.setGenre(genre);
        b.setDate(date);
        book_stock=stoi(stock);
        b.setStock(book_stock);

        return in;

    }


};


#endif //BOOK_H
