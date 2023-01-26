# Anotações de funções do CMake

---
## Teoria

CMake é utilizado como uma ferramenta para simplificar o processo de buildar, testar e empacotar os softwares de uma 
forma mais robusta, podendo configurar todo o processo para englobar diferentes plataformas e arquiteturas, além de
diversos ajustes que são necessárias para oferecer uma maior facilidade para quem for contribuir ao projeto.

De uma forma geral e resumida, o CMake é um conjunto de ferramentas que cobre desde a configuração até a produção de pacotes
prontos para serem distribuidos, e além de ter suporte a diversas plataformas, ferramentas e linguagens.

todo: ler e escrever o capitulo 2

---
Este comando deve ser o primeiro, pois especifica a versão mínima do cmake para o projeto, evitando problemas de
compatibilidade de comandos.

```cmake 
cmake_minimum_required(VERSION 3.10)
```

---
Define o nome do projeto, como também outras informações como versão e linguagem

```cmake 
project(Tutorial VERSION 1.5)
```

---
Define valores de variáveis

```cmake 
set(<variavel> <valor>)
```

Variáveis com esse sufixo indica que são variáveis especiais do CMake:

`CMAKE_`

Define a versão do c++

```cmake 
set(CMAKE_CXX_STANDARD 11)
```

A variável CMAKE_CXX_STANDARD é tratada como requerimento para a build ser feita com sucesso

```cmake
set(CMAKE_CXX_STANDARD_REQUIRED True)
```

---
Esse comando faz a substituição de valores de variável dentro de um arquivo a partir das variáveis dentro do CMake.

```cmake 
configure_file(<input com as variaveis a serem substituidas> <output com o resultado> @ONLY)
```

- Exemplo:

```cmake 
configure_file(TutorialConfig.h.in TutorialConfig.h @ONLY) 
```

```
TutorialConfig.h.in

#cmakedefine Tutorial_VERSION_MAJOR @Tutorial_VERSION_MAJOR@
#cmakedefine Tutorial_VERSION_MINOR @Tutorial_VERSION_MINOR@
```

No output irá ser criado 2 macros no header file, com o nome específicado e com a substituição do valor da variável
que está definida no CMakeLists.txt, e será inserido entre os `@`

```
TutorialConfig.h

#define Tutorial_VERSION_MAJOR 1
#define Tutorial_VERSION_MINOR 5
```

---
Especifica ao CMake para criar um executavel utilizando os arquivos de codigo fonte especificados

```cmake
add_executable(Tutorial tutorial.cxx)
```

---
Esse comando especifica ao executável (target) onde buscar os arquivos de include

```cmake 
target_include_directories(Tutorial PUBLIC ${PROJECT_BINARY_DIR}) # 
```

---
