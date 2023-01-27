# Anotações do estudo do CMake

---

## Teoria

CMake é utilizado como uma ferramenta para simplificar o processo de buildar, testar e empacotar os softwares de uma
forma mais robusta, podendo configurar todo o processo para englobar diferentes plataformas e arquiteturas, além de
diversos ajustes que são necessárias para oferecer uma maior facilidade para quem for contribuir ao projeto.

De uma forma geral e resumida, o CMake é um conjunto de ferramentas que cobre desde a configuração até a produção de
pacotes
prontos para serem distribuidos, e além de ter suporte a diversas plataformas, ferramentas e linguagens.

CMake trás um arquivo de configuração de alto nível chamado `CMakeLists.txt` que especifica, em um projeto, o que deve
ser buildado e como, quais testes deve executar e quais pacotes vai criar. É um arquivo independente de plataforma pois
se trata apenas de um arquivo texto (.txt).

Para exclarecer as coisas, quando se fala em build do projeto, se trata do seguinte processo:

- CMake vai ler todas as definições escritas no `CMakeLists.txt` e então vai gerar um arquivo já configurado de um
  "sistema automatizado de compilação" (ou `generator` na literatura inglesa), que nada mais é que um arquivo pronto
  para uso com tudo que é necessário para compilar o projeto e gerar o produto final, podendo possuir suporte a
  multiplas configurações (Debug, Release, e etc.). Exemplos de sistemas automatizados de compilação
  são `Make`, `Ninja`,
  `Visual Studio`, `Xcode`.

Um conceito fundamental do CMake é o conceito de diretório `source` e diretório `build`.

- `source`: Aqui fica localizado os arquivos fontes do projeto e o CMakeLists.txt. Todos os arquivos que são necessários
  para o binário ser criado. Geralmente é onde o controle de versionamento é aplicado.
- `build`: Também chamado de diretório `binary` é onde fica os arquivos gerados pela build do projeto. O CMake
  geralmente usa mais a palavra binary.

O jeito mais básico de executar o CMake é através da ferramenta de terminal chamada `cmake`, executando os seguintes
comandos para mudar para o diretório de build, especificar o `generator` e a localização do `source`.

```commandline
mkdir build
cd build
cmake -G "Unix Makefiles" ../source
```

Se a opção `-G` for omitida, o cmake vai utilizar o generator padrão da plataforma do host.

Logo após o último comando, o cmake vai iniciar a fase de configuração (`configuring phase`), onde vai criar uma
representação interna de todo o projeto, interrogando o sistema a procura de compiladores e outras coisas. Então
entrando para a fase de geração (`generation phase`), como explicado lá em cima.

Após o cmake executar, ele irá salvar os detalhes no `CMakeCache.txt` para se necessário executar novamente, vai
reutilizar
as informações processadas desse arquivo.

Ao final, com os arquivos do projeto gerados no diretório `build`, o cmake pode chamar o generator escolhido através do
comando:

```commandline
cmake --build /dir/para/build --config Debug --target MyApp
```

A opção `--build` aponta para o diretório de build utilizado pelo CMake. `--config` é utilizado pelos generators
que suportam multi configurações, os generator que não suportam apenas ignoram. `--target` é usada para especificar ao
generator o que deve ser buildado, se for omitido vai ser utilizado que foi especificado no CMakeLists.txt

O comando completo ficaria:

```commandline
mkdir build
cd build
cmake -G "Unix Makefiles" ../source
cmake --build . --config Release --target MyApp
```

O ato de separar o diretório de build do source é uma boa prática, pois abre possibilidades como:

- Buildar o mesmo projeto com diferentes configurações
- Uma build pode ser configurada para Debug, outra para Release
- Pode ter diferentes builds com diferentes generators. Isso pode ajudar a perceber erros inesperados causados
  pela dependência de um generator específico, ou configurações do compilador diferentes entre generators.

---

## Prática

O CMake possui sua própria linguagem, assim como qualquer outra que um programador pode encontrar na natureza,
possuindo variáveis, funções, macros, lógica de condicionais,loops, comentários e etc.

Um CMakeLists.txt mínimo para gerar um executável simples fica assim:

```cmake
cmake_minimum_required(VERSION 3.2)
project(MeuApp)
add_executable(myBin main.cpp)
```

Cada linha executa um comando do CMake, se parecendo mais como funções em outras linguagens, aceitando argumentos
mas não retornando nenhum valor. Cada argumento é separado por espaços e pode ser escrito em multiplas linhas

```cmake
add_executable(
        myBin
        main.cpp
        src1.cpp
        src2.cpp
)
```

Os comandos são case insensitive, mas a convensão é se escrever tudo minúsculo.

O primeiro comando dita qual versão do cmake o projeto está usando, quando mais novo ele for mais funcionalidades ele
vai ter. Dessa forma, o comando: `cmake_minimum_required()` **DEVE SER O PRIMEIRO NO ARQUIVO**, pois ele especifica
quais comandos
estão disponíveis e verifica no CMakeLists.txt

```cmake
cmake_minimum_required(VERSION major.minor[.patch[.tweak]])
```

O comando DEVE ter a palavra-chave VERSION, para especificar a versão passada por parâmetro. Nesse comando o
estritamente necessário é apenas preencher o major e o minor, como por exemplo: 3.1, 3.2, 3.15...

O segundo comando especifica mais os "metadados" do projeto, como nome, versão e linguagem usada (para a configuração do
compilador)

```cmake 
project(NomeDoProjeto
        [VERSION major[.minor[.patch[.tweak]]]]
        [LANGUAGES linguagem ...]
        )
```

- NomeDoProjeto : O nome do projeto deve somente conter letras, numeros, underline (_), e hífens (-),
  mas tipicamente usa-se apenas letras junto com underlines. Ele é usado na maioria das vezes como uma especie de
  identificador do projeto.
- VERSION: Funciona apenas com a versão do cmake >= 3.0, assim como o nome do projeto, é usado para popular algumas
  variáveis e metadados, mas é um bom habito utiliza-lo para ajudar no versionamento do projeto.
- LANGUAGES: Define as linguagens de programação habilitadas no projeto. Os valores suportados incluem:
  `C`, `CXX`, `Fortran`,`ASM`,`Java` e entre outros. Você pode definir uma ou mais linguagens (separando-os por
  espaços),
  e até especificar nenhuma, utilizando `LANGUAGES NONE`.

O terceiro comando faz com que o CMake crie um executável a partir de uma lista de códigos fontes, e sua sintaxe básica
é:

```cmake
add_executable(nomeDoBin source1 [source 2...])
```

Isso faz com que gere um executável com o nome especificado no <nomeDoBin> (O CMake chama de target). Quando o projeto é
buildado, o executávei vai aparecer no diretório de build. Esse binário é dependente da plataforma, então em uma
plataforma windows se chamaria nomeDoBin.exe por exemplo. Esse executável pode ser chamado várias vezes no projeto com
nomes diferentes para criar outros targets, se tiver dois nomes iguais vai dar erro.

O autor fala que é uma boa prática sempre verificar a versão disponível para a plataforma que você irá desenvolver,
e especificando-o no `cmake_minimum_required()`. Além disso, deve também considerar manter atualizado a versão correta
no `project()`.

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
