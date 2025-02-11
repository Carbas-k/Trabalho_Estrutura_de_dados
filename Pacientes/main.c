#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bd_paciente.h"

void exibir_menu() {
    printf("\n=== Sistema de Gerenciamento de Pacientes ===\n");
    printf("1 - Consultar paciente\n");
    printf("2 - Atualizar paciente\n");
    printf("3 - Remover paciente\n");
    printf("4 - Inserir paciente\n");
    printf("5 - Imprimir lista de pacientes\n");
    printf("Q - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    BDPaciente *bd = criar_bdpaciente();
    carregar_dados_csv(bd, "bd_paciente.csv");

    char opcao;
    do {
        exibir_menu();
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': {
                char consulta[100];
                printf("Digite o CPF ou Nome para consulta: ");
                scanf(" %[^\n]", consulta);
                Paciente *resultado = consultar_paciente(bd, consulta);
                if (resultado) {
                    printf("Paciente encontrado:\n");
                    printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data_Cadastro: %s\n",
                           resultado->id, resultado->cpf, resultado->nome, resultado->idade, resultado->data_cadastro);
                } else {
                    printf("Paciente nao encontrado.\n");
                }
                break;
            }
            case '2': {
                char consulta[100];
                printf("Digite o CPF ou Nome para localizar o paciente: ");
                scanf(" %[^\n]", consulta);

                Paciente *resultado = consultar_paciente(bd, consulta);
                if (!resultado) {
                    printf("Paciente nao encontrado.\n");
                    break;
                }

                printf("Paciente encontrado:\n");
                printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data_Cadastro: %s\n",
                    resultado->id, resultado->cpf, resultado->nome, resultado->idade, resultado->data_cadastro);

                char novo_cpf[15], novo_nome[100], nova_data[11];
                int nova_idade;

                printf("Digite o novo CPF (ou '-' para manter): ");
                scanf(" %[^\n]", novo_cpf);

                printf("Digite o novo Nome (ou '-' para manter): ");
                scanf(" %[^\n]", novo_nome);

                printf("Digite a nova Idade (ou -1 para manter): ");
                scanf("%d", &nova_idade);

                printf("Digite a nova Data de Cadastro (AAAA-MM-DD) (ou '-' para manter): ");
                scanf(" %[^\n]", nova_data);

                atualizar_paciente(bd, resultado->id,
                                strcmp(novo_cpf, "-") != 0 ? novo_cpf : "-",
                                strcmp(novo_nome, "-") != 0 ? novo_nome : "-",
                                nova_idade != -1 ? nova_idade : -1,
                                strcmp(nova_data, "-") != 0 ? nova_data : "-");

                printf("Paciente atualizado com sucesso!\n");
                break;
            }
            case '3': {
                char consulta[100];
                printf("Digite o CPF ou Nome para localizar o paciente: ");
                scanf(" %[^\n]", consulta);

                Paciente *resultado = consultar_paciente(bd, consulta);
                if (!resultado) {
                    printf("Paciente nao encontrado.\n");
                    break;
                }

                printf("Paciente encontrado:\n");
                printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data_Cadastro: %s\n",
                    resultado->id, resultado->cpf, resultado->nome, resultado->idade, resultado->data_cadastro);

                char confirmacao;
                printf("Tem certeza de que deseja remover este paciente? (S/N): ");
                scanf(" %c", &confirmacao);

                if (confirmacao == 'S' || confirmacao == 's') {
                    remover_paciente(bd, resultado->id);
                    printf("Paciente removido com sucesso!\n");
                } else {
                    printf("Operacao cancelada.\n");
                }
                break;
            }
            case '4': {
                char cpf[15], nome[100], data[11];
                int idade;

                printf("Digite o CPF (apenas numeros): ");
                scanf(" %[^\n]", cpf);

                printf("Digite o Nome: ");
                scanf(" %[^\n]", nome);

                printf("Digite a Idade: ");
                scanf("%d", &idade);

                printf("Digite a Data de Cadastro (AAAA-MM-DD): ");
                scanf(" %[^\n]", data);

                // Validação básica
                if (strlen(cpf) != 11 || idade <= 0 || strlen(data) != 10) {
                    printf("Dados invalidos. Operacao cancelada.\n");
                    break;
                }

                inserir_paciente(bd, cpf, nome, idade, data);
                printf("Paciente inserido com sucesso!\n");
                break;
            }
            case '5': {
                imprimir_pacientes(bd);
                break;
            }
            case 'Q':
            case 'q':
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 'Q' && opcao != 'q');

    salvar_dados_csv(bd, "bd_paciente.csv");
    liberar_bdpaciente(bd);
    return 0;
}