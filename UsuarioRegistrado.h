#ifndef USUARIOREGISTRADO_H
#define USUARIOREGISTRADO_H
#include "usuario.h"
#include "actividad.h"
#include <string>
#include <string.h>
#include <iostream>

class UsuarioRegistrado : public Usuario{
    private:
        std::string nombre_;
        std::string apellidos_;
        char dni_[10];
        std::string correo_;
               
    public:
        UsuarioRegistrado(std::string IP_, std::string nombre, std::string apellidos, char dni[10], std::string correo) : Usuario(IP_)
        {nombre_=nombre; apellidos_=apellidos; memcpy(dni_,dni,10); correo_=correo;}
        std::string GetNombre(){return nombre_;}
        std::string GetApellidos(){return apellidos_;}
        char* GetDNI(){return dni_;}
        std::string GetCorreo(){return correo_;}
        //los set
        void SetNombre(std::string nombre){nombre_=nombre;}
        void SetApellidos(std::string apellidos){apellidos_=apellidos;}
        void SetDni(char * dni){strcpy(dni_,dni);}
        void SetCorreo(std::string correo){correo_=correo;}
};


    bool inscribirse(int id, char dni[10]);
#endif
