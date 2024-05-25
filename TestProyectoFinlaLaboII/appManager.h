#pragma once
#include <iostream>

class User{

private:
    /// provicional a modo prueba
    std::string MasterUser = "admin";
    std::string MasterPass = "admin";

    std::string userNormal = "user";
    std::string passNormal = "pass";
    int _nivelUser;

protected:
    bool verifyUser(std::string user, std::string pass);
    std::string getMasterUser(){return MasterUser;}
    std::string getMasterPass(){return MasterPass;}
    int getNivelUser(){return _nivelUser;}
};


class AppManager:public User{

public:

    void login();
    void MenuAdmin();
    void MenuUser();
    void Config();

};


