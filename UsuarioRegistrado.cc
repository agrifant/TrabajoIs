#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "actividad.h"
#include <string>
#include <vector>

bool inscribirse(char dni[9], Actividad p1){
    //primero vemos si hay hueco
    if((p1.GetAforo()-p1.GetnParticipantes())<=0){
        return false;
    }else{
        //vemos si ya no esta inscrito
        std::vector <std::string> lista_Participantes=p1.GetLista_participantes();
        for(auto & i:lista_Participantes){
            if(i==dni){
                return false;
            }
        }
        // lo añadimos a la actividad
        p1.anadirParticipantes(dni);
        return true;
    }
}