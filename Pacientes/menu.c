#include "menu.h"
#include "bd_paciente.h"
#include "validacao.h"
#include <string.h>
#include <stdlib.h>

// Exibe o menu principal e processa as opções do usuário.
void f_exibirMenu(BDPaciente *bd) {
    char opcao; // Armazena a opção do usuário.
    do {
        printf("\n======= Health System =======\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Atualizar paciente\n");
        printf("3 - Remover paciente\n");
        printf("4 - Inserir paciente\n");
        printf("5 - Imprimir lista de pacientes\n");
        printf("Q - Sair\n> ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': 
                f_consultarPaciente(bd);    // Chama função para consultar paciente.
                break;
            case '2': 
                f_atualizarPaciente(bd);    // Chama função para atualizar paciente.
                break;
            case '3': 
                f_removerPaciente(bd);      // Chama função para remover paciente.
                break;
            case '4': 
                f_inserirNovoPaciente(bd);  // Chama função para inserir novo paciente.
                break;
            case '5':
                f_imprimirLista(bd);        // Chama função para imprimir lista de pacientes.
                break;
            case 'Q':
            case 'q':
                printf("Saindo...\n");       // Encerra o programa.
                break;
            default:
                printf("Opção inválida!\n"); // Informa que a opção é inválida.
                break;
        }
    } while (opcao != 'Q' && opcao != 'q'); // Repete até que o usuário escolha sair.
}

// Consulta um paciente pelo Nome ou CPF.
void f_consultarPaciente(BDPaciente *bd) {
    char consulta[100]; // Armazena a entrada do usuário (Nome ou CPF).
    printf("Escolha o modo de consulta:\n");
    printf("1 - Por nome\n");
    printf("2 - Por CPF\n");
    printf("3 - Retornar ao menu principal\n> ");
    int opcao;
    scanf("%d", &opcao);

    if (opcao == 3) return;                 // Retorna ao menu principal se escolhido.

    printf("Digite o %s para consulta: ", opcao == 1 ? "nome" : "CPF");
    scanf(" %[^\n]", consulta);             // Lê o valor para consulta.

    Node *atual = bd->primeiro;             // Ponteiro para percorrer a lista de pacientes.
    int encontrados = 0;                   // Contador de pacientes encontrados.

    // Cabeçalho da tabela de resultados.
    printf("\n%-5s %-15s %-20s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data_Cadastro");
    printf("-------------------------------------------------------------\n");

    while (atual) {                         // Percorre todos os pacientes.
        if ((opcao == 1 && strstr(atual->paciente.nome, consulta)) || // Busca por nome.
            (opcao == 2 && strcmp(atual->paciente.cpf, consulta) == 0)) { // Busca por CPF.
            printf("%-5d %-15s %-20s %-7d %-12s\n",
                   atual->paciente.id,
                   atual->paciente.cpf,
                   atual->paciente.nome,
                   atual->paciente.idade,
                   atual->paciente.data_cadastro);
            encontrados++;                  // Incrementa o contador de pacientes encontrados.
        }
        atual = atual->proximo;             // Avança para o próximo paciente.
    }

    if (encontrados == 0) {                 // Se nenhum paciente for encontrado.
        printf("Nenhum paciente encontrado.\n");
    }
}

// Atualiza os dados de um paciente existente.
void f_atualizarPaciente(BDPaciente *bd) {
    char consulta[100];                     // Armazena a entrada do usuário (Nome ou CPF).
    printf("Digite o CPF ou Nome para localizar o paciente: ");
    scanf(" %[^\n]", consulta);             // Lê o valor para consulta.

    Paciente *resultado = consultar_paciente(bd, consulta); // Localiza o paciente.
    if (!resultado) {                       // Verifica se o paciente foi encontrado.
        printf("Paciente nao encontrado.\n");
        return;
    }

    // Exibe os dados do paciente encontrado.
    printf("Paciente encontrado:\n");
    printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data_Cadastro: %s\n",
           resultado->id, resultado->cpf, resultado->nome, resultado->idade, resultado->data_cadastro);

    char novo_cpf_str[12], novo_nome[100], nova_data[11], nova_idade_str[10];
    printf("Digite o novo CPF (apenas numeros, ou '-' para manter): ");
    scanf(" %[^\n]", novo_cpf_str);         // Lê o novo CPF ou mantém o atual.
    printf("Digite o novo Nome (ou '-' para manter): ");
    scanf(" %[^\n]", novo_nome);            // Lê o novo Nome ou mantém o atual.
    printf("Digite a nova Idade (ou '-' para manter): ");
    scanf(" %[^\n]", nova_idade_str);       // Lê a nova Idade ou mantém a atual.
    printf("Digite a nova Data de Cadastro (AAAA-MM-DD) (ou '-' para manter): ");
    scanf(" %[^\n]", nova_data);            // Lê a nova Data de Cadastro ou mantém a atual.

    char novo_cpf_formatado[15];
    if (strcmp(novo_cpf_str, "-") != 0) {   // Valida o novo CPF se fornecido.
        if (!validar_cpf(novo_cpf_str)) {
            printf("CPF invalido! Deve conter exatamente 11 digitos numericos.\n");
            return;
        }
        formatar_cpf(novo_cpf_str, novo_cpf_formatado); // Formata o novo CPF.
    }

    int nova_idade = resultado->idade;     // Mantém a idade atual por padrão.
    if (strcmp(nova_idade_str, "-") != 0) { // Converte a nova idade para inteiro se fornecida.
        nova_idade = atoi(nova_idade_str);
        if (nova_idade <= 0) {
            printf("Idade invalida! Deve ser um numero inteiro positivo.\n");
            return;
        }
    }

    // Atualiza apenas os campos que não forem "-".
    atualizar_paciente(bd, resultado->id,
                       strcmp(novo_cpf_str, "-") != 0 ? novo_cpf_formatado : resultado->cpf,
                       strcmp(novo_nome, "-") != 0 ? novo_nome : resultado->nome,
                       nova_idade,
                       strcmp(nova_data, "-") != 0 ? nova_data : resultado->data_cadastro);

    printf("Paciente atualizado com sucesso!\n"); // Confirma a atualização.
}

