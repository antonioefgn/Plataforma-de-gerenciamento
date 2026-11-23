#ifndef GERENCIADOR_CANAIS_HPP
#define GERENCIADOR_CANAIS_HPP

#include <algorithm>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>
#include "imovel.hpp"
#include "plataforma.hpp"

class GerenciadorCanais {
    std::vector<Imovel> imoveis;
    std::vector<std::unique_ptr<Plataforma>> plataformas;

public:
    void adicionarImovel(const Imovel& imovel) {
        if (buscarImovel(imovel.get_id()))
            throw std::runtime_error("Ja existe imovel com id " + std::to_string(imovel.get_id()));
        imoveis.push_back(imovel);
    }

    void adicionarPlataforma(std::unique_ptr<Plataforma> p) {
        if (!p) throw std::invalid_argument("Plataforma nula");
        plataformas.push_back(std::move(p));
    }

    Imovel* buscarImovel(int id) {
        auto it = std::find_if(imoveis.begin(), imoveis.end(),
            [id](const Imovel& i) { return i.get_id() == id; });
        return it != imoveis.end() ? &*it : nullptr;
    }


    const Plataforma* buscarPlataforma(const std::string& nome) const {
        auto it = std::find_if(plataformas.begin(), plataformas.end(),
            [&](const auto& p) { return p->get_nome() == nome; });
        return it != plataformas.end() ? it->get() : nullptr;
    }

    const std::vector<Imovel>& get_imoveis() const { return imoveis; }
};

#endif
