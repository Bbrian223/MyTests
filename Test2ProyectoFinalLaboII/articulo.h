#pragma once
#include <cstring>
#include <iostream>

class Articulo{

private:

    int _idArticulo;
    char _nombre[30];
    float _costo;
    float _precio;
    int _stock;
    bool _estado;

public:

    Articulo();
    Articulo(int id, std::string nombre, float costo, float precio, int stock, bool estado);

    void setId(int id);
    int getId();

    void setNombre(std::string nombre);
    std::string getNombre();

    void setCosto(float costo);
    float getCosto();

    void setPrecio(float precio);
    float getPrecio();

    void setStock(int stock);
    int getStock();

    void setEstado(bool estado);
    bool getEstado();
};
