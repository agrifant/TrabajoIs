#include <iostream>
#include <vector>
#include "actividad.h"

Actividad::Actividad(int id,std::string director_academico,std::string nombre,
std::string fecha, std::string tipo, int aforo,
std::string ponentes, std::string tematica,
std::string ubicacion,std::string materialNecesario,
int nParticipantes , std::vector <std::string> lista_participantes): id_(id), 
director_academico_(director_academico), nombre_(nombre), fecha_(fecha),tipo_(tipo), aforo_(aforo),
ponentes_(ponentes),tematica_(tematica), ubicacion_(ubicacion),materialNecesario_(materialNecesario),
nParticipantes_(nParticipantes), lista_participantes_(lista_participantes) {

    
}
        




void Mostrar_Calendario(){

}
void Actividad::Mostrar_Info_Calendario(){//En esta funcion mostramos la info detallada de la ACtividad
    std::cout<<"Informacion de la actividad "<<this->GetNombre()<<std::endl;

    std::cout<<"Id:  "<<this->GetId()<<std::endl;
    std::cout<<"Nombre: "<<this->GetNombre()<<std::endl;
    std::cout<<"Director Academico "<<this->GetDirector_academico()<<std::endl;
    std::cout<<"Fecha: "<<this->GetFecha()<<std::endl;
    std::cout<<"Tipo: "<<this->GetTipo()<<std::endl;
    std::cout<<"Aforo; "<<this->GetAforo()<<std::endl;
    std::cout<<"Ponentes: "<<this->GetPonentes()<<std::endl;
    std::cout<<"Tematica: "<<this->GetTematica()<<std::endl;
    std::cout<<"Ubicacion: "<<this->GetUbicacion()<<std::endl;
    std::cout<<"Material Necesario: "<<this->GetMaterial_necesario()<<std::endl;
    std::cout<<"Numero de Participantes: "<<this->GetnParticipantes()<<std::endl;
    
}

void Actividad::anadirParticipantes(char dni[10]){
    lista_participantes_.push_back(dni);
    nParticipantes_++;
}