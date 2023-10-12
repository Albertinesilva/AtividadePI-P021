#include "../Headers/Livro.hpp"

int Livro::quantidadeDeIdentificadores = 0;

Livro::Livro(const string &titulo , const string &author , const int &numPaginas) : titulo(titulo) , author(author) , numPaginas(numPaginas){
    Livro::quantidadeDeIdentificadores++;
    setId(Livro::quantidadeDeIdentificadores);
}

Livro::Livro(){

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