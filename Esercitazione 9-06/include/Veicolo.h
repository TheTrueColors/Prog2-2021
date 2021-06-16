#ifndef VEICOLO_H
#define VEICOLO_H

#include<iomanip>
#include<iostream>
#include<sstream>
using namespace std;

class Veicolo
{
public:
    Veicolo(string Marca, int Cavalli): Marca(Marca), Cavalli(Cavalli) {}
    Veicolo() {}

    string getMarca()
    {
        return Marca;
    }
    void setMarca(string val)
    {
        Marca = val;
    }
    int getCavalli()
    {
        return Cavalli;
    }
    void setCavalli(int val)
    {
        Cavalli = val;
    }


    virtual std::string toString() const = 0;


    friend std::ostream& operator<<(std::ostream& out, const Veicolo& v)
    {
        out << v.toString();
        return out;
    }

protected:
    string Marca;
    int Cavalli;
};

#endif // VEICOLO_H
