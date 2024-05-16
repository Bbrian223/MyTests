#include "appManager.h"
#include <cstring>
#include "item.h"

bool User::verifyUser(std::string user, std::string pass){
    _nivelUser = 0;

    if(user == MasterUser && pass == MasterPass) _nivelUser = 1;
    if(user == userNormal && pass == passNormal) _nivelUser = 2;

    return _nivelUser;
}


///-------------------------
void AppManager::login(){
    std::string user, pass;
    Item item;

    item.dibujarRectangulo(23,5,12,32);

    do{
        item.eliminarHorizontal(40,54,12);
        item.eliminarHorizontal(40,54,13);

        item.mostrarItem("Inicio de sesion: ",30,10);
        item.mostrarItem("-------------------",30,11);
        item.mostrarItem("Usuario: ",30,12);
        item.mostrarItem("Password: ",30,13);

        user = item.ingresarTexto(40,12,on);
        pass = item.ingresarTexto(40,13,on);
        rlutil::hidecursor();

        if(verifyUser(user,pass)) break;
        else{
            item.mostrarItem("Datos incorrectos...",30,15);
        }

    }while(true);
    item.eliminarHorizontal(30,50,15);
    item.mostrarItem("ingresando",30,20);
    item.barraEspera(200);
    rlutil::cls();
    Menu();

}

void AppManager::Menu(){
    Item item;
    rlutil::hidecursor();

    do{

        item.mostrarItem("Opcion 1",30,10);
        item.mostrarItem("Opcion 2",30,11);
        item.mostrarItem("Opcion 3",30,12);
        item.mostrarItem("opcion 4",30,13);


    }while(true);
}


