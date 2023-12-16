#include "gtest/gtest.h"
#include "actividad.h"
#include "usuario.h"
#include "UsuarioRegistrado.h"
#include <fstream>
#include <vector>
#include <string>

TEST(UsuarioRegistrado,Inscribirse1){
    char dni[10]="57777777Y";
    UsuarioRegistrado alumno("100/100/100","Carlos","ENriquez",dni,"correo.@gmail.com");
    EXPECT_TRUE(alumno.inscribirse(1));
    EXPECT_FALSE(alumno.inscribirse(1));
    EXPECT_TRUE(alumno.inscribirse(2));
    EXPECT_TRUE(alumno.inscribirse(3));
    EXPECT_FALSE(alumno.inscribirse(2));
    EXPECT_FALSE(alumno.inscribirse(3));
    EXPECT_FALSE(alumno.inscribirse(-1));
    EXPECT_FALSE(alumno.inscribirse(100));

}

TEST(UsuarioRegistrado, geters){
    char dni[10]="47777777Y";
    UsuarioRegistrado alumno("100/100/100","Carlos","ENriquez",dni,"correo.@gmail.com");
    EXPECT_EQ("Carlos", alumno.GetNombre());
    EXPECT_EQ("ENriquez", alumno.GetApellidos());
    EXPECT_STREQ("47777777Y", alumno.GetDNI());
    EXPECT_EQ("correo.@gmail.com", alumno.GetCorreo());
}