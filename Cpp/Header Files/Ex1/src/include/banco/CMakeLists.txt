
set(BANCO_CONTAS
        ${CMAKE_CURRENT_SOURCE_DIR}/conta/Bancaria.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/conta/Poupanca.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/conta/Corrente.cpp
        )

add_library(banco STATIC ${BANCO_CONTAS})
