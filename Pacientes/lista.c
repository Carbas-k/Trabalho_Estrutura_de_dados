#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria e inicializa uma lista encadeada.
LinkedList *criar_lista() {
    LinkedList *lista = (LinkedList *)malloc(sizeof(LinkedList)); // Aloca memória para a lista.
    lista->primeiro = NULL; // Lista inicialmente vazia.
    return lista;
}

// Libera a memória alocada para a lista encadeada.
void liberar_lista(LinkedList *lista) {
    Node *atual = lista->primeiro;
    while (atual) {               // Percorre todos os nós da lista.
        Node *proximo = atual->proximo;
        free(atual);              // Libera cada nó.
        atual = proximo;
    }
    free(lista);                  // Libera a estrutura da lista.
}

// Adiciona um novo paciente no início da lista.
void adicionar_paciente(LinkedList *lista, Paciente paciente) {
    Node *novo = (Node *)malloc(sizeof(Node)); // Aloca memória para o novo nó.
    novo->paciente = paciente;                // Armazena os dados do paciente.
    novo->proximo = lista->primeiro;          // Insere no início da lista.
    lista->primeiro = novo;
}

// Remove um paciente da lista pelo ID.
void remover_paciente_por_id(LinkedList *lista, int id) {
    Node *anterior = NULL;
    Node *atual = lista->primeiro;
    while (atual) {
        if (atual->paciente.id == id) {       // Localiza o paciente pelo ID.
            if (anterior) anterior->proximo = atual->proximo;
            else lista->primeiro = atual->proximo;
            free(atual);                      // Libera o nó.
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

// Consulta um paciente pela chave (CPF ou Nome).
Node *consultar_paciente_por_cpf_ou_nome(LinkedList *lista, const char *consulta) {
    Node *atual = lista->primeiro;
    while (atual) {
        if (strcmp(atual->paciente.cpf, consulta) == 0 || strstr(atual->paciente.nome, consulta)) {
            return atual;                     // Retorna o nó se encontrado.
        }
        atual = atual->proximo;
    }
    return NULL;                              // Retorna NULL se não encontrado.
}

// Imprime todos os pacientes da lista.
void imprimir_lista(LinkedList *lista) {
    Node *atual = lista->primeiro;
    printf("ID\tCPF\tNome\tIdade\tData_Cadastro\n"); // Cabeçalho da tabela.
    while (atual) {
        printf("%d\t%s\t%s\t%d\t%s\n",              // Imprime os dados do paciente.
               atual->paciente.id,
               atual->paciente.cpf,
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.data_cadastro);
        atual = atual->proximo;
    }
}