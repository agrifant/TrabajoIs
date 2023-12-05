#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>
#include <iostream>
#include <list>

class Actividad{
    private:
        std::string tipo_;
        int id_;
        std::string director_acaemico_;
        std::string nombre_;
        std::string fecha_;
        int aforo_;
        std::string ponentes_;
        std::string tematica_;
        std::string ubicacion_;
        std::string materialNecesario_;
        int nParticipantes_;
        std::list <std::string> lista_participantes_;
    public:
        Actividad(int id,std::string director_academico,std::string nombre="Undefined",std::string fecha="UNdefined", std::string tipo="Undefined", int aforo=0,
        std::string ponentes="Undefined", std::string tematica="Undefined", 
        std::string ubicacion="Undefined",std::string materialNecesario="Undefined",
        int nParticipantes =0, std::list <std::string> lista_participantes={});
        //todos los Gets:
        std::string GetTipo(){return tipo_;}
        std::string GetDirector_academico(){return director_acaemico_;}
        std::string GetNombre(){return nombre_;}
        std::string GetFecha(){return fecha_;}
        int GetAforo(){return aforo_;}
        std::string GetPonentes(){return ponentes_;}
        std::string GetTematica(){return tematica_;}
        std::string GetUbicacion(){return ubicacion_;}
        std::string GetMaterial_necesario(){return materialNecesario_;}
        std::list <std::string> GetLista_participantes(){return lista_participantes_;}
        int GetnParticipantes(){return nParticipantes_;}
        
        //Funciones específicas
        void Mostrar_Calendario();
        void Mostrar_Info_Calendario();
        void añadirParticipantes(char dni[9]);
};

#endif