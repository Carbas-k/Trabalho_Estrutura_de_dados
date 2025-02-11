#ifndef BD_PACIENTE_H
#define BD_PACIENTE_H

#include <stdio.h>

// Estrutura que representa um paciente.
typedef struct Paciente {
    int id;
    char cpf[12];
    char nome[100];
    int idade;
    char data_cadastro[11];
} Paciente;

// Estrutura de um nó da lista encadeada.
typedef struct Node {
    Paciente paciente;
    struct Node *proximo;
} Node;

// Estrutura que representa o banco de dados de pacientes.
typedef struct {
    Node *primeiro;
    int tamanho;
} BDPaciente;

// Funções para manipulação do banco de dados.
BDPaciente *criar_bdpaciente();  // Cria e inicializa o banco de dados.
void liberar_bdpaciente(BDPaciente *bd);  // Libera a memória alocada.
void carregar_dados_csv(BDPaciente *bd, const char *nome_arquivo);  // Carrega dados do CSV.
void salvar_dados_csv(BDPaciente *bd, const char *nome_arquivo);    // Salva dados no CSV.

// Operações CRUD.
Paciente *consultar_paciente(BDPaciente *bd, const char *consulta);  // Consulta por CPF ou Nome.
Paciente *consultar_paciente_por_cpf(BDPaciente *bd, const char *cpf);  // Consulta exclusiva por CPF.
void atualizar_paciente(BDPaciente *bd, int id, const char *cpf, const char *nome, int idade, const char *data_cadastro);  // Atualiza um paciente.
void remover_paciente(BDPaciente *bd, int id);  // Remove um paciente pelo ID.
void inserir_paciente(BDPaciente *bd, const char *cpf, const char *nome, int idade, const char *data_cadastro);  // Insere um novo paciente.
void imprimir_pacientes(BDPaciente *bd);  // Imprime todos os pacientes.

#endif