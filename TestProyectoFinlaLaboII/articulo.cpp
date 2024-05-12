#include "articulo.h"


Articulo::Articulo(){
    _idArticulo = -1;
    strcpy(_nombre,"S/N");
    _precio = 0.0d;
    _costo = 0.0d;
    _stock = -1;
    _estado = false;
}

Articulo::Articulo(int id, std::string nombre, float costo, float precio, int stock, bool estado){
    setId(id);
    setNombre(nombre);
    setCosto(costo);
    setPrecio(precio);
    setStock(stock);
    setEstado(estado);
}

void Articulo::setId(int id){
    if(id < 0) id = 0;
    _idArticulo = id;
}

int Articulo::getId(){return _idArticulo;}

void Articulo::setNombre(std::string nombre){
    if(nombre.size() <= 30){
        strcpy(_nombre,nombre.c_str());
    }else{
        strcpy(_nombre,"Sin datos");
    }
}

std::string Articulo::getNombre(){return _nombre;}

void Articulo::setCosto(float costo){
    if(costo < 0) costo = 0;

    _costo = costo;
}

float Articulo::getCosto(){return _costo;}

void Articulo::setPrecio(float precio){
    if(precio < 0) precio = 0;
    _precio = precio;
}

float Articulo::getPrecio(){return _precio;}

void Articulo::setStock(int stock){
    if(stock < 0) stock = 0;
    _stock = stock;
}

int Articulo::getStock(){return _stock;}

void Articulo::setEstado(bool estado){
    _estado = estado;
}

bool Articulo::getEstado(){return _estado;}











