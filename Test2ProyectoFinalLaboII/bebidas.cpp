#include "bebidas.h"
#include <cstring>


Bebidas::Bebidas(){
    _idArticulo = -1;
    strcpy(_tipoBebida," SIN TIPO");
    _volumenMl = -1.0d;
    _gradAlcohol = -1.0d;
}

Bebidas::Bebidas(int idArt, std::string tipo, float vol, float grad){
    setIdArt(idArt);
    setTipoBebida(tipo);
    setVolumenMl(vol);
    setGragAlcohol(grad);
}

void Bebidas::setIdArt(int id){
    if(id < 0) id = 0;
    _idArticulo = id;
}

int Bebidas::getIdArt(){return _idArticulo;}

void Bebidas::setTipoBebida(std::string tipo){
    if(tipo.size() <= 50){
        strcpy(_tipoBebida,tipo.c_str());
    }else{
        strcpy(_tipoBebida," SIN TIPO");
    }
}

std::string Bebidas::getTipoBebida(){return _tipoBebida;}

void Bebidas::setVolumenMl(float vol){
    if(vol < 0.0d)vol = 0.0d;
    _volumenMl = vol;
}

float Bebidas::getVolumenMl(){return _volumenMl;}

void Bebidas::setGragAlcohol(float grad){
    if(grad < 0.0d) grad = 0.0d;
    _gradAlcohol = grad;
}

float Bebidas::getGradAlcohol(){return _gradAlcohol;}





