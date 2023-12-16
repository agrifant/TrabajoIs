#include <iostream>
#include <vector>
#include <fstream>
#include "actividad.h"

Actividad::Actividad(int id,std::string director_academico,std::string nombre,
std::string fecha, std::string tipo, int aforo,
std::string ponentes, std::string tematica,
std::string ubicacion,std::string materialNecesario,
int nParticipantes , std::vector <std::string> lista_participantes, int activar): id_(id), 
director_academico_(director_academico), nombre_(nombre), fecha_(fecha),tipo_(tipo), aforo_(aforo),
ponentes_(ponentes),tematica_(tematica), ubicacion_(ubicacion),materialNecesario_(materialNecesario),
nParticipantes_(nParticipantes), lista_participantes_(lista_participantes), activar_(activar) {
    
    
}
        
Actividad Actividad::operator=(const Actividad &a){
    id_=a.id_;
    tipo_=a.tipo_;
    director_academico_=a.director_academico_;
    nombre_=a.nombre_;
    fecha_=a.fecha_;
    aforo_=a.aforo_;
    ponentes_=a.ponentes_;
    tematica_=a.tematica_;
    ubicacion_=a.ubicacion_;
    materialNecesario_=a.materialNecesario_;
    nParticipantes_=a.nParticipantes_;
    lista_participantes_=a.lista_participantes_;
    activar_=a.activar_;
    return *this;
}



void Mostrar_Calendario(){

}
void Actividad::Mostrar_Info_Calendario(){//En esta funcion mostramos la info detallada de la ACtividad
    std::cout<<"Informacion de la actividad "<<this->GetNombre()<<std::endl;

    std::cout<<"Id:  "<<this->GetId()<<std::endl;
    std::cout<<"Nombre: "<<this->GetNombre()<<std::endl;
    std::cout<<"Director Academico "<<this->GetDirector_academico()<<std::endl;
    std::cout<<"Fecha: "<<this->GetFecha()<<std::endl;
    std::cout<<"Tipo: "<<this->GetTipo()<<std::endl;
    std::cout<<"Aforo; "<<this->GetAforo()<<std::endl;
    std::cout<<"Ponentes: "<<this->GetPonentes()<<std::endl;
    std::cout<<"Tematica: "<<this->GetTematica()<<std::endl;
    std::cout<<"Ubicacion: "<<this->GetUbicacion()<<std::endl;
    std::cout<<"Material Necesario: "<<this->GetMaterial_necesario()<<std::endl;
    std::cout<<"Numero de Participantes: "<<this->GetnParticipantes()<<std::endl;
    
}

void Actividad::anadirParticipantes(char dni[10]){
    lista_participantes_.push_back(dni);
    nParticipantes_++;
}

std::vector<Actividad> VectorConActividades(){
    std::vector<Actividad> actividades;//vector en el que guardaremos las actividades del fichero
    std::string linea;//Guardaremos cada linea en esta variable
    std::vector<std::string> datos;//Para guardar la info separada de cada linea
    std::ifstream archivo("../bd/actividades.txt");//Abrimos el archivo para leer su informacion
    int contador = 0;//contador que nos servirá despues para contar el numero de actividades
    int elec;//Para despues elegir que actividad queremos ver su informacion
    while(!archivo.eof())//leemos el archivo hasta llegar a la ultima linea
    {
        contador++;
        getline(archivo,linea);//guardamos la info de una actividad en (linea)
        datos = split(linea,'|');//utilizamos esta funcion para separar el string cada vez que encuentre un |
        std::vector<std::string> ListaP = split(datos[12],'%');//utilizamos esta funcion para separar el string cada vez que encuentre un %

        Actividad auxiliar;//Clase Actividad auxiliar para ir rellenando el vector de Actividades
        auxiliar.setId(stoi(datos[0]));//guardamos la info de cada atributo correspondiente, en el orden adecuado
        auxiliar.setDirectorAcademico(datos[1]);
        auxiliar.setNombre(datos[2]);
        auxiliar.setFecha(datos[3]);
        auxiliar.setTipo(datos[4]);
        auxiliar.setAforo(stoi(datos[5]));
        auxiliar.setPonentes(datos[6]);
        auxiliar.setTematica(datos[7]);
        auxiliar.setUbicacion(datos[8]);
        auxiliar.setMatNecesario(datos[9]);
        auxiliar.setNParticipantes(stoi(datos[10]));
        auxiliar.setActivar(stoi(datos[11]));
        auxiliar.setListaParticipantes(ListaP);

        actividades.push_back(auxiliar);//Añadimos la actividad guardada al vector de actividades
    }
    archivo.close();//Cerramos el archivo de lectura
    actividades.shrink_to_fit();//Elimino los espacios del vector vacios
    return actividades;
}

std::vector<Actividad> VectorConActividadesActivas(){
    std::vector<Actividad> todasActividades=VectorConActividades();
    std::vector <Actividad> actividadesActivas;
    for(auto & i:todasActividades){
        if(i.GetActivar()==1){
            actividadesActivas.push_back(i);
        }
    }
    return actividadesActivas;

}

int actividadesActivas(){
    std::vector<Actividad> todasActividades=VectorConActividades();
    int cont=0;
    for(auto & i:todasActividades){
        if(i.GetActivar()==1){
            cont++;
        }
    }
    return cont;

}

bool guardarVectorActividades(std::vector<Actividad> datos){
    std::ofstream archivo("../bd/actividades.txt",std::ios::trunc);
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
            archivo<<i->GetActivar()<<"|";
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
        

std::vector<std::string> split(std::string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;//vector de strings que vamos a devolver
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);//buscamos el caracter patron
        splitted = str.substr(posInit, posFound - posInit);//Substraemos la cadena
        posInit = posFound + 1;//Movemos la posicion inicial
        results.push_back(splitted);//Guardamos la cadena en el vector resultado
    }
    
    return results;//Lo devolvemos

}

void MostrarActividad(){
    std::vector<Actividad> actividades = VectorConActividades();
    int opcion;
    int id;
    
    for(auto& i: actividades){
        if(i.GetActivar()!=0 && i.GetActivar() !=1){
            std::cout<<"Error al indicar si una actividad está habilitada al público.\n";
        }
        if(i.GetActivar()==0){
            std::cout<<"La actividad " << i.GetNombre() << " con ID " << i.GetId() << " no está activada.\n";
        }
         if(i.GetActivar()==1){
            std::cout<<"La actividad " << i.GetNombre() << " con ID " << i.GetId() << " está activada.\n";
        }
    }

    std::cout<< "Seleccione qué opción desea realizar\n:" << "1. Habilitar una actividad.\n" << "2. Deshabilitar una actividad.\n";
    std::cin >> opcion;
        
    if(opcion!= 1 && opcion != 2){
        std::cout << "Opción inválida. Seleccione otro número\n.";

        if(opcion == 1){
    std::cout<< "Escribe el Identificador de la actividad que quiere habilitar:\n";
    std::cin>> id;

    for(auto& i: actividades){
        if(id==i.GetActivar()){
            i.setActivar(1);
        }
    }
}

        if(opcion == 2){
        std::cout<< "Escribe el Identificador de la actividad que quiere deshabilitar:\n";
    std::cin>> id;

    for(auto& i: actividades){
        if(id==i.GetActivar()){
            i.setActivar(0);
            }
        }
    }
}
}
