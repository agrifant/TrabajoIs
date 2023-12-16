#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "organizador.h"
#include "DirectorAcademico.h"
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
        std::cout<<"Erro interno, sentimos las molestias\n";
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
                std::cout<<cliente->GetDNI()<<"\n";
            }
            if((stoi(datos[0])==2)){
                strcpy(dni,datos[6].c_str());
                cliente2 =new DirectorAcademico(ip,datos[3],datos[4],datos[5],dni,datos[7], datos[8]);
            }
            if((stoi(datos[0])==3)){
                strcpy(dni,datos[6].c_str());
                cliente3= new Organizador(ip,datos[3],datos[4],datos[5],dni);
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
        switch(status){
            case 0://Usuario no registrado
                std::cout<<"¿Que desea hacer??\n";
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
                        if(inciarSesion(usuario,password)==true){
                            std::cout<<"Iniciando sesion\n";
                        }else{
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
                std::cout<<"¿Que desea hacer??\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                std::cout<<"2. Inscribirse\n";
                std::cout<<"4. Anular asistencia\n";
                std::cout<<"5. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"6. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:
                        std::cout<<"En cual actividad se quiere inscribir: \n";
                        std::cin>>accion;
                        
                        if(cliente->inscribirse(accion)==false){
                            std::cout<<("Hubo un error\n");
                        }else{
                            std::cout<<("Todo se realizo correctamente\n");
                        }

                        
                        break;

                    case 3:

                        
                        break;
                    
                    case 4:

                        
                        break;

                    case 5:
                        status=0;
                        
                        break;
                    case 6:
                        
                        terminar=true;
                        
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;
            
            case 2://Director academico
                std::cout<<"¿Que desea hacer??\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                std::cout<<"2. Generar actividades\n";
                std::cout<<"4. Editar Actividades\n";
                std::cout<<"5. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"6. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:

                        
                        break;

                    case 3:

                        
                        break;
                    
                    case 4:

                        
                        break;
                    
                    case 5:

                        status=0;
                        break;
                        
                    case 6:
                        
                        terminar=true;
                        
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;

            case 3://Organizador
                std::cout<<"¿Que desea hacer??\n";
                std::cout<<"1.Ver actividades propuestas\n";//funcion consultarActividades
                std::cout<<"2. Crear actividad\n";
                std::cout<<"3. Actualizar Acividad\n";
                std::cout<<"4. Eliminar Actividad\n";
                std::cout<<"5. Mostrar actividad\n";
                std::cout<<"6. Crear MailLit\n";
                std::cout<<"7. Generar fichero asistencia\n";
                std::cout<<"8. Cerrar sesión\n";//funcion de iniciar sesión
                std::cout<<"9. Salir de la aplicación\n\n";
                std::cout<<"Opción: ";
                std::cin>>hacer;
                switch(hacer){
                    case 1:
                        u.ConsultarActividades(status);
                        
                        break;

                    case 2:

                        
                        break;

                    case 3:

                        
                        break;
                    
                    case 4:

                        
                        break;
                    case 8:
                        status=0;
                        break;
                        
                    case 9:
                        
                        terminar=true;
                        
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        //std::this_thread::sleep_for(std::chrono::seconds(3));
                        

                }
                break;
                break;
            
            default:
                std::cout<<"Se a producido un error, lamentamos las molestias";
        }
        std::cout<<"\n\n\n\n";
    }
}