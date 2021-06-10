#ifndef BARCA_H
#define BARCA_H
#include<iostream>
#include<sstream>

#include <Veicolo.h>

using namespace std;

class Barca : public Veicolo
{
public:
    Barca(string Marca, int Cavalli): Veicolo(Marca, Cavalli) {}
    Barca() {}

    /** Funzione di stampa da usare nell overload dell operatore <<*/
    string toString() const
    {
        stringstream stream;
        stream << "Sono una barca di marca: " << Marca << ", di cavalli:" <<Cavalli<<endl;
        return stream.str();
    }

    friend ostream& operator<<(ostream& out, Barca& b)
    {
        out<<b.toString();
        return out;
    }

private:
};

#endif // BARCA_H
