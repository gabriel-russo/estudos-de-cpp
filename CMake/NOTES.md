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

Para problemas mais complexos, normalmente utiliza-se bibliotecas de terceiros ou de produção caseira, com isso, somente
com esses três comandos apresentados não vai conseguir ir muito longe. Vamos partir do final do último exemplo:

```cmake
add_executable(meuBin [WIN32] [MACOSX_BUNDLE] [EXCLUDE_FROM_ALL] source1 [source2 ...])
```

Para ser mais específico no seu binário, deve especificar a plataforma que irá usar.

- WIN32: Quando for criar um executável para windows, esse opção irá te ajudar criando um entry point mais específico,
  o `WinMain()`. E além de criar um link com a opção `/SUBSYSTEM:WINDOWS`.
- MACOSX_BUNDLE: Essa opção faz com que o CMake faça a build direcionada aos produtos Apple, não só pro macos, mas para
  o iOS também. Além de gerar arquivos específicos para o funcionamento nos sistemas da apple.
- EXCLUDE_FROM_ALL: É o ao contrário do default `ALL` (caso nenhum desses acima for usado), o executável apenas vai ser
  buildado se for chamado através do comando de build ou algum outro binario que depende dele for criado.
  Assim como o nome já deixa explícito, não vai fazer nenhuma build para nenhuma plataforma específica.

Para definir as bibliotecas (targets) é necessário usar o comando `add_library()`.

```cmake
add_library(libAlvo [STATIC | SHARED | MODULE] [EXCLUDE_FROM_ALL] source1 [source 2 ...])
```

Esse comando tem o mesmo sentido do add_executable, você define o alvo (esse nome vai ser como se fosse um identificador
dessa biblioteca dentro do CMakeLists.txt), o seu "tipo" e os arquivos fontes necessários para cria-lo.

- STATIC: Especifica que é uma biblioteca statica, no windows ele vai se tornar: libAlvo.lib, e em plataformas Unix-like
  irá ser libAlvo.a

> Uma "static library" ou biblioteca estática é um conjunto de código compilado que pode ser ligado a um programa
> durante a etapa de linkagem. Isso significa que todas as funções e dados da biblioteca estática são copiados para o
> executável final, e esse código fica embutido no programa. Dessa forma, o programa não precisa de referência externa
> para a biblioteca, ele já possui todas as informações necessárias dentro dele. Isso torna o programa auto-suficiente e
> pode ser executado em qualquer sistema operacional, sem a necessidade de instalação de biblioteca adicional.

- SHARED: Especifica uma biblioteca que é dinamica/compartilhada. No Windows as bibliotecas compartilhadas tem o nome de
  libAlvo.dll, em plataformas Apple tem o nome de libAlvo.dylib e nos sistemas Unix-like geralmente tem o nome de
  libAlvo.so

> Uma "shared library" ou biblioteca dinâmica é um conjunto de código compilado que pode ser carregado em tempo de
> execução. Isso significa que o programa não copia todas as funções e dados da biblioteca para si mesmo, mas ao invés
> disso, ele apenas contém uma referência para a biblioteca e a carrega em tempo de execução. Dessa forma, o tamanho do
> programa final é menor, já que ele não precisa incluir todo o código da biblioteca. No entanto, essa abordagem requer
> que a biblioteca esteja disponível no sistema operacional onde o programa está sendo executado, caso contrário, o
> programa não irá funcionar.

- MODULE: Especifica que a biblioteca é como se fosse um shared, mas vai ser carregada dinamicamente durante o runtime,
  e não no processo de linkagem na compilação. Esse tipo geralmente é usado para plugins ou componentes opcionais que
  são
  escolhidos se são carregados ou não.

Quando está adicionando essas bibliotecas, começa a ter o famoso "inferno das dependencias", onde uma biblioteca precisa
de outra para funcionar. Dessa forma, é necessário fazer o link dessas bibliotecas e indicar qual a relação que cada uma
tem com cada uma. Então, utiliza-se o comando abaixo:

```cmake
target_link_libraries(nomeDoAlvo
        <PRIVATE|PUBLIC|INTERFACE> lib1 [lib2 ....]
        [<PRIVATE|PUBLIC|INTERFACE> lib3 [lib4 ...]]
        ...
        )
```

