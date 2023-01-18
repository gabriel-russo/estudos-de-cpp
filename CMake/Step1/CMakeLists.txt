cmake_minimum_required(VERSION 3.10) # Este comando deve ser o primeiro, pois especifica a versão mínima do cmake para o projeto, evitando problemas de compatibilidade de comandos.

project(Tutorial VERSION 1.5) # Define o nome do projeto, como também outras informações como versão e linguagem

# set(<variavel> <valor>) --> Define valores de variáveis
# CMAKE_ --> Esse sufixo indica que são variáveis especiais do CMake
set(CMAKE_CXX_STANDARD 11) # Define a versão do c++
set(CMAKE_CXX_STANDARD_REQUIRED True) # A variável CMAKE_CXX_STANDARD é tratada como requerimento para a build ser feita com sucesso

# configure_file(<input com as variaveis a serem substituidas> <output com o resultado> @ONLY)
configure_file(TutorialConfig.h.in TutorialConfig.h @ONLY) # Esse comando faz a substituição de valores de variáveis dentro de um arquivo a partir das variáveis dentro do CMake.

add_executable(Tutorial tutorial.cxx) # Especifica ao CMake para criar um executavel utilizando os arquivos de codigo fonte especificados

target_include_directories(Tutorial PUBLIC ${PROJECT_BINARY_DIR}) # Esse comando especifica ao executável (target) onde buscar os arquivos de include

