**Sistema de Gerenciamento de Pacientes**
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


**Descrição do projeto:**
O Simulador de Sistema de Gerenciamento de Dados de Paciente é um projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados, lecionada pelo Prof. Dr. Thiago Meireles Paixão. O objetivo principal do sistema é fornecer um ambiente estruturado para armazenar, buscar, atualizar e remover registros de pacientes utilizando Listas Encadeadas
--------------------------------------------------------------------------------------------------------------------------------------------------------------------

_**Estrutura do repositório:**_

📂 Trabalho_Estrutura_de_Dados 
**── 📂 PACIENTES**       # Gerenciamento de dados dos pacientes

**────📜 Makefile**         # Arquivo para compilação automática do projeto

**──── 📜 README.md**         # Documentação do projeto

**──── 📜 arquivo.c** #responsável por carregar e salvar dados de pacientes em um arquivo CSV usando uma lista encadeada.

**──── 📜 arquivo.h**   #declara as funções responsáveis por carregar e salvar dados em um arquivo CSV usando uma lista encadeada

**──── 📜 bd_paciente.c**            # Arquivo implementa um banco de dados de pacientes em C utilizando uma lista encadeada

**──── 📜 bd_pacientes.csv**  # Arquivo de dados dos pacientes utilizado pelo programa  

**──── 📜 bd_paciente.h**           # Arquivo de cabeçalho para a implementação do banco de dados de pacientes.

**──── 📜 lista.c** #Arquivo que contém a implementação das funções que manipulam uma lista encadeada para armazenar e gerenciar dados de pacientes.

**──── 📜 lista.h** #header file que define as estruturas e funções para manipular uma lista encadeada de pacientes

**──── 📜 main.c**            # Arquivo principal do programa

**──── 📜 menu.c** #O arquivo de código que você enviou implementa um sistema de gerenciamento de pacientes baseado em uma lista encadeada. 

**──── 📜 menu.h** #Arquivo de cabeçalho em C chamado menu.h.

**──── 📜 validacao.c** #Esse arquivo implementa funções de validação e formatação para de dados.

**──── 📜 validacao.h** #Esse arquivo validacao.h é um header file em C, que contém declarações de funções utilizadas para validação e formatação de dados. 

**─📜ESPECIFICAÇÃO**     # Documentação técnica e requisitos do projeto 





_**Decisões de Implementação:**_

**Estrutura do Banco de Dados -** A escolha de armazenar os dados dos pacientes em colunas que contém: ID,CPF, Nome, Idade e Data de Cadastro se dá pela necessidade de registro de informações básicas do paciente.

**Formato dos dados -** A escolha do formato do CPF e da Data por conter pontos e traços (ex.:123.456.789.01 e YYY-MM-DD) possui sua motivação na usabilidade e melhoria do entendimento para o usuário do sistema, uma vez que humanos possuem maior afinidade com esse modelo e costumam registar e passar seus dados dessa maneira.

**Validação dos dados -** A verificação contida no CPF tem o intuito de mitigar possíveis erros de digitação. Já a verificação na data permite que apenas pacientes com idades reais, portanto de valores maiores que 0 sejam registrados.

**Escopo Temporal -** A coluna de registro Data de cadastro vai permitir que análises temporais sejam feitas, para que os usuários possam achar os registros e atualizá-los de maneira mais eficiente.

_**Módulos do programa:**_

| Funções     | Descrição| Parâmetros   |  Retorno  |
|------------|:--------:|-------------:|----------:|
| f_carregarDados  |  Carrega os arquivos e abre para leitura    | LinkedList *lista e const char *nome_arquivo|        Void   |
| f_salvarDados     |  Salva os dados de uma lista encadeada em um arquivo CSV   | LinkedList *lista e const char *nome_arquivo    |     Void      |





_**Como Executar**_
1. Clone o repositório.
2. Execute `make` para compilar o programa.
3. Execute `./sistema_pacientes` para iniciar o sistema.


