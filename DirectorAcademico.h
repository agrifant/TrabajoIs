#ifndef DIRECTORACADEMICO_H
#define DIRECTORACADEMICO_H
#include "usuario.h"
#include <string>

class DirectorAcademico : public Usuario{
    private:
        std::string nombre_;
        std::string apellidos_;
        std::string carrera_;
        char[9] dni_;
        std::string correo_;
        std::string departamento_;

    public:
        DirectorAcademico(std::string IP_, std::string nombre, std::string apellidos, std::string carrera, char[9] dni, std::string correo, std::string departamento) :  
        {nombre_=nombre; apellidos_=apellidos; carrera_=carrera; dni_=dni; correo_=correo; departamento_=departamento;}
        std::string GetNombre(return nombre_;)
        std::string GetApellidos(return Apellidos_;)
        std::string GetCarrera(return Carrera_;)
        char[9] GetDNI(return dni_;)
        std::string GetCorreo(return Correo_;)
        std::string GetDepartamento(return Departamento_;)

};
#endif
