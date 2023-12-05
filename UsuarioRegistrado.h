#ifndef USUARIOREGISTRADO_H
#define USUARIOREGISTRADO_H
#include "usuario.h"
#include "actividad.h"
#include <string>

class UsuarioRegistrado : public Usuario{
    private:
        std::string nombre_;
        std::string apellidos_;
        char dni_[9];
        std::string correo_;
               
    public:
        DirectorAcademico(std::string IP_, std::string nombre, std::string apellidos, char dni[9], std::string correo) : Usuario(IP_)
        {nombre_=nombre; apellidos_=apellidos; dni_=dni; correo_=correo;}
        std::string GetNombre(return nombre_;)
        std::string GetApellidos(return Apellidos_;)
        char[9] GetDNI(return dni_;)
        std::string GetCorreo(return Correo_;)

        //funcion de inscribirse(recibe el dni del usuario, el id de la actividad)
        bool inscribirse(char dni[9], Actividad p1);
}
#endif
