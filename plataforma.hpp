#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include <string>
#include <sstream>
#include <iomanip>
#include "reserva.hpp"

using namespace std;

class Plataforma {
protected:
    string nome;
    double taxaComissao;

public:
    Plataforma(const string& nome, double taxaComissao)
        : nome(nome), taxaComissao(taxaComissao) {}

    virtual ~Plataforma() = default;

    string get_nome() const { return nome; }

    virtual double calcularValorLiquido(double valorBruto) const = 0;
    virtual string formatarExportacao(const Reserva& r) const = 0;
};

class Airbnb : public Plataforma {
public:
    Airbnb() : Plataforma("Airbnb", 0.15) {}

    double calcularValorLiquido(double valorBruto) const override {
        return valorBruto * (1.0 - taxaComissao);
    }

    string formatarExportacao(const Reserva& r) const override {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "[AIRBNB] Hospede: " << r.get_hospede()
            << " | Liquido: R$ " << calcularValorLiquido(r.get_valor_bruto());
        return oss.str();
    }
};

class Booking : public Plataforma {
private:
    double taxaLimpeza;

public:
    Booking(double taxaLimpeza = 80.0)
        : Plataforma("Booking", 0.12), taxaLimpeza(taxaLimpeza) {}

    double calcularValorLiquido(double valorBruto) const override {
        double liquido = valorBruto * (1.0 - taxaComissao) - taxaLimpeza;
        return (liquido > 0.0) ? liquido : 0.0;
    }

    string formatarExportacao(const Reserva& r) const override {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "[BOOKING] Hospede: " << r.get_hospede()
            << " | Taxa Limpeza: R$ " << taxaLimpeza
            << " | Liquido: R$ " << calcularValorLiquido(r.get_valor_bruto());
        return oss.str();
    }
};

class ReservaDireta : public Plataforma {
public:
    ReservaDireta() : Plataforma("Reserva Direta", 0.0) {}

    double calcularValorLiquido(double valorBruto) const override {
        return valorBruto;
    }

    string formatarExportacao(const Reserva& r) const override {
        ostringstream oss;
        oss << fixed << setprecision(2);
        oss << "[DIRETA] Hospede: " << r.get_hospede()
            << " | Liquido: R$ " << calcularValorLiquido(r.get_valor_bruto());
        return oss.str();
    }
};

#endif