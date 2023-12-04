#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

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

    int status=0;
    int hacer =0;
    bool terminar=false;
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

                        std::system("clear");
                        break;

                    case 2:

                        std::system("clear");
                        break;

                    case 3:
                        
                        terminar=true;
                        std::system("clear");
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        std::system("clear");

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

                        std::system("clear");
                        break;

                    case 2:

                        std::system("clear");
                        break;

                    case 3:

                        std::system("clear");
                        break;
                    
                    case 4:

                        std::system("clear");
                        break;

                    case 5:

                        std::system("clear");
                        break;
                    case 6:
                        
                        terminar=true;
                        std::system("clear");
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        std::system("clear");

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

                        std::system("clear");
                        break;

                    case 2:

                        std::system("clear");
                        break;

                    case 3:

                        std::system("clear");
                        break;
                    
                    case 4:

                        std::system("clear");
                        break;
                    
                    case 5:

                        std::system("clear");
                        break;
                        
                    case 6:
                        
                        terminar=true;
                        std::system("clear");
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        std::system("clear");

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

                        std::system("clear");
                        break;

                    case 2:

                        std::system("clear");
                        break;

                    case 3:

                        std::system("clear");
                        break;
                    
                    case 4:

                        std::system("clear");
                        break;
                        
                    case 9:
                        
                        terminar=true;
                        std::system("clear");
                        break;
                    
                    default:
                        std::cout<<"Funcion no valida, por favor, inserte una opción que valga\n";
                        std::this_thread::sleep_for(std::chrono::seconds(3));
                        std::system("clear");

                }
                break;
                break;
            
            default:
                std::cout<<"Se a producido un error, lamentamos las molestias";
        }
    }
}