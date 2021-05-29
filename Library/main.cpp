#include <iostream>
#include <sstream>
#include "Library.h"
#include "AuthorList.h"

using namespace std;

static void load(Library& listL,AuthorList& listA, string booksFile, string authorFile)
{
    ifstream ifsB(booksFile,ifstream::in);
    ifstream ifsA(authorFile,ifstream::in);
    while(ifsA.good())
    {
        Author newA;
        ifsA>>newA;
        listA.ins(newA);
    }

    while(ifsB.good())
    {
        Book newB;
        newB.setList(listA);
        ifsB>>newB;
        listL.ins(newB);
    }
}

int main()
{

    AuthorList aList;
    Library lib;
    load(lib, aList, "books.txt", "authors.txt");
    cout<<lib;
    /*Node<Author> *a =aList.search("Sandro","Ladro");
    Author found = a->getValue();
    cout<<endl<<found;*/
    return 0;
}
