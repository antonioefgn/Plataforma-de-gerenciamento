#ifndef HOSPEDE_HPP
#define HOSPEDE_HPP

#include <string>
#include <iostream>

using namespace std;

class Hospede {
private:
    string nome;
    string documento;
    string telefone;
    string email;

public:
    Hospede() {}
    Hospede(string nome, string documento, string telefone, string email) {
        this->nome = nome;
        this->documento = documento;
        this->telefone = telefone;
        this->email = email;
    }

    string get_nome() const { return nome; }
    string get_documento() const { return documento; }
    string get_telefone() const { return telefone; }
    string get_email() const { return email; }
};

inline ostream& operator<<(ostream& os, const Hospede& h) {
    os << h.get_nome() << " | Doc: " << h.get_documento();
    return os;
}

#endif