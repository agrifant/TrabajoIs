#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H
#include <string>

class Actividad{
    private:
        std::string tipo_;
        int id;
        std::string director_acaemico_;
        std::string nombre_;
        std::string fecha_;
        int aforo_;
        std::string ponentes_;
        std::string tematica_;
        std::string ubicacion_;
        std::string materialNecesario_;
        int nParticipantes_;
    public:
        void Mostrar_Calendario();
        void Mostrar_Info_Calendario();
};

#endif