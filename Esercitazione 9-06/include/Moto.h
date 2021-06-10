#ifndef MOTO_H
#define MOTO_H
#include<iostream>
#include<sstream>

#include <Veicolo.h>

using namespace std;

class Moto : public Veicolo
{
public:
    Moto(string Marca, int Cavalli): Veicolo(Marca, Cavalli) {}
    Moto() {}

    /** Funzione di stampa da usare nell overload dell operatore <<*/
    string toString() const
    {
        stringstream stream;
        stream << "Sono una moto di marca " << Marca << ", di cavalli:" <<Cavalli<<endl;
        return stream.str();
    }

    friend ostream& operator<<(ostream& out, Moto& m)
    {
        out<<m.toString();
        return out;
    }

private:
};

#endif // MOTO_H
