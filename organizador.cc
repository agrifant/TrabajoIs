#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string.h>
#include "usuario.h"
#include "organizador.h"
#include "actividad.h"
#include "UsuarioRegistrado.h"

bool Organizador::GenerarAsistencia(int id)
{
    int check = false;
    char DNIaux[10];
    std::string linea;
    std::vector<UsuarioRegistrado> UsuariosBD;
    std::vector<std::string> datosUsuarios;
    std::vector <Actividad> datos=VectorConActividades();
    std::vector<std::string> dnisParticipantes;
    for (int i =0;i<datos.size();i++)
    {
        if (id == datos[i].GetId())
        {
            check=true;
            dnisParticipantes = datos[i].GetLista_participantes();

            std::ifstream archivo("usuarios.txt");
            while(!archivo.eof())//leemos el archivo hasta llegar a la ultima linea
            {
            //contador++;
            getline(archivo,linea);//guardamos la info de una usuarios en (linea)
            datosUsuarios = split(linea,'|');//utilizamos esta funcion para separar el string cada vez que encuentre un |

            UsuarioRegistrado auxiliar;//Clase usuarios registrados auxiliar para ir rellenando el vector de usuarios
            auxiliar.SetNombre(datosUsuarios[3]);//guardamos la info de cada atributo correspondiente, en el orden adecuado
            auxiliar.SetApellidos(datosUsuarios[4]);
            auxiliar.SetDni(strcpy(DNIaux,datosUsuarios[5].c_str()));
            auxiliar.SetCorreo(datosUsuarios[6]);

            UsuariosBD.push_back(auxiliar);//Añadimos la actividad guardada al vector de usuarios
            }
            archivo.close();//Cerramos el archivo de lectura
            UsuariosBD.shrink_to_fit();//Elimino los espacios del vector vacios
            if (datos[i].GetActivar() == 0)
            {
                check = false;
                std::cout<<"La actividad seleccionada no esta activa y por lo tanto, no tiene participantes"<<std::endl;
            }
            else
            {
            //AHORA RECORREMOS EL VECTOR DE USUARIOS REGISTRADOS Y PONEMOS LA INFO DE LOS USUARIOS QUE ESTAN INSCRITOS
            std::cout<<"-----------USUARIOS INSCRITOS-----------"<<std::endl;
            for (int j = 0; j<dnisParticipantes.size();j++)
            {
                //strcpy(DNIaux,dnisParticipantes[j].c_str());
                for (int k = 0;k<UsuariosBD.size();k++)
                {
                    std::string auxconvert = UsuariosBD[k].GetDNI();
                    if (auxconvert==dnisParticipantes[j])//strcmp(DNIaux,UsuariosBD[k].GetDNI())
                    {
                        std::cout<<UsuariosBD[k].GetNombre();
                        std::cout<<" "<<UsuariosBD[k].GetApellidos();
                        std::cout<<", Correo: "<<UsuariosBD[k].GetCorreo();
                        std::cout<<", DNI: "<<UsuariosBD[k].GetDNI()<<std::endl;
                    }
                }
            }
            }
        }
    }

    return check;
}