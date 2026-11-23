#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>
#include "data.hpp"
#include "hospede.hpp"

using namespace std;

class Reserva {
    private:
        Data check_in;
        Data check_out;
        Hospede hospede;
        float valor_bruto;
        string nome_plataforma;

    public:
        Reserva(Data check_in, Data check_out, Hospede hospede, float valor_bruto, string nome_plataforma){
            this->check_in = check_in;
            this->check_out = check_out;
            this->hospede = hospede;
            this->valor_bruto = valor_bruto;
            this->nome_plataforma = nome_plataforma;
        }

    bool conflitoData(const Reserva& outra) const {
        return ((this->check_in <= outra.check_out) && (this->check_out >= outra.check_in));
    }

    Data get_check_in() const { return check_in; }
    Data get_check_out() const { return check_out; }
    Hospede get_hospede() const { return hospede; }
    float get_valor_bruto() const { return valor_bruto; }
    string get_nome_plataforma() const { return nome_plataforma; }
};

#endif