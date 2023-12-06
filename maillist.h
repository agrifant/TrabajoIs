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

    //Getters
    std::string GetIDMailList(){this->IDMailList;}
    std::string GetNombreMailList(){this->NombreMailList;}
    std::vector<std::string> GetCorreoMiembros(){this->correoMiembros;}
    //Setters
    void SetIDMailList(std::string id){this->IDMailList = id;}
    void SetNombreMailList(std::string nmaillist){this->NombreMailList = nmaillist;}
    void SetCorreoMiembros(std::vector<std::string> correos){this->correoMiembros=correos;}
};

#endif