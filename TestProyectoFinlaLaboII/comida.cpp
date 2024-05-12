#include "comida.h"
#include <cstring>

Comida::Comida(){
    _idArticulo = -1;
    strcpy(_ingredientes,"SIN INGREDIENTES");
    _guarnicion = false;
}

Comida::Comida(int id, std::string ingredientes, bool guarn){
    setIdArt(id);
    setIngredientes(ingredientes);
    setGuarnicion(guarn);
}

void Comida::setIdArt(int id){
    if(id < 0) id = 0;
    _idArticulo = id;
}

int Comida::getIdArt(){return _idArticulo;}

void Comida::setIngredientes(std::string ingredientes){
    if(ingredientes.size() <= 100){
        strcpy(_ingredientes,ingredientes.c_str());
    }else{
        strcpy(_ingredientes,"SIN INGREDIENTES");
    }
}

std::string Comida::getIngredientes(){return _ingredientes;}

void Comida::setGuarnicion(bool guarnicion){
    _guarnicion = guarnicion;
}

bool Comida::getGurnicion(){return _guarnicion;}