De exemplo vai ser usado duas bibliotecas: A e B.

- PRIVATE: Dependência privada especifica que a biblioteca A usa a biblioteca B em sua implementação interna, mas quem
  fazer o link com a biblioteca A não precisa saber nada sobre a biblioteca B pois não interfere em nada.

- PUBLIC: Dependência publica especifica que não só a biblio A usa a biblio B internamente, mas também usa a biblio B
  na sua interface, isso significa que você não pode usar a biblio A sem precisar da biblio B. Então quem linkar com
  A vai depender também de B. Um exemplo dessa situação é quando uma função da biblio A usa um objeto que foi definido e
  implementado na biblio B e usa como parâmetro.

- INTERFACE: Dependência interface especifica que, para usar a biblio A, parte da biblio B tem que ser usada. É
  diferente do publico pois a biblio A não precisa do B internamente, apenas usa B como interface. Um Exemplo dessa
  situação seria quando você usa uma biblioteca que é headers-only como dependencia.

> Uma biblioteca "headers-only" é uma biblioteca de software que consiste apenas de arquivos de cabeçalho (headers) e
> não contém arquivos de implementação (como arquivos ".cpp"). Isso significa que, ao usar essa biblioteca, você
> precisará
> incluir os arquivos de cabeçalho correspondentes em seu código-fonte, mas não precisará vincular qualquer arquivo de
> objeto ou biblioteca específica.
>
>As bibliotecas headers-only são comuns em C++ devido ao seu modelo de linguagem de
> programação baseado em templates. Os templates são uma forma de programação genérica, que permite escrever código que
> pode ser usado com diferentes tipos de dados. Dessa forma, os templates são compilado junto ao código que os usa,
> então não é necessário uma biblioteca separada para os arquivos de objeto.

```cmake
add_library(collector src1.cpp) # Criando um target biblioteca collector
add_library(algo src2.cpp) # Criando um target biblioteca algo
add_library(engine src3.cpp) # Criando um target biblioteca engine
add_library(ui src4.cpp) # Criando um target biblioteca ui
add_executable(myApp main.cpp) # Criando um target myApp

target_link_libraries(collector # Criando o relacio. de dependência
        PUBLIC ui
        PRIVATE algo engine
        )
# Leitura: A biblioteca collector tem uma dependência publica com ui, então o target myApp
# vai ser linkado tanto com collector quanto ui. Além disso a biblio collector tem uma relação
# privada com algo e engine, então myApp não vai ser linkado diretamente com eles, pois são usados
# internamente por collector e não interessa saber da existencia desses dois.

target_link_libraries(myApp PRIVATE collector) # E por fim faz o link da dependencia do myApp 
# com o collector, então quem se linkar futuramente com myApp não tem q se preocupar com collector.
```

Além disso, você pode usar o `target_link_libraries()` de várias outras formas, como:

- Caminho completo para uma lib: `/usr/lib/libfoo.so`

- Nome da lib: `libfoo.lib`, dessa forma o linker vai procurar por essa biblioteca

- Como uma flag para o Linker: Você inicia com o hífen, como por exe `-lfoo`, dessa forma se parece como se tivesse
  passando as libs manuelmente pro compilador.

```text
Manual do GCC:
-llibrary
-l library
    Procura a biblioteca com base no nome na fase de linking. [...] 
    A opção é passada diretamente para o linker pelo GCC. [...]
    O linker procura na lista padrão de diretórios pela biblioteca. [...]
```

O Autor fala que, quando está nomeando o nome do target das bibliotecas, evitar começar ou terminar
com "lib", pois em algumas plataformas o lib é colocado automaticamente quando está construindo a biblio, então
pode ficar: `liblibfoo.<dll|so|lib|a>`.

Além disso ele fala que: SEMPRE, especifique a relação da biblioteca (PRIVATE, PUBLIC ...),
pois em projetos maiores essas keywords tem um enorme impacto.

As variáveis são muito importante para o CMake assim como em qualquer outra linguagem de programação, pois só com elas
que podemos moldar o produto final como queremos.

Para definir uma variável no cmake, utiliza-se esse comando no CMakeLists.txt:

```cmake 
set(MinhaVar <valor>... [PARENT_SCOPE])
```

