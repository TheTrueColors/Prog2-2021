#ifndef AUTHOR_H
#define AUTHOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Author
{
private:
    string name;
    string surname;
    string date_birth;

public:
    Author(string name, string surname, string date_birth) : name(name), surname(surname), date_birth(date_birth) {};
    Author() {};

    string getName()
    {
        return this->name;
    }

    string getSurname()
    {
        return this->surname;
    }

    string getDate()
    {
        return this->date_birth;
    }

    void setName(string name)
    {
        this->name = name;
        return;
    }

    void setSurname(string surname)
    {
        this->surname = surname;
        return;
    }

    void setDate(string date_birth)
    {
        this->date_birth = date_birth;
        return;
    }

    string toString()
    {
        stringstream out;
        out<<"Author:"<<endl<<"Name: "<<this->getName()<<endl<<"Surname: "<<this->getSurname()<<endl<<"Date of Birth: "<<this->getDate()<<endl<<endl;
        return out.str();

    }

    friend ostream& operator<<(ostream& out,Author& a)
    {
        out<<"Author:"<<endl<<"Name: "<<a.getName()<<endl<<"Surname: "<<a.getSurname()<<endl<<"Date of Birth: "<<a.getDate()<<endl<<endl;
        return out;
    }


    friend istream& operator>>(istream& in, Author& a)
    {
        string name, surname, date;

        getline(in, name, '-');
        getline(in, surname, '-');
        getline(in, date, '\n');
        a.setName(name);
        a.setSurname(surname);
        a.setDate(date);

        return in;

    }

};

#endif //AUTHOR_H
