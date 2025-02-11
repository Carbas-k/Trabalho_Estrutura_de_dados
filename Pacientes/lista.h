#ifndef LISTA_H
#define LISTA_H

// Estrutura que representa um paciente.
typedef struct Paciente {
    int id;
    char cpf[15];
    char nome[100];
    int idade;
    char data_cadastro[11];
} Paciente;

// Estrutura de um nó da lista encadeada.
typedef struct Node {
    Paciente paciente;
    struct Node *proximo;
} Node;

// Estrutura que representa a lista encadeada.
typedef struct {
    Node *primeiro;
} LinkedList;

// Funções para manipulação da lista.
LinkedList *criar_lista();  // Cria e inicializa uma lista encadeada.
void liberar_lista(LinkedList *lista);  // Libera a memória alocada.
void adicionar_paciente(LinkedList *lista, Paciente paciente);  // Adiciona um paciente à lista.
void remover_paciente_por_id(LinkedList *lista, int id);  // Remove um paciente pelo ID.
Node *consultar_paciente_por_cpf_ou_nome(LinkedList *lista, const char *consulta);  // Consulta por CPF ou Nome.
void imprimir_lista(LinkedList *lista);  // Imprime todos os pacientes da lista.

#endif