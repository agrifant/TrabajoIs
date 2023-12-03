//esta es la definicion de la clase MailList donde guardaremos la informacion sobre las MailList 
//para que puedan ser utilizadas posteriormente por el organizador
#include <iostream>
#include <string>
#include <vector>
#ifndef MAIL_LIST
#define MAIL_LIST

class MailList{
    private:
    std::string IDMailList;
    std::vector<std::string> correoMiembros;
    std::string NombreMailList;

    public:
    MailList(std::string IDMailList_,std::vector<std::string> correoMiembros_,std::string NombreMailList_)
    {IDMailList=IDMailList_;correoMiembros=correoMiembros_,NombreMailList=NombreMailList_;};//constructor de la clase MailList
};

#endif