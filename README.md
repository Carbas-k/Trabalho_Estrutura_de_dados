# Sistema de Gerenciamento de Pacientes

## Como Executar
1. Clone o repositório.
2. Execute `make` para compilar o programa.
3. Execute `./sistema_pacientes` para iniciar o sistema.

## Estrutura do Projeto
- `main.c`: Programa principal.
- `bd_paciente.h` e `bd_paciente.c`: Implementação do TAD BDPaciente.
- `utils.h` e `utils.c`: Funções utilitárias.
- `Makefile`: Para compilação.

## Decisões de Implementação
- O TAD BDPaciente utiliza uma lista encadeada para armazenar os registros.
- As operações CRUD são implementadas de forma modular.
- O arquivo CSV é carregado na inicialização e salvo ao sair.