#pragma once
#include "rlutil.h"
#include <windows.h>
#include <iostream>

class Item{
private:
    rlutil::COLOR _backgroud;
    rlutil::COLOR _colorText;
public:

    Item();
    Item(rlutil::COLOR backg, rlutil::COLOR cText);

    void setBackgroundColor(rlutil::COLOR backg);
    void setColorText(rlutil::COLOR cText);

    void mostrarItem(std::string text, int x, int y);
    void mostrarItem(std::string text, int x, int y, bool select);
    std::string ingresarTexto(int x, int y, bool cursorOn);
    void eliminarHorizontal(int x, int largo, int y);
    void barraEspera(int time);
    void dibujarRectangulo(int init_x, int init_y, int largo, int ancho);
    void borrarRectangulo(int x, int y, int alto, int ancho);
};
