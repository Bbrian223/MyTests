#include "item.h"
#include <cstring>


Item::Item(){
    _backgroud = rlutil::COLOR::BLACK;
    _colorText = rlutil::COLOR::WHITE;
    rlutil::setBackgroundColor(_backgroud);
    rlutil::setColor(_colorText);
}

Item::Item(rlutil::COLOR backg, rlutil::COLOR cText){
    setBackgroundColor(backg);
    setColorText(cText);
}

void Item::setBackgroundColor(rlutil::COLOR backg){
    _backgroud = backg;
    rlutil::setBackgroundColor(_backgroud);
}

void Item::setColorText(rlutil::COLOR cText){
    _colorText = cText;
    rlutil::setColor(_colorText);
}

void Item::mostrarItem(std::string text, int x, int y){
    rlutil::hidecursor();       //esconde el cursor
    rlutil::locate(x,y);
    std::cout<<text;
}

std::string Item::ingresarTexto(int x, int y, bool cursorOn){
    std::string text = "NULL";

    if(cursorOn) rlutil::CursorHider();
    else rlutil::hidecursor();

    rlutil::locate(x,y);
    getline(std::cin,text);

    return text;
}

void Item::eliminarHorizontal(int x, int largo, int y){
    rlutil::locate(x,y);

    for(int i=0; i<largo; i++){
        std::cout<<" ";
    }
}

void Item::barraEspera(int time){

    for(int i=0; i<7; i++){
        rlutil::msleep(time);
        std::cout<<". ";
    }
}

void Item::barraEspera(int time, int x, int y){
    int aux = time/35;
    rlutil::setBackgroundColor(rlutil::COLOR::CYAN);


    for(int i=0; i<35; i++){
        rlutil::msleep(time);
        mostrarItem(" ",x-8+i,y);
        time -= aux;
    }

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void Item::dibujarRectangulo(int x, int y, int alto, int ancho){
    COORD coord;

    for (int i = 0; i < alto; i++) {

		for (int j = 0; j < ancho; j++) {

            coord.X = x+j;
            coord.Y = y+i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

			if (i == 0 && j == 0)std::cout << char(201);
			if (i == 0 && j == ancho - 1)std::cout << char(187);

			if (i == alto - 1 && j == 0)std::cout << char(200);
			if (i == alto - 1 && j == ancho - 1)std::cout << char(188);

			if ((j == 0 || j == ancho - 1) && i > 0 && i < alto - 1){
                std::cout << char(186);//179
            }
			if ((i == 0 || i == alto - 1) && j > 0 && j < ancho - 1){
				std::cout << char(205);//196
			}
		}
	}
}

void Item::pintarRectangulo(int x, int y, int alto, int ancho){

    for(int i=y; i<=y+alto; i++){
        eliminarHorizontal(x,ancho,i);
    }

}

void Item::pintarRectangulo(int x, int y, int alto, int ancho, rlutil::COLOR cFondo){
    rlutil::setBackgroundColor(cFondo);

    for(int i=y; i<=y+alto; i++){
        eliminarHorizontal(x,ancho,i);
    }

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void Item::crearCartel(std::string text, int x, int y, bool select){
    int tam = strlen(text.c_str());
    int x_text = (x+13)-(tam/2);

    if(select)rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);

    dibujarRectangulo(x,y,3,26);
    eliminarHorizontal(x+2,24,y+2);
    mostrarItem(text,x_text,y+2);

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void Item::crearCartelVertical(std::string text, int x, int y, bool select){
    if(select)rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);

    dibujarRectangulo(x,y,5,5);
    pintarRectangulo(x+2,y+2,2,3);
    mostrarItem(text,x+3,y+3);

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void Item::crearColumna(std::string texto,rlutil::COLOR cFondo, int x, int y, bool separacion){
    int y_max = 30;
    int x_final = x + strlen(texto.c_str()) + 1;
    rlutil::setBackgroundColor(cFondo);

    mostrarItem(texto,x,y);

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);

    if(!separacion) return;

    for(int i=y; i<y_max; i++){
        mostrarItem("|",x_final,i);
    }
}

void Item::crearFila(std::string text,rlutil::COLOR cTexto, int x, int y){
    rlutil::setColor(cTexto);
    mostrarItem(text,x,y);
    rlutil::setColor(rlutil::COLOR::WHITE);
}








