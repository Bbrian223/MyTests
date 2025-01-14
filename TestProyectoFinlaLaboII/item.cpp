#include "item.h"


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

void Item::mostrarItem(std::string text, int x, int y, bool select){
    rlutil::hidecursor();

    if(select) rlutil::setBackgroundColor(rlutil::COLOR::LIGHTBLUE);
    else{
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }

    rlutil::locate(x,y);
    std::cout<<text;

    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
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

    for(int i=x; i<=x+largo; i++){
        std::cout<<" ";
    }
}

void Item::barraEspera(int time){

    for(int i=0; i<7; i++){
        rlutil::msleep(time);
        std::cout<<". ";
    }
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

void Item::borrarRectangulo(int x, int y, int alto, int ancho){

    for(int i=y; i<=y+alto; i++){
        eliminarHorizontal(x,ancho,i);
    }

}


