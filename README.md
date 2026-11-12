# Plataforma-de-gerenciamento
É uma plataforma de gerenciamento de apps de aluguel e reseervas
ela foi montada em varios passos:
﻿    • Passo 1: Configurar o projeto. Crie uma pasta organizada separando cabeçalhos (.h ou .hpp) e implementações (.cpp). Configure um compilador padrão (como g++ com -std=c++17) e teste um "Olá, Mundo" para garantir que a compilação funciona.
    • Passo 2: Criar a classe Data. Implemente uma classe simples com dia, mes e ano. Sobrecarregue os operadores de comparação (==, <, <=, >, >=) para facilitar a verificação de datas no futuro.
    • Passo 3: Criar Hospede e Reserva. A classe Reserva deve conter o hóspede, data de check-in, data de check-out, valor bruto e o nome da plataforma de origem. Adicione um método conflitaCom(const Reserva& outra) usando a lógica: (inicioA < fimB) && (fimA > inicioB).
Fase 2: Pilares de POO — Herança e Polimorfismo (Dias 4 a 6)
Aqui entra a parte mais importante para a nota da disciplina: mostrar que seu sistema lida com diferentes plataformas de forma genérica.
    • Passo 4: Criar a classe abstrata Plataforma. Defina atributos comuns (como nome e taxaComissao) e métodos virtuais puros (= 0), como calcularValorLiquido(double valorBruto) const e formatarExportacao(const Reserva& r) const.
    • Passo 5: Implementar as plataformas concretas. Crie as classes filhas Airbnb, Booking e ReservaDireta. Na Airbnb, aplique uma regra (ex: 15% de taxa); na Booking, aplique outra (ex: 12% + taxa fixa de limpeza); na ReservaDireta, aplique 0% de taxa.
    • Passo 6: Criar a classe Imovel. Ela deve armazenar ID, título, preço da diária e um vetor de reservas (std::vector<Reserva>). Crie o método adicionarReserva(), que percorre as reservas existentes e lança uma exceção (std::runtime_error) caso haja conflito de datas.
Fase 3: O Motor Central e Sincronização (Dias 7 a 9)
Agora você vai conectar tudo em uma classe controladora que gerencia o negócio.
    • Passo 7: Criar GerenciadorCanais. Essa classe guarda a lista de imóveis (std::vector<Imovel>) e as plataformas disponíveis usando ponteiros inteligentes (std::vector<std::unique_ptr<Plataforma>>).
    • Passo 8: Simular a sincronização. Crie um método registrarReserva(int idImovel, Reserva novaReserva, Plataforma* origem). Quando uma reserva entra pelo Airbnb, o gerenciador valida no Imovel, salva a reserva e imprime no console um aviso simulando o bloqueio daquela data nas outras plataformas (Booking e Direto).
    • Passo 9: Criar relatórios financeiros. Adicione métodos no gerenciador para somar o faturamento bruto e o faturamento líquido por imóvel ou por plataforma, aproveitando o polimorfismo de calcularValorLiquido().
Fase 4: Persistência em Arquivos (Dias 10 e 11)
Para o sistema não perder os dados ao fechar, use manipulação básica de arquivos com <fstream>.
    • Passo 10: Salvar dados em .csv. Crie funções para gravar os imóveis em imoveis.csv e as reservas em reservas.csv separando os campos por ponto e vírgula (;).
    • Passo 11: Simular importação externa. Crie um arquivo novas_reservas_airbnb.txt manualmente com 2 ou 3 reservas de teste. Faça uma função no menu que lê esse arquivo, tenta cadastrar as reservas no sistema e exibe quais foram aceitas e quais deram conflito (overbooking).
Fase 5: Interface CLI e Refinamento Final (Dias 12 a 14)
Com toda a lógica testada e funcionando, construa a interação com o usuário.
    • Passo 12: Construir o menu no main.cpp. Crie um loop do-while com opções claras: Cadastrar Imóvel, Nova Reserva Manual, Importar Reservas de Arquivo, Listar Calendário do Imóvel e Ver Relatório Financeiro.
    • Passo 13: Tratar entradas e exceções. Envolva as chamadas do menu em blocos try-catch para capturar erros de datas inválidas, IDs inexistentes ou conflitos de reserva sem fechar o programa bruscamente.
    • Passo 14: Revisão de código. Verifique se todos os destrutores das classes base são virtuais (virtual ~Plataforma() = default;), se você usou const corretamente nos métodos de leitura e se o código compila sem avisos (warnings).

