#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "actividad.h"
#include "usuario.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

bool inscribirse(int id, char dni[10]){
    std::vector <Actividad> datos=VectorConActividades();
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
        //vemos si ya no esta inscrito
        std::vector <std::string> lista_Participantes=p1->GetLista_participantes();
        for(auto & i:lista_Participantes){
            if(i==dni){
                std::cout<<"Ya inscrito\n";
                return false;
            }
        }
        // lo añadimos a la actividad
        p1->anadirParticipantes(dni);

        //tenemos que guardar la informacion en el fichero

        std::ofstream archivo("actividades.txt",std::ios::trunc);
        if(!archivo.is_open()){
            std::cout<<"Error interno, sentimos las molestias\n";
            return false;
        }
        for(auto i=datos.begin(); i!=datos.end();i++){
            archivo<<i->GetId()<<"|";
            archivo<<i->GetDirector_academico()<<"|";
            archivo<<i->GetNombre()<<"|";
            archivo<<i->GetFecha()<<"|";
            archivo<<i->GetTipo()<<"|";
            archivo<<i->GetAforo()<<"|";
            archivo<<i->GetPonentes()<<"|";
            archivo<<i->GetTematica()<<"|";
            archivo<<i->GetUbicacion()<<"|";
            archivo<<i->GetMaterial_necesario()<<"|";
            archivo<<i->GetnParticipantes()<<"|";
            std::vector <std::string> lista=i->GetLista_participantes();
            for(auto b=lista.begin(); b!=lista.end(); b++){
                if(b==(lista.end()-1) && i==(datos.end()-1)){ 
                    archivo<<*b;
                }else{
                    if(b==(lista.end()-1)){
                        archivo<<*b<<"\n";
                    }else{
                        archivo<<*b<<"%";
                    }
                    
                }
                
            }
            
        }

        archivo.close();

        return true;
    }
}