O nome da variável deve seguir a mesma regra que em outras linguagens: pode conter letras, números e underlines (_), não
pode começar com número ou caractere especial e etc.

O nome das variávels são case-sensitive.

Sobre o `PARENT_SCOPE`: As variáveis possuem um escopo em particular assim como a variável de outras linguagens,
limitando-se a funções, arquivos e etc, dessa forma, não podendo ser modifcada fora do escopo. Mais detalhes sobre isso
vai ser tratado mais para frente no capítulo 7.

O Cmake trata toda as variáveis como strings. Em outros contextos as variáveis podem ser interpretadas como outros
tipos, mas em sua essência são apenas strings. Quando está criando uma variável com o `set()`, os valores não precisam
de aspas, a não ser que o valor precise de espaços internamente. Se vários valores forem passados por parâmetro, os
valores vão ser agrupados em uma string e separados por ponto e vírgula, pois é assim q o CMake representa listas.

Alguns exemplos do uso do `set()`:

```cmake
set(MinhaVar a b c)    # MinhaVar = "a;b;c"
set(MinhaVar a;b;c)    # MinhaVar = "a;b;c"
set(MinhaVar "a b c")  # MinhaVar = "a b c"
set(MinhaVar a b;c)    # MinhaVar = "a;b;c"
set(MinhaVar a "b c")  # MinhaVar = "a;b c"
```

Para pegar os valores de uma váriavel utiliza o operador de expansão `${ <nome da variavel> }`, o CMake é bem flexível
com a utilização desse operador, você pode utilizar esse operador junto com outros recursivamente. Caso utilize com uma
variável que não existe, apenas retornará uma string vazia.

Alguns exemplos de uso do operador de expansão com o comando `set()`:

```cmake
set(foo ab)                     # foo = "ab"
set(bar ${foo}cd)               # bar = "abcd"
set(baz ${foo} cd)              # baz = "ab;cd"
set(minhaVar ba)                # minhaVar = "ba"
set(grupo "${${MinhaVar}r}ef")  # grupo => "${bar}ef" => "abcdef"
set(${foo} xyz)                 # ab = "xyz"
set(bar ${naoExiste})           # bar = ""
```

String também podem ser usadas com multiplas linhas, tendo dois jeitos de faze-lo:

Com o simples enter para pular a linha e o CMake se encarrega do resto:

```cmake

set(amet "dolor amet")

set(minhaVar "Lorem ipsum magum
florium ${amet}, tambem posso dar scape em aspas com \"contra barra\"")
```

Ou com caracteres delimitadores especiais do CMake, o `[[` para abrir e o `]]` para fechar

```cmake
set(multilinha [[
Primeira linha
Segunda Linha
]])
```

Ou para utilizar string puro sem qualquer interpretação do CMake utilize `[=[` para abrir e `]=]` para fechar:

```cmake
set(shellScriptExemplo [=[
#!/bin/bash

[[ -n "${USER}" ]] && echo "Usuario existe"

]=])
```

Para excluir uma variável utilize o comando `unset( <nome da variavel> )`

O CMake também possibilita a utilização de variáveis de ambiente, utilizando a
sintaxe: `$ENV{<nome da variavel especial>`, exemplo:

```cmake
set(pathDoAmbiente "$ENV{PATH}")
```

Vale ressaltar que modificar variáveis de ambiente no CMake apenas tem efeitos locais no runtime do CMake.

Também é possível salvar o estado de variáveis no cache, utilizando a opção `CACHE`

```cmake
set(minhVar <VALOR>... CACHE <TIPO> "docstring" [FORCE])
```

Ao executar o comando acima, o CMake vai armazenar essa variável no `CMakeCache.txt`, dentro do diretório de build.
Dessa forma, o valor dessa variável vai manter até ser sobrescrita ou removida do cache.

As variáveis em cache se comporta como uma variável normal.

As opções:

`TIPO`: O tipo da variável pode ser:

- `BOOL`: É uma variável booleana de on/off, por baixo dos panos é uma string que representa um booleano com texto
  (ON/OFF ou TRUE/FALSE ou 1/0 e etc.)
