//esta es la definicion de la clase ORGANIZADOR que utilizaremos para heredar la funcion de ConsultarActividades() a los otros tipos de ORGANIZADOR
#include <iostream>
#include <string>
#include "usuario.h"
#ifndef ORGANIZADOR
#define ORGANIZADOR

class Organizador : public Usuario{
    private:
    std::string Nombre;
    std::string Apellidos;
    std::string correo;
    char DNI[9];
    
    public:
    Organizador(std::string IP_,std::string Nombre_,std::string Apellidos_,std::string correo_,char DNI_[9]) : Usuario(IP_)
    {Nombre=Nombre_;Apellidos=Apellidos_;memcpy(DNI,DNI_,9);};//constructor de la clase ORGANIZADOR
    
    bool CrearActividad();//funcion del organizador para crear una nueva actividad
    bool ActualizarActividad(int id);//funcion del organizador para actulizar la informacion de una actividad
    bool EliminarActividad(int id);//funcion para eliminar una actividad del sistema
    bool MostrarActividad(int id);//funcion para "Activar" una actividad y que se muestre en el calendario de actividades a los usuarios
    bool CrearMailList();//funcion para crear una nueva maillist que el organizador utilizará para promover una actividad
    bool GenerarAsistencia(int id);//funcion para generar la asistencia de una actividad en concreto
};

#endif
