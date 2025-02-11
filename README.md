**Sistema de Gerenciamento de Pacientes**

Alunos: Davi Sutil e Karyna Carbas
--------------------------------------------------------------------------------------------------------------------------------------------------------------------


**Descrição do projeto:**
O Simulador de Sistema de Gerenciamento de Dados de Paciente é um projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados, lecionada pelo Prof. Dr. Thiago Meireles Paixão. O objetivo principal do sistema é fornecer um ambiente estruturado para armazenar, buscar, atualizar e remover registros de pacientes utilizando Listas Encadeadas
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
_**Estrutura do repositório:**_

**📂 Trabalho_Estrutura_de_Dados** 

│──── 📜 Makefile          # Arquivo para compilação automática do projeto  

│──── 📜 README.md         # Documentação do projeto

│──── 📜 arquivo.c #responsável por carregar e salvar dados de pacientes em um arquivo CSV usando uma lista encadeada.  

│──── 📜 arquivo.h   #declara as funções responsáveis por carregar e salvar dados em um arquivo CSV usando uma lista encadeada  

│──── 📜 bd_paciente.c            # Arquivo implementa um banco de dados de pacientes em C utilizando uma lista encadeada

│──── 📜 bd_pacientes.csv  # Arquivo de dados dos pacientes utilizado pelo programa  

│──── 📜 bd_paciente.h           # Arquivo de cabeçalho para a implementação do banco de dados de pacientes.

│──── 📜 lista.c #Arquivo que contém a implementação das funções que manipulam uma lista encadeada para armazenar e gerenciar dados de pacientes.

│──── 📜 lista.h #header file que define as estruturas e funções para manipular uma lista encadeada de pacientes

│──── 📜 main.c            # Arquivo principal do programa

│──── 📜 menu.c #O arquivo de código que você enviou implementa um sistema de gerenciamento de pacientes baseado em uma lista encadeada. 

│──── 📜 menu.h #Arquivo de cabeçalho em C chamado menu.h.

│──── 📜 validacao.c #Esse arquivo implementa funções de validação e formatação para de dados.

│──── 📜 validacao.h #Esse arquivo validacao.h é um header file em C, que contém declarações de funções utilizadas para validação e formatação de dados. 

│──── 📜ESPECIFICAÇÃO     # Documentação técnica e requisitos do projeto 

--------------------------------------------------------------------------------------------------------------------------------------------------------------------
_**Funções do programa:**_

| Função  arquivo.c        | Descrição                                                                                     | Parâmetros                                                                 | Retorno  |
|-----------------|-----------------------------------------------------------------------------------------------|----------------------------------------------------------------------------|----------|
| f_carregarDados | Carrega dados de um arquivo CSV para uma lista encadeada.                                     | LinkedList *lista, const char *nome_arquivo                                | void     |
| f_salvarDados   | Salva os dados de uma lista encadeada em um arquivo CSV.                                      | LinkedList *lista, const char *nome_arquivo                                | void     |