- `FILEPATH`: Uma variável que representa um caminho até um arquivo
- `PATH`: Uma variável que representa um caminho até um diretório
- `STRING`: Apenas uma string de texto
- `INTERNAL`: Essa variável não é feita para ser interagida com o usuário, é mais usada para guardar dados internos do
  projeto, como por exemplo um processamento demorado.

A utilização de variáveis booleanas é tão recorrente que para ajudar na legibilidade do código, foi criada o comando
`option`, que é utilizada em conjunto com o comando `set()`. E sua sintaxe é:

`option(<nome Variavel> <string de ajuda> [valor inicial])`

Exemplo:

```cmake
set(minhaVar CACHE BOOL)

option(minhaVar "Ligar ou Desligar funcionalidade X" ON)
```

Caso queira manipular os valores do cache através da linha de comando, utilize:

Para criar:
`cmake -D myVar:tipo=valor ... `

Para remover:
`cmake -U nomedaVar -U *Var `

Para as Versões gráficas do CMake, você pode criar algumas opções extras para as variáveis, como por exemplo marcar como
avançado:

```cmake
mark_as_advanced([CLEAR|FORCE] var1 [var2...])
```

Para debugar variáveis e outras coisas, você poder dar print na tela utilizando o comando:

```cmake
message([mode] mensagem [msg2]...)
```

Os modos não são obrigatórios, se não for usado nenhum dos abaixos a mensagem vai ser printada normalmente.

E os modos são:

- `STATUS`: Usado para informar algo, as mensagens são precedidas por 2 hífens
- `WARNING`: Usados para dar aviso, são destacadas em vermelho (se suportado), mas não aborta a execução
- `AUTHOR_WARNING`: É igual o warning, mas só aparece se estiver habilitado com a opção `-Wdev`
- `SEND_ERROR`: Usado para dar um erro, são destacadas em vermelho (se suportado), mas vai continuar o processamento até
  o estágio de configuração for completado, mas não entra no estágio de geração
- `FATAL_ERROR`: Usado para informar um erro, a mensagem vai ser destacada e irá abortar a execução, alem do log que vai
  dizer a localização do erro.
- `DEPRECATION`: Uma categoria especial para dar a mensagem de depreciação, se a variável `CMAKE_ERROR_DEPRECATED` for
  verdadeira, então a mensagem será tratada como um erro. Se `CMAKE_WARN_DEPRECATED` for verdadeiro, a mensagem é
  tratada como um waning. Se nenhumas estiverem habilidatas, a mensagem não irá ser exibida.

Exemplo:

```cmake
set(myVar "Ola mundo")
message("O valor da variavel myVar é: ${myVar}")
```

Outro mecanismo de debug de variáveis que o CMake disponibiliza é o comando `variable_watch()`. Normalmente é usada em
projetos mais complexos onde é preciso entender como uma variável chegou a um valor em particular. Quando uma variável é
seguida, todos as leituras e modificações são logadas.

```cmake
variable_watch(minhaVar [command])
```

Para um controle absoluto, você pode executar um callback toda vez que a variável for lida ou modificada passando uma
função no argumento `[command]`, esse callback vai receber os seguintes argumentos: Nome da variável, tipo de acesso,
valor da variável, o arquivo atual na stack e o stack de arquivos.

Além disso, as variávels do tipo string podem ser modificadas ou lidas através de funções utilitárias:

```cmake
string(FIND ${varComString} subString varDeOutput [REVERSE])

string(REPLACE matchString replaceWith outVar input [input...])

string(REGEX MATCH regex outVar [input...])

# E entre outros ......
```

Como foi falado anteriormente, CMake possui listas, e nada mais é que uma string separa por ponto e vírgula, mas você
pode utilizar uma função que irá trata-los como uma lista:

```cmake
list(LENGTH listVar outVar)
list(GET listVar index [index...] outVar)
list(APPEND listVar item [item...]) # Insere no final
list(INSERT listVar index item [item...]) # Insere no index
list(FIND myList value outVar)
list(REMOVE_ITEM myList value [value...])
list(REMOVE_AT myList index [index...])
list(REMOVE_DUPLICATES myList)

# E entre outros ......
```

Além disso, pode fazer operações matemáticas:

```cmake
set(x 3)

set(y 7)

math(EXPR z "(${x}+${y}) / 2")

message("result = ${z}")
```
