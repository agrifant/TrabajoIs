#include "gtest/gtest.h"
#include "actividad.h"
#include "usuario.h"
#include "UsuarioRegistrado.h"
#include "organizador.h"
#include <fstream>
#include <vector>
#include <string>

TEST(Organizador,GenerarAsistencia1){
    Organizador organizador("1");
    EXPECT_TRUE(organizador.GenerarAsistencia(6));
    EXPECT_FALSE(organizador.GenerarAsistencia(1));
    EXPECT_TRUE(organizador.GenerarAsistencia(2));
    EXPECT_FALSE(organizador.GenerarAsistencia(50));
}
