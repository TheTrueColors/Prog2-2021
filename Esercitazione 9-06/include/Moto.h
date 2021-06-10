#ifndef MOTO_H
#define MOTO_H

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
        const char sep = ' ';
        const int tabW = 2;
        const int marcaW = 10;
        const int cavalliW = 10;
        stringstream stream;
        stream <<left<<setw(marcaW)<<"Moto"<<setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(marcaW)<< Marca << setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(cavalliW)<< Cavalli;
        stream <<left<<setw(tabW)<<"|"<<endl;
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
