#include "gtest/gtest.h"
#include "usuario.h"
#include "actividad.h"
#include <fstream>
#include <vector>
#include <string>

TEST(Usuario, Split){
Usuario usertest("1");
std::vector<std::string> resPrueba1;
std::vector<std::string> resPrueba2;
std::vector<std::string> resPrueba3;
std::string lineaPrueba="Hola,mellamo|gabriel/lele,";

resPrueba1 = u.split(lineaPrueba,',');
resPrueba2 = u.split(lineaPrueba,'|');
resPrueba3 = u.split(lineaPrueba,'/');

EXPECT_EQ("Hola", resPrueba1[0]);
EXPECT_EQ("", resPrueba1[2]);
EXPECT_EQ("Hola,mellamo", resPrueba2[0]);
EXPECT_EQ("lele,", resPrueba3[1]);

}