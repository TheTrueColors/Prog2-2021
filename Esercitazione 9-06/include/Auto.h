#ifndef AUTO_H
#define AUTO_H

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
        const char sep = ' ';
        const int tabW = 2;
        const int marcaW = 10;
        const int cavalliW = 10;
        stringstream stream;
        stream <<left<<setw(marcaW)<<"Auto"<<setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(marcaW)<< Marca << setfill(sep);
        stream <<left<<setw(tabW)<<"|"<<setfill(sep);
        stream <<left<<setw(cavalliW)<< Cavalli;
        stream <<left<<setw(tabW)<<"|"<<endl;
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
