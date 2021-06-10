#include <iostream>
#include "ListAuto.h"
#include "ListMoto.h"
#include "ListBarca.h"
#include "Tree.h"
#include <sstream>
#include <thread>
#include <fstream>


using namespace std;

/** Funzione che si occupa di acquisire i dati all'interno della lista delle auto */
void loadA(ListAuto& aList, string fileNameA)
{
    string Marca;
    string C;
    int Cavalli;
    ifstream ifsA(fileNameA);
    while(ifsA.good())
    {
        getline(ifsA, Marca, '-');
        getline(ifsA, C, '\n');
        Cavalli = stoi(C);

        Auto a(Marca,Cavalli);
        aList.insert(a);
    }

}

/** Funzione che si occupa di acquisire i dati all'interno della lista delle moto */
void loadM(ListMoto& mList, string fileNameM)
{
    string Marca;
    string C;
    int Cavalli;
    ifstream ifsM(fileNameM);
    while(ifsM.good())
    {
        getline(ifsM,Marca,'-');
        getline(ifsM,C,'\n');
        Cavalli = stoi(C);

        Moto m(Marca,Cavalli);
        mList.insert(m);
    }
}

/** Funzione che si occupa di acquisire i dati all'interno della lista delle barche */
void loadB(ListBarca& bList, string fileNameB)
{
    string Marca;
    string C;
    int Cavalli;
    ifstream ifsB(fileNameB);
    while(ifsB.good())
    {
        getline(ifsB,Marca,'-');
        getline(ifsB,C,'\n');
        Cavalli = stoi(C);

        Barca b(Marca,Cavalli);
        bList.insert(b);
    }
}

/** Funzione che si occupa di travasare i dati all'interno del BST Auto dalla lista delle auto */
void travasaA(ListAuto& aList, Tree<Auto>& aTree)
{
    Nodo<Auto>* cur = aList.getHead();
    Auto a;
    while(cur!=aList.getNil())
    {
        a = aList.getData(cur);
        aTree.ins(a);
        cur=cur->getNext();
    }

}

/** Funzione che si occupa di travasare i dati all'interno del BST Moto dalla lista delle moto */
void travasaM(ListMoto& mList, Tree<Moto>& mTree)
{
    Nodo<Moto>* cur = mList.getHead();
    Moto m;
    while(cur!=mList.getNil())
    {
        m = mList.getData(cur);
        mTree.ins(m);
        cur=cur->getNext();
    }
}

/** Funzione che si occupa di travasare i dati all'interno del BST Barche dalla lista delle barche */
void travasaB(ListBarca& bList, Tree<Barca>& bTree)
{
    Nodo<Barca>* cur = bList.getHead();
    Barca b;
    while(cur!=bList.getNil())
    {
        b = bList.getData(cur);
        bTree.ins(b);
        cur=cur->getNext();
    }
}

/** Funzione di cancellazione di un auto */
void cancA(int key, Tree<Auto>& aTree)
{
    aTree.canc(key);
}

/** Funzione di cancellazione di una moto */
void cancM(int key, Tree<Moto>& mTree)
{
    mTree.canc(key);
}

/** Funzione di cancellazione di una barca */
void cancB(int key, Tree<Barca>& bTree)
{
    bTree.canc(key);
}

/** Funzione per la stampa delle liste*/
void print(ListAuto& aList, ListMoto& mList, ListBarca& bList)
{
   aList.print();
   mList.print();
   bList.print();
}

/** Funzione che cancella tutte le auto, moto e barche o una di una categoria sotto una cilindrata data*/
void canc(Tree<Auto>& aTree, Tree<Moto>& mTree, Tree<Barca>& bTree)
{
    cout<<endl<<"Vuoi eliminare in base alla cilindrata : un auto(1), una moto(2), una barca(3) o da tutti i veicoli(4) o nessuno(0) "<<endl;
    int c;
    cin>>c;
    if(c>0 && c<5)
    {
        cout<<"Inserisci il limite minimo di cilindrata che vuoi mantenere: "<<endl;
        int cc;
        cin>>cc;
        if(c==1)cancA(cc, aTree);
        else if(c==2)cancM(cc, mTree);
        else if(c==3)cancB(cc, bTree);
        else if(c==4)
        {
            cancA(cc, aTree);
            cancM(cc, mTree);
            cancB(cc, bTree);
        }
    }
}

int main()
{
    ListAuto  aList;
    ListMoto  mList;
    ListBarca  bList;

    Tree<Auto> aTree;
    Tree<Moto> mTree;
    Tree<Barca> bTree;

    /** Creo il tread per l'inserimento delle auto nella lista di appartenenza*/
    thread aL_thread(loadA, ref(aList), "auto.txt");
    cout<<"Creazione Loading Auto thread con id: "<<aL_thread.get_id()<<endl;
    /** Creo il tread per l'inserimento delle moto nella lista di appartenenza*/
    thread mL_thread(loadM, ref(mList), "moto.txt");
    cout<<"Creazione Loading Moto thread con id: "<<mL_thread.get_id()<<endl;
    /** Creo il tread per l'inserimento delle barche nella lista di appartenenza*/
    thread bL_thread(loadB, ref(bList), "barca.txt");
    cout<<"Creazione Loading Barca thread con id: "<<bL_thread.get_id()<<endl;

    aL_thread.join();
    mL_thread.join();
    bL_thread.join();

    cout<<endl;
    print(aList, mList, bList);

    cout<<endl<<"Sto creando i thread per il travaso delle liste nei BST"<<endl;
    /** Creo il tread per l'inserimento delle auto nell' albero di appartenenza*/
    thread aT_thread(travasaA, ref(aList), ref(aTree));
    /** Creo il tread per l'inserimento delle moto nell' albero di appartenenza*/
    thread mT_thread(travasaM, ref(mList), ref(mTree));
    /** Creo il tread per l'inserimento delle barche nell' albero di appartenenza*/
    thread bT_thread(travasaB, ref(bList), ref(bTree));

    aT_thread.join();
    mT_thread.join();
    bT_thread.join();

    /**Funzione che gestisce la possibilità di effettuare cancellazioni negli alberi*/
    canc(aTree, mTree, bTree);

    aTree.inOrder();
    mTree.inOrder();
    bTree.inOrder();


    return 0;
}
