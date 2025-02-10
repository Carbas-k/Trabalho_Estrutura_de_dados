**Sistema de Gerenciamento de Pacientes
**

**Descrição do projeto:**
O Simulador de Sistema de Gerenciamento de Dados de Paciente é um projeto acadêmico desenvolvido para a disciplina de Estrutura de Dados, lecionada pelo Prof. Dr. Thiago Meireles Paixão. O objetivo principal do sistema é fornecer um ambiente estruturado para armazenar, buscar, atualizar e remover registros de pacientes utilizando Listas Encadeadas

_**Estrutura do repositório:**_
📂 **Trabalho_Estrutura_de_Dados **
│── 📂 PACIENTES         # Gerenciamento de dados dos pacientes  
│────📜 Makefile          # Arquivo para compilação automática do projeto  
│──── 📜 README.md         # Documentação do projeto  
│──── 📜 bd_pacientes.csv  # Arquivo de dados dos pacientes utilizado pelo programa  
│──── 📜 main.c            # Arquivo principal do programa
│──── 📜 bd_paciente.c            # Arquivo implementa um banco de dados de pacientes em C utilizando uma lista encadeada
│──── 📜 bd_paciente.h           # Arquivo de cabeçalho para a implementação do banco de dados de pacientes.
│─📜ESPECIFICAÇÃO     # Documentação técnica e requisitos do projeto 



_** Decisões de Implementação:**_

**Estrutura do Banco de Dados - **A escolha de armazenar os dados dos pacientes em colunas que contém: ID,CPF, Nome, Idade e Data de Cadastro se dá pela necessidade de registro de informações básicas do paciente.

**Formato dos dados -** A escolha do formato do CPF e da Data por conter pontos e traços (ex.:123.456.789.01 e YYY-MM-DD) possui sua motivação na usabilidade e melhoria do entendimento para o usuário do sistema, uma vez que humanos possuem maior afinidade com esse modelo e costumam registar e passar seus dados dessa maneira.

**Validação dos dados -** A verificação contida no CPF tem o intuito de mitigar possíveis erros de digitação. Já a verificação na data permite que apenas pacientes com idades reais, portanto de valores maiores que 0 sejam registrados.

**Escopo Temporal -** A coluna de registro Data de cadastro vai permitir que análises temporais sejam feitas, para que os usuários possam achar os registros e atualizá-los de maneira mais eficiente.

_**Módulos do programa:**_
  




_**Como Executar**_
1. Clone o repositório.
2. Execute `make` para compilar o programa.
3. Execute `./sistema_pacientes` para iniciar o sistema.


