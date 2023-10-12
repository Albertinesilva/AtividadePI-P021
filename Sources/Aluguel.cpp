#include "../Headers/Aluguel.hpp"

int Aluguel::quantidadeDeIdentificadores = 0;

Aluguel::Aluguel(const bool &ativo, Usuario* usuario, Livro* livro, const Data &dataInicio) {
    Aluguel::quantidadeDeIdentificadores++;
    setId(Aluguel::quantidadeDeIdentificadores);
    setAtivo(ativo);
    setUsuario(usuario);
    setLivro(livro);
    setDataInicio(dataInicio);
}

int Aluguel::getquantidadeDeIdentificadores(){
    return Aluguel::quantidadeDeIdentificadores;
}

void Aluguel::setQuantidadeDeIdentificadores(int qtd){
    Aluguel::quantidadeDeIdentificadores = qtd;
}


int Aluguel::getId(){
    return this->id;
}

bool Aluguel::getAtivo(){
    return this->ativo;
}

Usuario* Aluguel::getUsuario(){
    return this->usuario;
}

Livro* Aluguel::getLivro(){
    return this->livro;
}

Data Aluguel::getDataInicio(){
    return this->dataInicio;
}

void Aluguel::setId(int id){
    this->id = id;
}

void Aluguel::setAtivo(bool ativo){
    this-> ativo = ativo;
}

void Aluguel::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}

void Aluguel::setLivro(Livro* livro){
    this->livro = livro;
}

void Aluguel::setDataInicio(Data dataInicio){
    this->dataInicio = dataInicio;
}

void Aluguel::mostraAluguel(){
    cout << "ID : " << getId() << endl;
    cout << "-----Cliente-----" << endl;
    getUsuario()->mostraUsuario();
    cout << "-----Livro-----" << endl;
    getLivro()->mostraLivro();
    cout << "Data de Retirada : " << 
    getDataInicio().tm_mday << "/" <<
    getDataInicio().tm_mon << "/" <<
    getDataInicio().tm_year << endl;
}

