#ifndef HOSPEDE_HPP
#define HOSPEDE.HPP

using namespace std;

class Hospede{
    private:
        string nome;
        string documento;
        string telefone;
        string email;
    public:
        Hospede(){;}
        Hospede(string nome, string documento, string telefone, string email){
            this->nome = nome;
            this->documento = documento;
            this->telefone = telefone;
            this->email = email;
        }

        string get_nome(){return nome;}
        string get_documento(){return documento;}
        string get_telefone(){return telefone;}
        string get_email(){return email;}
};

ostream& operator<<(ostream& os, const Hospede& h){
    os << h.get_nome() << " | Doc: " << h.get_documento();
    return os;
}

#endif