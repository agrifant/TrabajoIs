
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "actividad.h"
#include "usuario.h"
#include <vector>
std::vector<std::string> split(std::string str, char pattern);

void Usuario::ConsultarActividades(int status) {
    std::vector<Actividad> actividades;//vector en el que guardaremos las actividades del fichero
    std::string linea;//Guardaremos cada linea en esta variable
    std::vector<std::string> datos;//Para guardar la info separada de cada linea
    std::ifstream archivo("../bd/actividades.txt");//Abrimos el archivo para leer su informacion
    int contador = 0;//contador que nos servirá despues para contar el numero de actividades
    int elec;//Para despues elegir que actividad queremos ver su informacion
    while(!archivo.eof())//leemos el archivo hasta llegar a la ultima linea
    {
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

        if (status > 1)
        {
            std::cout<<"Estoy aqui"<<std::endl;
            actividades.push_back(auxiliar);//Añadimos la actividad guardada al vector de actividades
            contador++;
        }
        else
        {
            if (auxiliar.GetActivar() == 1)
            {
                actividades.push_back(auxiliar);//Añadimos la actividad guardada al vector de actividades
                contador++;
            }
        }

        
    }
    archivo.close();//Cerramos el archivo de lectura
    actividades.shrink_to_fit();//Elimino los espacios del vector vacios
    for (int i = 0; i<contador;i++)//Creo un menu con el For
        {
            std::cout<<(i+1)<<". "<<actividades[i].GetNombre()<<std::endl;
        }
    
    std::cout<<"Que actividad quieres visitar: ";
    std::cin>>elec;//Recogemos su eleccion
    actividades[elec-1].Mostrar_Info_Calendario();//Llamamos a la funcion para mostrar toda la informacion de la actividad escogida
}

//Esta funcion la utilizamos para sacar la info de los archivos, separando cada linea por un simbolo particular
std::vector<std::string> Usuario::split(std::string str, char pattern) {
    
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