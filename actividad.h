#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>
#include <iostream>
#include <vector>

class Actividad{
    private:
        std::string tipo_;
        int id_;
        std::string director_academico_;
        std::string nombre_;
        std::string fecha_;
        int aforo_;
        std::string ponentes_;
        std::string tematica_;
        std::string ubicacion_;
        std::string materialNecesario_;
        int nParticipantes_;
        std::vector <std::string> lista_participantes_;
        int activar_;

    public:
        Actividad(){};
        Actividad(int id,std::string director_academico,std::string nombre="Undefined",std::string fecha="UNdefined", std::string tipo="Undefined", int aforo=0,
        std::string ponentes="Undefined", std::string tematica="Undefined", 
        std::string ubicacion="Undefined",std::string materialNecesario="Undefined",
        int nParticipantes =0, std::vector <std::string> lista_participantes={}, int activar=0);
        //todos los Gets:
        int GetId(){return id_;}
        std::string GetTipo(){return tipo_;}
        std::string GetDirector_academico(){return director_academico_;}
        std::string GetNombre(){return nombre_;}
        std::string GetFecha(){return fecha_;}
        int GetAforo(){return aforo_;}
        std::string GetPonentes(){return ponentes_;}
        std::string GetTematica(){return tematica_;}
        std::string GetUbicacion(){return ubicacion_;}
        std::string GetMaterial_necesario(){return materialNecesario_;}
        std::vector <std::string> GetLista_participantes(){return lista_participantes_;}
        int GetnParticipantes(){return nParticipantes_;}
        int GetActivar(){return activar_;}
        
        //Todos los setters
        void setId(int id){Actividad::id_=id;}
        void setAforo(int aforo){Actividad::aforo_=aforo;}
        void setDirectorAcademico(std::string DirAcad){Actividad::director_academico_=DirAcad;}
        void setNombre(std::string nombre){Actividad::nombre_=nombre;}
        void setFecha(std::string fecha){Actividad::fecha_=fecha;}
        void setTipo(std::string tipo){Actividad::tipo_=tipo;}
        void setPonentes(std::string ponentes){Actividad::ponentes_=ponentes;}
        void setTematica(std::string tematica){Actividad::tematica_=tematica;}
        void setUbicacion(std::string ubicacion){Actividad::ubicacion_=ubicacion;}
        void setMatNecesario(std::string matnec){Actividad::materialNecesario_=matnec;}
        void setNParticipantes(int nparticipantes){Actividad::nParticipantes_=nparticipantes;}
        void setListaParticipantes(std::vector<std::string> Lpanticipantes){Actividad::lista_participantes_=Lpanticipantes;}
        void setActivar(int activar){Actividad::activar_=activar;}
        

        Actividad operator=(const Actividad &a);
        //Funciones específicas
        void Mostrar_Calendario();
        void Mostrar_Info_Calendario();
        void anadirParticipantes(char dni[10]);
};

void MostrarActividad();
std::vector<Actividad> VectorConActividades();
std::vector<std::string> split(std::string str, char pattern);
bool guardarVectorActividades(std::vector<Actividad> datos);
std::vector<Actividad> VectorConActividadesActivas();
int actividadesActivas();

#endif