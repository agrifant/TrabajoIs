#include "gtest/gtest.h"
#include "actividad.h"
#include "usuario.h"
#include "UsuarioRegistrado.h"
#include <fstream>
#include <vector>
#include <string>

TEST(UsuarioRegistrado,Inscribirse1){
    char dni[10]="77777777Y";
    UsuarioRegistrado alumno("100/100/100","Carlos","ENriquez",dni,"correo.@gmail.com");
    EXPECT_TRUE(inscribirse(1,alumno.GetDNI()));
    EXPECT_FALSE(inscribirse(1,alumno.GetDNI()));
    EXPECT_FALSE(inscribirse(100,alumno.GetDNI()));

}

TEST(UsuarioRegistrado, Inscribirse2){
    char dni[10]="77777777Y";
    UsuarioRegistrado alumno("100/100/100","Carlos","ENriquez",dni,"correo.@gmail.com");
    EXPECT_TRUE(inscribirse(1,alumno.GetDNI()));
}