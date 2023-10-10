#ifndef USUARIO_HPP
#define USUARIO_HPP

#include<iostream>

using namespace std;

class Usuario{

    static int quantidadeDeIdentificadores;
    int id;
    string nome;
    string cpf;
    string endereco;
    string telefone;

    public:

    Usuario();
    Usuario(const string &nome, const string &cpf, const string &endereco, const string &telefone);
    string getNome();
    string getCpf();
    string getEndereco();
    string getTelefone();
    int getId();

    void setNome(string nome);
    void setCpf(string cpf);
    void setEndereco(string endereco);
    void setTelefone(string telefone);
    void setId(int id);

    void mostraUsuario();


};


#endif