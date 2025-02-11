#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "lista.h"

void f_carregarDados(LinkedList *lista, const char *nome_arquivo);// Carrega os dados de um arquivo CSV para a lista encadeada.
void f_salvarDados(LinkedList *lista, const char *nome_arquivo);// Salva os dados da lista encadeada em um arquivo CSV.

#endif