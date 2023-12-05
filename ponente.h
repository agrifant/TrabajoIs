#ifndef PONENETE_H
#define PONENETE_H
#include <string>
#include <list>

//todos los parámetros que los ponentes tienen
struct ponente{
    std::string nombre;
    std::string apellidos;
    char dni[9];
    std::string correo;
};

class Ponenetes{
    private:
        //id de la lista que estamos usando
        int id_;
        //lista que guarda los ponentes
        std::list<ponente> list_ponentes_;
    public:
        Ponenetes(int id):id_(id){}
        std::list<ponente> Getlist_ponentes(){return list_ponentes_;}
};

#endif