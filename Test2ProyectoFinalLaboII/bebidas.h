#pragma once
#include <iostream>


class Bebidas{

private:

    int _idArticulo;
    char _tipoBebida[50];
    float _volumenMl;
    float _gradAlcohol;
    // vasosDisponibles

public:

    Bebidas();
    Bebidas(int idArt, std::string tipo, float vol, float grad);

    void setIdArt(int id);
    int getIdArt();

    void setTipoBebida(std::string tipo);
    std::string getTipoBebida();

    void setVolumenMl(float vol);
    float getVolumenMl();

    void setGragAlcohol(float grad);
    float getGradAlcohol();



};