// Remove um paciente existente.
void f_removerPaciente(BDPaciente *bd) {
    char consulta[100];                     // Armazena a entrada do usuário (Nome ou CPF).
    printf("Digite o CPF ou Nome para localizar o paciente: ");
    scanf(" %[^\n]", consulta);             // Lê o valor para consulta.

    Paciente *resultado = consultar_paciente(bd, consulta); // Localiza o paciente.
    if (!resultado) {                       // Verifica se o paciente foi encontrado.
        printf("Paciente nao encontrado.\n");
        return;
    }

    // Exibe os dados do paciente encontrado.
    printf("Paciente encontrado:\n");
    printf("ID: %d, CPF: %s, Nome: %s, Idade: %d, Data_Cadastro: %s\n",
           resultado->id, resultado->cpf, resultado->nome, resultado->idade, resultado->data_cadastro);

    char confirmacao;
    printf("Tem certeza de que deseja remover este paciente? (S/N): ");
    scanf(" %c", &confirmacao);             // Solicita confirmação do usuário.

    if (confirmacao == 'S' || confirmacao == 's') { // Remove o paciente se confirmado.
        remover_paciente(bd, resultado->id);
        printf("Paciente removido com sucesso!\n");
    } else {
        printf("Operacao cancelada.\n");    // Cancela a operação se negado.
    }
}

// Insere um novo paciente no sistema.
void f_inserirNovoPaciente(BDPaciente *bd) {
    char cpf_numerico[12], nome[100], data[11]; // Variáveis para armazenar os dados do paciente.
    int idade;

    printf("Digite o CPF (apenas números, 11 dígitos): ");
    scanf(" %[^\n]", cpf_numerico);         // Lê o CPF do paciente.
    printf("Digite o Nome: ");
    scanf(" %[^\n]", nome);                 // Lê o Nome do paciente.
    printf("Digite a Idade: ");
    scanf("%d", &idade);                    // Lê a Idade do paciente.
    printf("Digite a Data de Cadastro (AAAA-MM-DD): ");
    scanf(" %[^\n]", data);                 // Lê a Data de Cadastro do paciente.

    if (!validar_cpf(cpf_numerico)) {       // Valida o CPF.
        printf("CPF inválido! Deve conter exatamente 11 dígitos numéricos.\n");
        return;
    }
    if (idade <= 0) {                       // Valida a Idade.
        printf("Idade inválida! Deve ser um número inteiro positivo.\n");
        return;
    }
    if (!validar_data(data)) {              // Valida a Data de Cadastro.
        printf("Data de Cadastro inválida! Deve estar no formato AAAA-MM-DD.\n");
        return;
    }

    // Insere o paciente no sistema.
    inserir_paciente(bd, cpf_numerico, nome, idade, data);

    Paciente *novo = consultar_paciente_por_cpf(bd, cpf_numerico); // Consulta o paciente recém-inserido.
    if (novo) {
        char cpf_formatado[15];
        formatar_cpf(novo->cpf, cpf_formatado); // Formata o CPF para exibição.
        printf("\n=== Novo Registro Inserido ===\n");
        printf("ID: %d\n", novo->id);
        printf("CPF: %s\n", cpf_formatado);
        printf("Nome: %s\n", novo->nome);
        printf("Idade: %d\n", novo->idade);
        printf("Data_Cadastro: %s\n", novo->data_cadastro);
        printf("==============================\n");
    } else {
        printf("Erro ao confirmar o novo registro.\n"); // Informa erro se o paciente não for encontrado.
    }
}

// Imprime todos os pacientes cadastrados.
void f_imprimirLista(BDPaciente *bd) {
    Node *atual = bd->primeiro;             // Ponteiro para percorrer a lista de pacientes.
    if (!atual) {                           // Verifica se a lista está vazia.
        printf("Nenhum paciente cadastrado.\n");
        return;
    }

    // Cabeçalho da tabela de pacientes.
    printf("\n==================== Lista de Pacientes =========================\n");
    printf("%-5s %-15s %-20s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data_Cadastro");
    printf("-----------------------------------------------------------------\n");

    while (atual) {                         // Percorre todos os pacientes.
        char cpf_formatado[15];
        formatar_cpf(atual->paciente.cpf, cpf_formatado); // Formata o CPF para exibição.
        printf("%-5d %-15s %-20s %-7d %-12s\n",
               atual->paciente.id,
               cpf_formatado,
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.data_cadastro);
        atual = atual->proximo;             // Avança para o próximo paciente.
    }
}