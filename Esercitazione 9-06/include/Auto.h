#ifndef AUTO_H
#define AUTO_H
#include<iostream>
#include<sstream>
#include<string>

#include <Veicolo.h>

using namespace std;

class Auto : public Veicolo
{
public:
    Auto(string Marca, int Cavalli): Veicolo(Marca, Cavalli) {}
    Auto() {}

    /** Funzione di stampa da usare nell overload dell operatore <<*/
    string toString() const
    {
        stringstream stream;
        stream << "Sono un auto di marca " << Marca << ", di cavalli:" <<Cavalli<<endl;
        return stream.str();
    }

    friend ostream& operator<<(ostream& out, Auto& a)
    {
        out<<a.toString();
        return out;
    }

private:
};

#endif // AUTO_H
