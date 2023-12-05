#include <iostream>
#include <list>
#include "actividad.h"
void Mostrar_Calendario(){

}
void Mostrar_Info_Calendario(){
    
}

void Actividad::añadirParticipantes(char dni[9]){
    lista_participantes_.push_back(dni);
    nParticipantes_++;
}