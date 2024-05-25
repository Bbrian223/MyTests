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
        rlutil::hidecursor();

        if(usuario.verifyUser(user,pass)) break;
        else{
            rlutil::setBackgroundColor(rlutil::COLOR::RED);
            item.mostrarItem("Datos incorrectos...",posx,posy+5);
            rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        }

    }

    item.eliminarHorizontal(posx,20,posy+5);
    item.mostrarItem("Ingresando",posx+5,posy +10);
    item.barraEspera(80,posx,posy+12);

    switch(usuario.getNivelUser()){
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
    int x = 4;
    int y = 5;

    item.pintarRectangulo(40,9,18,40);
    item.dibujarRectangulo(2,0,30,30);
    TablaPrecios();                     //provisoria

    do{

        item.crearCartel("REGISTRAR VENTA",x,y,opc == 0);
        item.crearCartel("HISTORIAL DE VENTAS",x,y+3,opc == 1);
        item.crearCartel("CERRAR SESION",x,y+6,opc == 2);
        item.crearCartel("SALIR",x,y+9,opc == 3);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 3;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 3) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 0) Venta();
            if(opc == 1) Historial();
            if(opc == 2 )login();
            if(opc == 3 )return;

            TablaPrecios();
            break;
        }

    }while(true);
}

void AppManager::MenuAdmin(){
    Item item;
    int opc = 0;
    int x = 4;
    int y = 5;

    item.pintarRectangulo(40,9,18,40);
    item.dibujarRectangulo(2,0,30,30);
    TablaPrecios();                         //provisoria

    do{

        item.crearCartel("REGISTRAR VENTA",x,y,opc == 0);
        item.crearCartel("HISTORIAL DE VENTAS",x,y+3,opc == 1);
        item.crearCartel("CONFIGURACION",x,y+6,opc == 2);
        item.crearCartel("REPORTES",x,y+9,opc == 3);
        item.crearCartel("CERRAR SESION",x,y+12,opc == 4);
        item.crearCartel("SALIR",x,y+15,opc == 5);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 5;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 5) opc = 0;
            break;
        case 1:     ///enter
            if(opc == 0) Venta();
            if(opc == 1) Historial();
            if(opc == 2) Config();
            if(opc == 3) Reportes();
            if(opc == 4) login();
            if(opc == 5) return;

            TablaPrecios();
            break;
        }

    }while(true);
}

void AppManager::Config(){
    Item item;
    int opc = 0;
    int x = 4;
    int y = 5;

    item.pintarRectangulo(4,2,25,26);
    item.pintarRectangulo(34,2,27,80);

    do{
        item.crearCartel("ALTA PRODUCTOS",x,y,opc == 0);
        item.crearCartel("BAJA PRODUCTOS",x,y+3,opc == 1);
        item.crearCartel("MODIFICAR STOCK",x,y+6,opc == 2);
        item.crearCartel("MODIFICAR PRECIO",x,y+9,opc == 3);
        item.crearCartel("MODIFICAR USUARIOS",x,y+12,opc == 4);
        item.crearCartel("COPIA DE SEGURIDAD",x,y+15,opc == 5);
        item.crearCartel("RESTABLECER COPIA",x,y+18,opc == 6);
        item.crearCartel("VOLVER",x,y+21,opc == 7);

        switch(rlutil::getkey()){
        case 14:    ///sube
            opc--;
            if(opc < 0) opc = 7;
            break;
        case 15:    ///baja
            opc++;
            if(opc > 7) opc = 0;
            break;
        case 1:     ///enter

            if(opc == 1)BajaProd();

            if(opc == 7 ){
                item.pintarRectangulo(4,2,27,27);
                return;
            }


            break;
        }

    }while(true);
}

