#pragma once
#include "rlutil.h"
#include <windows.h>
#include <iostream>

enum {
    off = 0,
    on = 1,
    horizontal = 2,
    vertical = 3
};

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
    std::string ingresarTexto(int x, int y, bool cursorOn);
    void eliminarHorizontal(int x_init, int x_fin, int y);
    void barraEspera(int time);
    void dibujarRectangulo(int init_x, int init_y, int largo, int ancho);
};