| Funções de bd_paciente.c                    | Descrição                                                                                     | Parâmetros                                                                                             | Retorno                                                                 |
|----------------------------|-------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------|
| `criar_bdpaciente`         | Cria e inicializa o banco de dados (BD) de pacientes.                                           | Nenhum                                                                                                 | Ponteiro para `BDPaciente`                                              |
| `liberar_bdpaciente`       | Libera a memória alocada para o banco de dados e seus nós.                                      | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                      | void                                                                    |
| `carregar_dados_csv`       | Carrega os dados de um arquivo CSV para o banco de dados.                                       | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *nome_arquivo`: Nome do arquivo CSV.  | void                                                                    |
| `salvar_dados_csv`         | Salva os dados do banco de dados em um arquivo CSV.                                             | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *nome_arquivo`: Nome do arquivo CSV.  | void                                                                    |
| `consultar_paciente`       | Consulta um paciente pelo CPF ou nome.                                                          | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *consulta`: String contendo CPF ou nome. | Ponteiro para o `Paciente` encontrado ou `NULL`                         |
| `consultar_paciente_por_cpf`| Consulta um paciente exclusivamente pelo CPF.                                                  | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *cpf`: CPF do paciente.               | Ponteiro para o `Paciente` encontrado ou `NULL`                         |
| `inserir_paciente`         | Insere um novo paciente no banco de dados.                                                      | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *cpf`: CPF do paciente.<br>`const char *nome`: Nome do paciente.<br>`int idade`: Idade do paciente.<br>`const char *data_cadastro`: Data de cadastro. | void                                                                    |
| `atualizar_paciente`       | Atualiza os dados de um paciente existente no banco de dados.                                   | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`int id`: ID do paciente a ser atualizado.<br>`const char *cpf`: Novo CPF (opcional).<br>`const char *nome`: Novo nome (opcional).<br>`int idade`: Nova idade.<br>`const char *data_cadastro`: Nova data de cadastro (opcional). | void                                                                    |
| `remover_paciente`         | Remove um paciente do banco de dados.                                                           | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`int id`: ID do paciente a ser removido.          | void                                                                    |
| `imprimir_pacientes`       | Imprime todos os pacientes cadastrados no banco de dados.                                       | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                      | void                                                                    |
|                            | - Verifica se a lista está vazia.<br>- Formata e imprime os dados dos pacientes em uma tabela.  |                                                                                                        |                                                                         |

| **Funções de lista.c**                              | **Descrição**                                                                                     | **Parâmetros**                                                                                             | **Retorno**                                                                 |
|-----------------------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| `criar_lista`                           | Cria e inicializa uma lista encadeada.                                                            | Nenhum                                                                                                     | Ponteiro para `LinkedList` (estrutura inicializada).                        |
|                                         | - Aloca memória para a lista.<br>- Define o primeiro nó como `NULL`.                               |                                                                                                            |                                                                             |
| `liberar_lista`                         | Libera a memória alocada para a lista encadeada e seus nós.                                        | `LinkedList *lista`: Ponteiro para a lista encadeada.                                                      | Nenhum (void).                                                             |
|                                         | - Percorre todos os nós da lista.<br>- Libera cada nó individualmente.<br>- Libera a estrutura principal da lista. |                                                                                                            |                                                                             |
| `adicionar_paciente`                    | Adiciona um novo paciente no início da lista encadeada.                                            | `LinkedList *lista`: Ponteiro para a lista encadeada.<br>`Paciente paciente`: Estrutura contendo os dados do paciente. | Nenhum (void).                                                             |
|                                         | - Aloca memória para o novo nó.<br>- Insere o nó no início da lista.                                |                                                                                                            |                                                                             |
| `remover_paciente_por_id`               | Remove um paciente da lista pelo ID.                                                              | `LinkedList *lista`: Ponteiro para a lista encadeada.<br>`int id`: ID do paciente a ser removido.          | Nenhum (void).                                                             |
|                                         | - Localiza o paciente pelo ID.<br>- Remove o nó correspondente da lista.                            |                                                                                                            |                                                                             |
| `consultar_paciente_por_cpf_ou_nome`    | Consulta um paciente pela chave (CPF ou Nome).                                                    | `LinkedList *lista`: Ponteiro para a lista encadeada.<br>`const char *consulta`: String contendo CPF ou nome. | Ponteiro para o `Node` encontrado ou `NULL` se não encontrado.              |
|                                         | - Percorre a lista procurando o CPF exato ou um nome que contenha a consulta.                      |                                                                                                            |                                                                             |
| `imprimir_lista`                        | Imprime todos os pacientes da lista encadeada.                                                    | `LinkedList *lista`: Ponteiro para a lista encadeada.                                                      | Nenhum (void).                                                             |
|                                         | - Exibe os dados dos pacientes em formato tabular.                                                |                                                                                                            |                                                                             |

| **Função/Operação do main**         | **Descrição**                                                                                     | **Parâmetros**                                                                                             | **Retorno**                                                                 |
|-----------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| `criar_bdpaciente`          | Cria e inicializa o banco de dados (BD) de pacientes.                                             | Nenhum                                                                                                     | Ponteiro para `BDPaciente` (estrutura inicializada).                        |
|                             | - Aloca memória para o BD.<br>- Define a lista como vazia (`primeiro = NULL`).<br>- Inicializa o tamanho como 0. |                                                                                                            |                                                                             |
| `carregar_dados_csv`        | Carrega os dados de um arquivo CSV para o banco de dados.                                         | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *nome_arquivo`: Nome do arquivo CSV.      | Nenhum (void).                                                             |
|                             | - Abre o arquivo CSV para leitura.<br>- Ignora o cabeçalho.<br>- Lê cada linha e insere na lista encadeada.<br>- Fecha o arquivo ao final. |                                                                                                            |                                                                             |
| `f_exibirMenu`              | Exibe o menu principal e permite interação com o usuário.                                         | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                             | - Fornece opções para inserir, consultar, atualizar, remover e listar pacientes.<br>- Gerencia as operações do usuário. |                                                                                                            |                                                                             |
| `salvar_dados_csv`          | Salva os dados do banco de dados em um arquivo CSV.                                               | `BDPaciente *bd`: Ponteiro para o banco de dados.<br>`const char *nome_arquivo`: Nome do arquivo CSV.      | Nenhum (void).                                                             |
|                             | - Abre o arquivo CSV para escrita.<br>- Escreve o cabeçalho.<br>- Percorre a lista e escreve os dados no arquivo.<br>- Fecha o arquivo ao final. |                                                                                                            |                                                                             |
| `liberar_bdpaciente`        | Libera a memória alocada para o banco de dados e seus nós.                                        | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                             | - Percorre todos os nós da lista encadeada.<br>- Libera cada nó individualmente.<br>- Libera a estrutura principal do BD. |                                                                                                            |                                                                             |