void AppManager::Venta(){
    std::string producto, cantidad;
    Item item;
    int opc = 0;
    int x = 4;
    int y = 5;
    bool ingreso = false;

    item.pintarRectangulo(4,2,25,27);

    item.mostrarItem("Legajo cajero:",x,y);
    item.mostrarItem((usuario.getNivelUser() == 1 ? "ADMIN":"USUARIO"),23,y);   //legajo usuario actual

    item.mostrarItem("Fecha:",x,y+2);
    item.mostrarItem("01/01/1900",21,y+2);  //fecha actual

    item.mostrarItem("Hora: ",x,y+4);
    item.mostrarItem("10:00 PM",23,y+4);    //hora actual

    item.mostrarItem("producto:",x,y+6);
    item.mostrarItem("cantidad:",x,y+8);
    item.mostrarItem("Precio:",x,y+10);

    while(true){

        item.crearCartel("AGREGAR PRODUCTO",x,y+12,opc == 0);
        item.crearCartel("MODIFICAR PRODUCTO",x,y+15,opc == 1);
        item.crearCartel("FINALIZAR VENTA",x,y+18,opc == 2);

        if(!ingreso){
            producto = item.ingresarTexto(x+17,y+6,true);
            cantidad = item.ingresarTexto(x+17,y+8,true);
            item.mostrarItem("$100.5",x+20,y+10);   //precio actual
            rlutil::hidecursor();
            ingreso = true;
        }

        switch(rlutil::getkey()){
        case 14:
            opc--;
            if(opc < 0) opc = 2;
            break;
        case 15:
            opc++;
            if(opc > 2) opc = 0;
            break;
        case 1:
            if(opc == 0){
                ///guarda el prod actual
                item.pintarRectangulo(20,y+6,4,12);
                ingreso = false;
            }

            if(opc == 1) {
                item.pintarRectangulo(20,y+6,4,12);
                ingreso = false;

            }

            if(opc == 2){
                ///guardar prod actual
                item.pintarRectangulo(4,2,25,27);
                return;
            }
            break;
        }


    }

}

void AppManager::TablaPrecios(){
    Item item;
    char alta[2] = {(char)30,'\0'};
    char baja[2] = {(char)31,'\0'};

    int x = 38;
    int y = 4;
    int contFilas = 0;
    bool status = false;
    rlutil::COLOR indicador;

    ///--------datos simulados------
    std::string bebidas[10]={
        "Whisky","Cerveza","Vinos",
        "Espumantes","Vodka","Ron",
        "Aperitivos","Tragos",
        "Cocteles","Comida"
    };
    std::string aux = "bebida";

    int elem[10] = {3,5,4,6,4,2,7,5,8,5};
    ///-------------------------

    item.pintarRectangulo(x,2,0,x+37,rlutil::COLOR::LIGHTRED);

    for(int i=x; i<91; i+=26){
        item.crearColumna("Bebida",rlutil::COLOR::LIGHTRED,i,2,false);
        item.crearColumna(" %Osc",rlutil::COLOR::LIGHTRED,i+8,2,false);
        item.crearColumna("PreUlt",rlutil::COLOR::LIGHTRED,i+16,2,i < 90);
    }


    for(int i=0; i<10; i++){
        if(contFilas > 28) {
            x += 26;
            y = 4;
        }

        item.crearFila(bebidas[i],rlutil::COLOR::LIGHTCYAN,x,y);
        item.crearFila("-----------------------",rlutil::COLOR::WHITE,x,++y);

        for(int j=0; j<elem[i];j++){
            if(contFilas == 29) {
                x += 26;
                y = 4;
            }

            if(status) indicador = rlutil::COLOR::GREEN;
            else indicador = rlutil::COLOR::RED;

            item.crearFila("bebida",rlutil::COLOR::WHITE,x,++y);
            item.crearFila("123,5",rlutil::COLOR::WHITE,x+16,y);
            item.crearFila((status == true ? alta : baja),indicador,x+13,y);
            item.crearFila("%1,25",indicador,x+8,y);

            status = !status;
            contFilas = y;
        }

        y += 2;
        contFilas = y;
    }
}

void AppManager::Historial(){
    Item item;
    int opc = 0;
    char arriba[2] = {(char)30,'\0'};
    char abajo[2] = {(char)31,'\0'};

    item.pintarRectangulo(34,2,27,80);

    while(true){

        item.crearCartelVertical(arriba,112,8,opc == 1);
        item.crearCartelVertical(abajo,112,14,opc == 2);

        item.crearCartel("Hoy",33,1,opc == 3);
        item.crearCartel("Ultimos 15 dias",61,1,opc == 4);
        item.crearCartel("Ultimos 30 dias",89,1,opc == 5);

        switch(rlutil::getkey()){
        case 14:        //arriba
            opc = 1;
            break;
        case 15:
            opc = 2;
            break;
        case 17:
            if(opc < 3) opc = 5;
            else{
                opc++;
                if(opc > 5) opc = 5;
            }
            break;
        case 16:
            if(opc < 3) opc = 3;
            else{
                opc--;
                if(opc < 3) opc = 3;
            }
            break;
        case 0:
            item.pintarRectangulo(34,2,27,84);
            return;
            break;
        }
    }
}

void AppManager::AltaProd(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::BajaProd(){
    Item item;
    int x=50;
    int y=10;

    item.pintarRectangulo(34,2,27,80);
    item.crearCartel("hola",x,y,true);
    rlutil::anykey();
}

void AppManager::ModStock(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::ModPrecio(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::GenerarBackup(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::CargarBackup(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}

void AppManager::Reportes(){
    Item item;
    item.pintarRectangulo(34,2,27,80);
    rlutil::anykey();
}


