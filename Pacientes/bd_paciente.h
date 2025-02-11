#ifndef BDPACIENTE_H
#define BDPACIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura Paciente
typedef struct Paciente {
    int id;
    char cpf[15];
    char nome[100];
    int idade;
    char data_cadastro[11];
    struct Paciente *proximo;
} Paciente;

// Definição do TAD BDPaciente
typedef struct {
    Paciente *primeiro;
    int tamanho;
} BDPaciente;

// Funções públicas
BDPaciente *criar_bdpaciente();
void carregar_dados_csv(BDPaciente *bd, const char *nome_arquivo);
void salvar_dados_csv(BDPaciente *bd, const char *nome_arquivo);
void liberar_bdpaciente(BDPaciente *bd);

// Operações CRUD
Paciente *consultar_paciente(BDPaciente *bd, const char *cpf_ou_nome);
void atualizar_paciente(BDPaciente *bd, int id, const char *cpf, const char *nome, int idade, const char *data_cadastro);
void remover_paciente(BDPaciente *bd, int id);
void inserir_paciente(BDPaciente *bd, const char *cpf, const char *nome, int idade, const char *data_cadastro);
void imprimir_pacientes(BDPaciente *bd);

#endif