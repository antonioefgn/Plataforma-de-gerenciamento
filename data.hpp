#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class Data {
private:
    int dia, mes, ano;

    int paraInteiro() const {
        return ano * 10000 + mes * 100 + dia;
    }

public:
    // Construtor padrão
    Data() : dia(1), mes(1), ano(2000) {}

    // Construtor parametrizado
    Data(int dia, int mes, int ano) : dia(dia), mes(mes), ano(ano) {}

    int get_dia() const { return dia; }
    int get_mes() const { return mes; }
    int get_ano() const { return ano; }

    void set_dia(int dia) { this->dia = dia; }
    void set_mes(int mes) { this->mes = mes; }
    void set_ano(int ano) { this->ano = ano; }

    // Sobrecarga de operadores
    bool operator==(const Data& outra) const {
        return this->paraInteiro() == outra.paraInteiro();
    }

    bool operator!=(const Data& outra) const {
        return this->paraInteiro() != outra.paraInteiro();
    }

    bool operator<(const Data& outra) const {
        return this->paraInteiro() < outra.paraInteiro();
    }

    bool operator<=(const Data& outra) const {
        return this->paraInteiro() <= outra.paraInteiro();
    }

    bool operator>(const Data& outra) const {
        return this->paraInteiro() > outra.paraInteiro();
    }

    bool operator>=(const Data& outra) const {
        return this->paraInteiro() >= outra.paraInteiro();
    }

    // Sobrecarga do operador de saída (cout e arquivos)
    friend std::ostream& operator<<(std::ostream& os, const Data& d) {
        os << std::setfill('0') << std::setw(2) << d.dia << "/"
           << std::setfill('0') << std::setw(2) << d.mes << "/"
           << d.ano;
        return os;
    }
};

#endif