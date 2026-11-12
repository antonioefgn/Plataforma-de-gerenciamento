#ifndef DATA_HPP
#define DATA.HPP


using namespace std;

class Data{
    private:
        int dia, mes, ano;

        int paraInteiro() const {
            return ano * 10000 + mes * 100 + dia;
        }

    public:
        Data(int dia, int mes, int ano){
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        }

        int get_dia(){return dia;}
        int get_mes(){return mes;}
        int get_ano(){return ano;}

        void set_dia(int dia){this->dia = dia;}
        void set_mes(int mes){this->mes = mes;}
        void set_ano(int ano){this->ano = ano;}

        // Sobrecarga de operadores //

        bool operator == (const Data& outra) const{
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

        // --- SOBRECARGA DO OPERADOR DE SAÍDA (cout e arquivos) ---
        friend std::ostream& operator<<(std::ostream& os, const Data& d) {
                os << std::setfill('0') << std::setw(2) << d.dia << "/"
                << std::setfill('0') << std::setw(2) << d.mes << "/"
                << d.ano;
            return os;
    }
};

#endif;