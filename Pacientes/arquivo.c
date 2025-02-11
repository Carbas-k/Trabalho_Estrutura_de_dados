#include "arquivo.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Carrega dados do arquivo CSV para a lista encadeada.
void f_carregarDados(LinkedList *lista, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura.
    if (!arquivo) {                          // Verifica se o arquivo foi aberto.
        perror("Erro ao abrir o arquivo CSV");
        return;
    }
    char linha[256];                         // Buffer para ler cada linha.
    fgets(linha, sizeof(linha), arquivo);    // Ignora o cabeçalho.

    while (fgets(linha, sizeof(linha), arquivo)) { // Lê os dados dos pacientes.
        Paciente paciente;
        sscanf(linha, "%d,%[^,],%[^,],%d,%s",      // Extrai os campos do CSV.
               &paciente.id, paciente.cpf, paciente.nome, &paciente.idade, paciente.data_cadastro);
        adicionar_paciente(lista, paciente);       // Adiciona à lista.
    }
    fclose(arquivo);                               // Fecha o arquivo.
}

// Salva os dados da lista encadeada no arquivo CSV.
void f_salvarDados(LinkedList *lista, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");      // Abre o arquivo para escrita.
    if (!arquivo) {                                // Verifica se o arquivo foi aberto.
        perror("Erro ao salvar o arquivo CSV");
        return;
    }
    fprintf(arquivo, "ID,CPF,Nome,Idade,Data_Cadastro\n"); // Escreve o cabeçalho.

    Node *atual = lista->primeiro;                // Inicializa o ponteiro para a lista.
    while (atual) {                               // Percorre a lista.
        fprintf(arquivo, "%d,%s,%s,%d,%s\n",      // Escreve os dados no arquivo.
                atual->paciente.id,
                atual->paciente.cpf,
                atual->paciente.nome,
                atual->paciente.idade,
                atual->paciente.data_cadastro);
        atual = atual->proximo;                   // Avança para o próximo nó.
    }
    fclose(arquivo);                              // Fecha o arquivo.
}