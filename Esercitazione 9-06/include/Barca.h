#ifndef BARCA_H
#define BARCA_H

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
        const char sep = ' ';
        const int tabW = 2;
        const int marcaW = 10;
        const int cavalliW = 10;
        stringstream stream;
        stream <<left<<setw(marcaW)<<"Barca"<<setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(marcaW)<< Marca << setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(cavalliW)<< Cavalli;
        stream <<left<<setw(tabW)<<"|"<<endl;
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
