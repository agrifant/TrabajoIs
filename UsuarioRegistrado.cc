#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "actividad.h"
#include "usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

bool UsuarioRegistrado::inscribirse(int id_){
    std::vector <Actividad> datos=VectorConActividades();
    std::vector<Actividad> lista_activos= VectorConActividadesActivas();
    int id=id_;
    int cont=0;

    //aberiguamos la actividad que nos ha enviado
    for(auto i=datos.begin(); datos.end()!=i && cont!=id ;i++){

        if(i->GetActivar()==0){
            id++;
        }
        cont++;
        
    }
    Actividad vacio(0,"Nada");
    Actividad *p1=&vacio;
    cont=0;
    for(auto & i: datos){
        cont++;
        if(id==cont){
            p1=&i;
        }
    }
    //vemos si existe la actividad en la base de datos
    if(p1->GetId()==0){
        std::cout<<"La actividad no existe\n";
        return false;
    }
    // vemos si hay hueco
    if((p1->GetAforo()-p1->GetnParticipantes())<=0){
        std::cout<<p1->GetAforo()<<"-"<<p1->GetnParticipantes()<<" por lo que no es posible\n";
        return false;
    }else{
        std::vector <std::string> lista_Participantes=p1->GetLista_participantes();

        //vemos si ya no esta inscrito
        for(auto & i:lista_Participantes){
            if(i==dni_){
                std::cout<<"Ya inscrito\n";
                return false;
            }
        }
        //vemos si la actividad esta activada
        if(0==p1->GetActivar()){
            std::cout<<"Actividad inexistente\n";
;            return false;
        }
        // lo añadimos a la activida
        p1->anadirParticipantes(dni_);

        //tenemos que guardar la informacion en el fichero

        return guardarVectorActividades(datos);
    }
}