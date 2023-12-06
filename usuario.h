//esta es la definicion de la clase usuario que utilizaremos para heredar la funcion de ConsultarActividades() a los otros tipos de usuario
#ifndef USUARIO
#define USUARIO
#include <iostream>
#include <string>
#include <vector>

class Usuario{
    private:
    std::string IP;
    public:
    Usuario(std::string IP_){IP=IP_;};//constructor de la clase usuario
    void ConsultarActividades();//funcion principal de la clase que será heredada a las demas clases de tipo usuario
    std::vector<std::string> split(std::string str, char pattern);//Funcion para separar la informacion de una linea String dependiendo de patrones
    
};

#endif