#include "../Headers/Livro.hpp"

int Livro::quantidadeDeIdentificadores = 0;

Livro::Livro(const string &titulo , const string &author , const int &numPaginas, const int &numCopiasDisponiveis)
: titulo(titulo) , author(author) , numPaginas(numPaginas) , numCopiasDisponiveis(numCopiasDisponiveis){
    Livro::quantidadeDeIdentificadores++;
    setId(Livro::quantidadeDeIdentificadores);
}

Livro::Livro(){

}

int Livro::getquantidadeDeIdentificadores(){
    return Livro::quantidadeDeIdentificadores;
}

void Livro::setQuantidadeDeIdentificadores(int qtd){
    Livro::quantidadeDeIdentificadores = qtd;
}

int Livro::getNumCopiasDisponiveis(){
    return this->numCopiasDisponiveis;
}

string Livro::getAuthor(){
    return this->author;
}

string Livro::getTitulo(){
    return this->titulo;
}

int Livro::getNumPaginas(){
    return this->numPaginas;
}

int Livro::getId(){
    return this->id;
}

void Livro::setNumCopiasDisponiveis(int numCopiasDisponiveis){
    this->numCopiasDisponiveis = numCopiasDisponiveis;
}

void Livro::setTitulo(string titulo){
    this->titulo = titulo;
}

void Livro::setAuthor(string author){
    this->author = author;
}

void Livro::setNumPaginas(int numPaginas){
    this->numPaginas = numPaginas;
}

void Livro::setId(int id){
    this->id = id;
}

void Livro::mostraLivro(){
    cout << "Id : " << getId() << endl;
    cout << "Titulo : " << getTitulo() << endl;
    cout << "Author : " << getAuthor() << endl;
    cout << "Numero de Paginas : " << getNumPaginas() << endl;
    cout << "Numero de Copias Disponiveis : " << getNumCopiasDisponiveis() << endl; 
}