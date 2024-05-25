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
    std::string ingresarTexto(int x, int y, bool cursorOn);
    void eliminarHorizontal(int x, int largo, int y);
    void barraEspera(int time);                             //eliminar?
    void barraEspera(int time, int x, int y);
    void dibujarRectangulo(int init_x, int init_y, int largo, int ancho);
    void pintarRectangulo(int x, int y, int alto, int ancho);
    void pintarRectangulo(int x, int y, int alto, int ancho, rlutil::COLOR cFondo);

    void crearCartel(std::string text, int x, int y, bool select);
    void crearCartelVertical(std::string text, int x, int y, bool select);
    void crearColumna(std::string text,rlutil::COLOR cFondo, int x, int y, bool separacion);
    void crearFila(std::string text,rlutil::COLOR cTexto, int x, int y);
};
