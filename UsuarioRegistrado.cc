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
    //vemos si la actividad existe enrtre las catividades activas
    if(id>actividadesActivas()||id<=0){
        std::cout<<"Esa actividad no existe\n";
        return false;
    }

    //aberiguamos la actividad que nos ha enviado
    int cont=0;
    for(auto i=datos.begin(); cont!=id_ && datos.end()!=i ;i++){
        if(i->GetActivar()==0){
            id++;
        }else{
            cont++;
        }
        
    }

    Actividad vacio(0,"Nada");
    Actividad *p1=&vacio;
    for(auto & i: datos){
        if(id==i.GetId()){
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