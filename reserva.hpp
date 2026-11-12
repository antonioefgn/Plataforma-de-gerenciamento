#ifndef RESERVA_HPP
#define RESERVA.HPP
#include "data.hpp"
#include "hospede.hpp"

using namespace std;

class Reserva{
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
        bool comflitoData( const Reserva& outra){
            return ((this->check_in <= outra.check_out) && (this->check_out >= outra.check_in));
        }

        Data get_check_in(void){ return check_in;}
        Data get_check_out(void){ return check_out;}
        Hospede hospede(void){ return hospede;}
        float valor_bruto(void){ return valor_bruto;}
        string nome_plataforma(void){ return nome_plataforma;}

};

#endif