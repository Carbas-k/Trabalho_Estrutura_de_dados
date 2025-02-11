#ifndef MENU_H
#define MENU_H

#include "bd_paciente.h"

void f_exibirMenu(BDPaciente *bd);// Exibe o menu principal e processa as opções do usuário.
void f_consultarPaciente(BDPaciente *bd);// Consulta um paciente pelo Nome ou CPF.
void f_atualizarPaciente(BDPaciente *bd);// Atualiza os dados de um paciente existente.
void f_removerPaciente(BDPaciente *bd);// Remove um paciente existente do sistema.
void f_inserirNovoPaciente(BDPaciente *bd);// Insere um novo paciente no sistema.
void f_imprimirLista(BDPaciente *bd);// Imprime todos os pacientes cadastrados no sistema.

#endif