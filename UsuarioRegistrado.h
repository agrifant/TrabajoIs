#include <string>

class UsuarioRegistrado{
    private:
        std::string nombre_;
        std::string apellidos_;
        char[9] dni_;
        std::string correo_;
               
    public:
        DirectorAcademico(std::string nombre, std::string apellidos, char[9] dni, std::string correo) {nombre_=nombre; apellidos_=apellidos; dni_=dni; correo_=correo;}
        std::string GetNombre(return nombre_;)
        std::string GetApellidos(return Apellidos_;)
        char[9] GetDNI(return dni_;)
        std::string GetCorreo(return Correo_;)
}