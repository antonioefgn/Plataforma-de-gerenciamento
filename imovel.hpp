#ifndef IMOVEL_HPP
#define IMOVEL_HPP

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>
#include "reserva.hpp"

class Imovel {
    int id;
    std::string titulo;
    double preco_diaria;
    std::vector<Reserva> reservas;

public:
    Imovel(int id, const std::string& titulo, double preco_diaria)
        : id(id), titulo(titulo), preco_diaria(preco_diaria) {}

    int get_id() const { return id; }
    const std::string& get_titulo() const { return titulo; }
    double get_preco_diaria() const { return preco_diaria; }
    const std::vector<Reserva>& get_reservas() const { return reservas; }

    void adicionarReserva(const Reserva& nova) {
        bool conflito = std::any_of(reservas.begin(), reservas.end(),
            [&](const Reserva& r) { return r.conflitoData(nova); });
        if (conflito)
            throw std::runtime_error("Conflito de datas no imovel " + std::to_string(id));
        reservas.push_back(nova);
    }
};

#endif
