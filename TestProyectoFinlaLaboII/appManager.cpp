#include "appManager.h"
#include <cstring>
#include "item.h"

bool User::verifyUser(std::string user, std::string pass){
    _nivelUser = 0;

    if(user == MasterUser && pass == MasterPass) _nivelUser = 1;
    if(user == userNormal && pass == passNormal) _nivelUser = 2;

    return _nivelUser;
}

void AppManager::login(){
    std::string user, pass;
    Item item;
    int posx = 50;
    int posy = 13;

    rlutil::cls();
    item.dibujarRectangulo(2,0,30,116);
    item.dibujarRectangulo(41,9,11,36);

    item.mostrarItem("Inicio de sesion: ",posx,posy);
    item.mostrarItem("-------------------",posx,posy+1);
    item.mostrarItem("Legajo: ",posx,posy+2);
    item.mostrarItem("Password: ",posx,posy+3);

    while(true){
        item.eliminarHorizontal(posx+10,16,posy+2);
        item.eliminarHorizontal(posx+10,16,posy+3);

        user = item.ingresarTexto(posx + 10,posy + 2,true);
        pass = item.ingresarTexto(posx + 10,posy + 3,true);

        if(verifyUser(user,pass)) break;
        else{
            item.mostrarItem("Datos incorrectos...",posx,posy+5);
        }

    }

    item.eliminarHorizontal(posx,20,posy+5);
    item.mostrarItem("Ingresando",posx,posy +10);
    item.barraEspera(200);
    item.eliminarHorizontal(posx,22,posy+10);

    switch(User::getNivelUser()){
    case 1:
        MenuAdmin();
        break;
    case 2:
        MenuUser();
        break;
    default:
        exit(100);
        break;
    }

    rlutil::cls();
    exit(0);

}

void AppManager::MenuUser(){
    Item item;
    int opc = 0;
    int posx = 50;
    int posy = 13;

    item.borrarRectangulo(43,11,8,33);

    do{

        item.mostrarItem("REGISTRAR VENTA",posx,posy,opc == 0);
        item.mostrarItem("HISTORIAL DE VENTAS",posx,posy+1,opc == 1);
        item.mostrarItem("CERRAR SESION",posx,posy+2,opc == 2);
        item.mostrarItem("SALIR",posx,posy+3,opc == 3);
        item.mostrarItem(">>",posx-4,posy+opc);

        switch(rlutil::getkey()){
        case 14:    ///sube
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc--;
            if(opc < 0) opc = 3;
            break;
        case 15:    ///baja
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc++;
            if(opc > 3) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 2 )login();
            if(opc == 3 )return;
            break;
        }

    }while(true);
}

void AppManager::MenuAdmin(){
    Item item;
    int opc = 0;
    int posx = 50;
    int posy = 13;

    item.borrarRectangulo(43,11,8,33);

    do{

        item.mostrarItem("REGISTRAR VENTA",posx,posy,opc == 0);
        item.mostrarItem("HISTORIAL DE VENTAS",posx,posy+1,opc == 1);
        item.mostrarItem("CONFIGURACION",posx,posy+2,opc == 2);
        item.mostrarItem("REPORTES",posx,posy+3,opc == 3);
        item.mostrarItem("CERRAR SESION",posx,posy+4,opc == 4);
        item.mostrarItem("SALIR",posx,posy+5,opc == 5);
        item.mostrarItem(">>",posx-4,posy+opc);

        switch(rlutil::getkey()){
        case 14:    ///sube
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc--;
            if(opc < 0) opc = 5;
            break;
        case 15:    ///baja
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc++;
            if(opc > 5) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 2 )Config();
            if(opc == 4 )login();
            if(opc == 5 )return;
            break;
        }

    }while(true);
}

void AppManager::Config(){
    Item item;
    int opc = 0;
    int posx = 50;
    int posy = 12;

    item.borrarRectangulo(43,11,8,33);

    do{

        item.mostrarItem("ALTA DE PRODUCTOS",posx,posy,opc == 0);
        item.mostrarItem("BAJA DE PRODUCTOS",posx,posy+1,opc == 1);
        item.mostrarItem("MODIFICAR STOCK",posx,posy+2,opc == 2);
        item.mostrarItem("MODIFICAR PRECIO",posx,posy+3,opc == 3);
        item.mostrarItem("COPIA DE SEGURIDAD",posx,posy+4,opc == 4);
        item.mostrarItem("RESTABLECER COPIA",posx,posy+5,opc == 5);
        item.mostrarItem("VOLVER",posx,posy+6,opc == 6);
        item.mostrarItem(">>",posx-4,posy+opc);

        switch(rlutil::getkey()){
        case 14:    ///sube
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc--;
            if(opc < 0) opc = 6;
            break;
        case 15:    ///baja
            item.eliminarHorizontal(posx-4,2,posy+opc);
            opc++;
            if(opc > 6) opc = 0;
            break;
        case 1:     ///enter
            item.borrarRectangulo(43,11,8,33);
            if(opc == 6 )return;

            break;
        }

    }while(true);
}
