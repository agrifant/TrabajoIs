#ifndef DIRECTORACADEMICO_H
#define DIRECTORACADEMICO_H
#include "usuario.h"
#include <string>
#include <string.h>


class DirectorAcademico : public Usuario{
    private:
        std::string nombre_;
        std::string apellidos_;
        std::string carrera_;
        char dni_[10];
        std::string correo_;
        std::string departamento_;

    public:
        DirectorAcademico(std::string IP_, std::string nombre, std::string apellidos, std::string carrera, char dni[10], 
        std::string correo, std::string departamento) : Usuario(IP_) 
        {nombre_=nombre; apellidos_=apellidos; carrera_=carrera; memcpy(dni,dni_,10); correo_=correo; departamento_=departamento;}
        std::string GetNombre(){return nombre_;}
        std::string GetApellidos(){return apellidos_;}
        std::string GetCarrera(){return carrera_;}
        char* GetDNI(){return dni_;}
        std::string GetCorreo(){return correo_;}
        std::string GetDepartamento(){return departamento_;}

};
#endif
