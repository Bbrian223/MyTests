#pragma once
#include <iostream>

class Comida{

private:

    int _idArticulo;
    char _ingredientes[100];
    bool _guarnicion;

public:

    Comida();
    Comida(int idArt, std::string ingredientes, bool guarn);

    void setIdArt(int id);
    int getIdArt();

    void setIngredientes(std::string ingredientes);
    std::string getIngredientes();

    void setGuarnicion(bool guarnicion);
    bool getGurnicion();


};
