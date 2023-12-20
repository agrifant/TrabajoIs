#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "organizador.h"
#include "DirectorAcademico.h"
#include "actividad.h"
#include <string>
#include <fstream>
#include <vector>

int status=0;
std::string ip="100.100.100";

UsuarioRegistrado *cliente;
DirectorAcademico *cliente2;
Organizador * cliente3;

struct usuariosBd{
    int poder;
    std::string usuairo;
    std::string password;
};

bool inciarSesion(std::string usuario, std::string password){
    struct usuariosBd usus;
    std::string linea;
    std::vector<std::string>datos;
    std::ifstream archivo("../bd/usuarios.txt");
    if(!archivo.is_open()){
        std::cout<<"Error interno, sentimos las molestias\n";
        return false;
    }

    struct usuariosBd i;
    while(!archivo.eof()){
        getline(archivo,linea);
        datos=split(linea, '|');
        i.poder=stoi(datos[0]);
        i.usuairo=datos[1];
        i.password=datos[2];

        if(datos[1]==usuario && datos[2]==password){
            status=stoi(datos[0]);
            char dni[10];
            if((stoi(datos[0])==1)){
                strcpy(dni,datos[5].c_str());
                cliente=new UsuarioRegistrado(ip,datos[3],datos[4],dni,datos[6]);
                std::cout<<"\nBuenas "<<cliente->GetNombre()<<"\n";
            }
            if((stoi(datos[0])==2)){
                strcpy(dni,datos[6].c_str());
                cliente2 =new DirectorAcademico(ip,datos[3],datos[4],datos[5],dni,datos[7], datos[8]);
                std::cout<<"\nBuenas director academico "<<cliente2->GetNombre()<<"\n";
            }
            if((stoi(datos[0])==3)){
                strcpy(dni,datos[6].c_str());
                cliente3= new Organizador(ip,datos[3],datos[4],datos[5],dni);
                std::cout<<"\nBuenas organizador "<<cliente3->GetNombre()<<"\n";
            }            
            archivo.close();
            return true;
        }
        
    }
    archivo.close();
    return false;
}

int main(){
    std::cout<<"Actividades Extraescolares:\n";
    //status: Guarda el estado de usuario:
    //0-> Usuario no registrado, se te abre por defecto nada 
    // mas iniciar la pagina
    //
    //1-> Usuario registrado, se abre despues de que te hayas
    //registrado
    //
    //2-> Director Académico, se habre despues de haberse regisrtado
    //
    //3-> Organizador, se habre despuse de haberte registrado
    int hacer =0;
    bool terminar=false;
    int accion;
    bool a;
    std::string usuario;
    std::string password;
    Usuario u(ip);
    while(terminar==false){
        std::vector<Actividad> lista_activos= VectorConActividadesActivas();
        int s=1;
        std::vector<Actividad> actividades= VectorConActividades();
        switch(status){
            case 0://Usuario no registrado
                std::cout<<"Eliga una opción:\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                std::cout<<"2. Iniciar sesión\n";//funcion de iniciar sesión
                std::cout<<"3. Salir de la aplicación\n\n";
                std::cout<<"Si desea participar en algunade estas actividades, REGISTRATE!!\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:
                        std::cout<<"Dame le usuario\n";
                        std::cin>>usuario;
                        std::cout<<"Dame la contraseña\n";
                        std::cin>>password;
                        if(inciarSesion(usuario,password)==false){
                            std::cout<<"Error con la contraseña o usuario\n";
                        }  


                        break;

                    case 3:
                        
                        terminar=true;
                        
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;
            
            case 1://Usuario registrado
                std::cout<<"Eliga una opción:\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                std::cout<<"2. Inscribirse\n";
                //std::cout<<"4. Anular asistencia\n";
                std::cout<<"3. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"4. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:
                        std::cout<<"En cual actividad se quiere inscribir: \n";
                        for(auto & i: lista_activos){
                            if(i.GetAforo()==i.GetnParticipantes()){
                                std::cout<<s<<"."<<i.GetNombre()<<" (Lleno)\n";
                                s++; 
                            }else{
                                std::cout<<s<<"."<<i.GetNombre()<<"\n";
                                s++;
                            }
                        }
                        std::cin>>accion;
                        if(cliente->inscribirse(accion)==true){
                            std::cout<<"Inscripcion realizada con exito \n";
                        }   
                        break;

                    case 3:
                        status=0;                       
                        break;
 
                    case 4:
                        terminar=true; 
                        status=0;
                        
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;
            
            case 2://Director academico
                std::cout<<"Eliga una opción:\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                //std::cout<<"2. Generar actividades\n";
                //std::cout<<"4. Editar Actividades\n";
                std::cout<<"2. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"3. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:
                        status=0;
                        break;
                        
                    case 3:
                        terminar=true;
                        break;

                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;

            case 3://Organizador
                std::cout<<"Eliga una opción:\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                //std::cout<<"2. Crear actividad\n";
                //std::cout<<"3. Actualizar Acividad\n";
                //std::cout<<"4. Eliminar Actividad\n";
                //std::cout<<"6. Crear MailLit\n";
                std::cout<<"2. Activar actividad\n";
                std::cout<<"3. Generar fichero asistencia\n";
                std::cout<<"4. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"5. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:
                        MostrarActividad();
                        break;
                    case 3:
                        std::cout<<"En cual actividad quiere obtener la asistencia: \n";
                        for(auto& i: actividades)
                        {
                        std::cout<<"- La actividad " << i.GetNombre() << " con ID " << i.GetId()<<" tiene "<<i.GetnParticipantes()<<" participantes"<<std::endl;
                        }
                        std::cout<<"Introduzca el Id de la Actividad que quiere saber la asistencia: \n";
                        std::cin>>accion;
                        cliente3->GenerarAsistencia(accion);

                        break;
                    case 4:
                        status=0;
                        break;
                        
                    case 5:
                        terminar=true;
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;
            
            default:
                std::cout<<"Se a producido un error, lamentamos las molestias\n";
        }
        if(terminar!=true){
            std::cout<<"\n----Pulsa cualquier tecla para continuar-----\n";
            std::cin.get();
            std::cin.get();
            std::cout<<"\n\n";
        }else{
            std::cout<<"Cerrando programa\n";
        }
    }
}
