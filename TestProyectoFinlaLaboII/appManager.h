#pragma once
#include <iostream>

class User{

private:
    std::string MasterUser = "brian";
    std::string MasterPass = "brian";

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
    void Menu();
    void MenuConfig();

};


