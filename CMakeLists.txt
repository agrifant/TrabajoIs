cmake_minimum_required(VERSION 3.22)
project(programa)

# Configuración de Google Test
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main gmock_main)

# Añadir tus archivos fuente y el ejecutable principal
add_executable(programa
    main.cc
    actividad.cc
    TestInscribirse.cc
    usuario.cc
    UsuarioRegistrado.cc
)

# Enlazar con la biblioteca Google Test
target_link_libraries(programa PRIVATE GTest::GTest)

# Agregar el ejecutable de los tests
add_executable(inscribirse-test
    TestInscribirse.cc
    actividad.cc
    usuario.cc
    UsuarioRegistrado.cc
)

# Enlazar con la biblioteca Google Test
target_link_libraries(inscribirse-test PRIVATE GTest::GTest)

# Configurar el ejecutable principal como dependencia de los tests
add_dependencies(inscribirse-test programa)

# Configurar el comando de prueba para ejecutar los tests
add_test(NAME inscribirse-gtests COMMAND inscribirse-test)