| **Funções menu.c**                     | **Descrição**                                                                                     | **Parâmetros**                                                                                             | **Retorno**                                                                 |
|---------------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| `f_exibirMenu`                  | Exibe o menu principal e processa as opções do usuário.                                           | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Exibe um menu com opções para consultar, atualizar, remover, inserir e listar pacientes.<br>- Processa a entrada do usuário até que escolha sair. |                                                                                                            |                                                                             |
| `f_consultarPaciente`           | Consulta um paciente pelo Nome ou CPF.                                                            | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Permite ao usuário escolher entre consulta por nome ou CPF.<br>- Exibe os pacientes encontrados em formato tabular. |                                                                                                            |                                                                             |
| `f_atualizarPaciente`           | Atualiza os dados de um paciente existente.                                                       | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Localiza o paciente pelo CPF ou Nome.<br>- Permite atualizar CPF, Nome, Idade e Data de Cadastro.<br>- Valida os novos dados antes de atualizar. |                                                                                                            |                                                                             |
| `f_removerPaciente`             | Remove um paciente existente.                                                                     | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Localiza o paciente pelo CPF ou Nome.<br>- Solicita confirmação antes de remover.               |                                                                                                            |                                                                             |
| `f_inserirNovoPaciente`         | Insere um novo paciente no sistema.                                                               | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Lê os dados do paciente (CPF, Nome, Idade e Data de Cadastro).<br>- Valida os dados antes de inserir.<br>- Exibe os dados do paciente recém-inserido. |                                                                                                            |                                                                             |
| `f_imprimirLista`               | Imprime todos os pacientes cadastrados.                                                           | `BDPaciente *bd`: Ponteiro para o banco de dados.                                                          | Nenhum (void).                                                             |
|                                 | - Verifica se a lista está vazia.<br>- Exibe os dados dos pacientes em formato tabular.           |                                                                                                            |                                                                             |

| **Função de validacao.c**               | **Descrição**                                                                                     | **Parâmetros**                                                                                             | **Retorno**                                                                 |
|--------------------------|---------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
| `validar_cpf`            | Valida um CPF numérico.                                                                           | `const char *cpf`: String contendo o CPF a ser validado (apenas números).                                  | `int`: Retorna `1` se o CPF for válido, ou `0` se inválido.                 |
|                          | - Verifica se o CPF tem exatamente 11 caracteres.<br>- Verifica se todos os caracteres são dígitos. |                                                                                                            |                                                                             |
| `validar_data`           | Valida uma data no formato `AAAA-MM-DD`.                                                          | `const char *data`: String contendo a data a ser validada.                                                 | `int`: Retorna `1` se a data for válida, ou `0` se inválida.                |
|                          | - Verifica se a data tem exatamente 10 caracteres.<br>- Verifica os separadores `-`.<br>- Valida o ano, mês e dia.<br>- Considera anos bissextos e meses com 30/31 dias. |                                                                                                            |                                                                             |
| `formatar_cpf`           | Formata um CPF numérico para o formato `xxx.xxx.xxx-xx`.                                          | `const char *cpf_numerico`: String contendo o CPF numérico (apenas números).<br>`char *cpf_formatado`: String onde o CPF formatado será armazenado. | Nenhum (void).                                                             |
|                          | - Verifica se o CPF tem exatamente 11 dígitos.<br>- Formata o CPF no padrão `xxx.xxx.xxx-xx`.<br>- Retorna "CPF_INVALIDO" se o CPF não tiver 11 dígitos. |                                                                                                            |                                                                             |







-------------------------------------------------------------------------------------------------------------------------------------------------------------------

**Decisões de Implementação:**

_Estrutura do Banco de Dados -_ A escolha de armazenar os dados dos pacientes em colunas que contém: ID,CPF, Nome, Idade e Data de Cadastro se dá pela necessidade de registro de informações básicas do paciente.

_Formato dos dados -_ A escolha do formato do CPF e da Data por conter pontos e traços (ex.:123.456.789.01 e YYY-MM-DD) possui sua motivação na usabilidade e melhoria do entendimento para o usuário do sistema, uma vez que humanos possuem maior afinidade com esse modelo e costumam registar e passar seus dados dessa maneira.

_Validação dos dados -_ A verificação contida no CPF tem o intuito de mitigar possíveis erros de digitação. Já a verificação na data permite que apenas pacientes com idades reais, portanto de valores maiores que 0 sejam registrados.

_Escopo Temporal -_ A coluna de registro Data de cadastro vai permitir que análises temporais sejam feitas, para que os usuários possam achar os registros e atualizá-los de maneira mais eficiente.
