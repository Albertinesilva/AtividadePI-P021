#include "../Headers/Usuario.hpp"

int Usuario::quantidadeDeIdentificadores = 0;

Usuario::Usuario(const string &nome, const string &cpf, const string &endereco, const string &telefone) : nome(nome) , cpf(cpf) , endereco(endereco) , telefone(telefone){
    Usuario::quantidadeDeIdentificadores++;
    setId(Usuario::quantidadeDeIdentificadores);
}

Usuario::Usuario(){

}

string Usuario::getNome(){
    return this->nome;
}

string Usuario::getCpf(){
    return this->cpf;
}

string Usuario::getEndereco(){
    return this->endereco;
}

string Usuario::getTelefone(){
    return this->telefone;
}

int Usuario::getId(){
    return this->id;
}

void Usuario::setNome(string nome){
    this->nome = nome;
}

void Usuario::setCpf(string cpf){
    this->cpf = cpf;
}

void Usuario::setEndereco(string endereco){
    this->endereco = endereco;
}

void Usuario::setTelefone(string telefone){
    this->telefone = telefone;
}

void Usuario::setId(int id){
    this->id = id;
}


void Usuario::mostraUsuario(){
    cout << "Id : " << getId() << endl;
    cout << "Nome : " << getNome() << endl;
    cout << "Cpf : " << getCpf() << endl;
    cout << "Endereço : " << getEndereco() << endl;
    cout << "Telefone : " << getTelefone() << endl;
}
