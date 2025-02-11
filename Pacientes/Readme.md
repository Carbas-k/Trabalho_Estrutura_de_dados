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

_**Funções do programa:**_

| Funções em arquivo.c     | Descrição| Parâmetros   |  Retorno  |
|------------|:--------:|-------------:|----------:|
| f_carregarDados  |  Carrega os arquivos e abre para leitura    | LinkedList *lista e const char *nome_arquivo|        Void   |
| f_salvarDados     |  Salva os dados de uma lista encadeada em um arquivo CSV   | LinkedList *lista e const char *nome_arquivo    |     Void      |


| Função bd_pacientes.c                    | Descrição                                                                                     | Parâmetros                                                                                             | Retorno                                                                 |
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

| **Função lista.c**                              | **Descrição**                                                                                     | **Parâmetros**                                                                                             | **Retorno**                                                                 |
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



_**Como Executar**_
1. Clone o repositório.
2. Execute `make` para compilar o programa.
3. Execute `./sistema_pacientes` para iniciar o sistema.


