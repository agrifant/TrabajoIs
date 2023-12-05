#include <iostream>
#include <list>
#include "actividad.h"

Actividad::Actividad(int id,std::string director_academico,std::string nombre,
std::string fecha, std::string tipo, int aforo,
std::string ponentes, std::string tematica,
std::string ubicacion,std::string materialNecesario,
int nParticipantes , std::list <std::string> lista_participantes): id_(id), 
director_acaemico_(director_academico), nombre_(nombre), fecha_(fecha),tipo_(tipo), aforo_(aforo),
ponentes_(ponentes),tematica_(tematica), ubicacion_(ubicacion),materialNecesario_(materialNecesario),
nParticipantes_(nParticipantes), lista_participantes_(lista_participantes) {

    
}
        




void Mostrar_Calendario(){

}
void Mostrar_Info_Calendario(){
    
}

void Actividad::añadirParticipantes(char dni[9]){
    lista_participantes_.push_back(dni);
    nParticipantes_++;
}