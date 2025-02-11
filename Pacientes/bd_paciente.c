#include "bd_paciente.h"
#include "validacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cria e inicializa o banco de dados.
BDPaciente *criar_bdpaciente() {
    BDPaciente *bd = (BDPaciente *)malloc(sizeof(BDPaciente));
    bd->primeiro = NULL; // Lista inicialmente vazia.
    bd->tamanho = 0;     // Tamanho inicial é zero.
    return bd;
}

// Libera a memória alocada para o banco de dados.
void liberar_bdpaciente(BDPaciente *bd) {
    Node *atual = bd->primeiro;
    while (atual) {               // Percorre todos os nós.
        Node *proximo = atual->proximo;
        free(atual);              // Libera cada nó.
        atual = proximo;
    }
    free(bd);                     // Libera a estrutura do banco de dados.
}

// Carrega os dados do arquivo CSV para o banco de dados.
void carregar_dados_csv(BDPaciente *bd, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r"); // Abre o arquivo para leitura.
    if (!arquivo) {                           // Verifica se o arquivo foi aberto.
        perror("Erro ao abrir o arquivo CSV");
        return;
    }
    char linha[256];
    fgets(linha, sizeof(linha), arquivo);     // Ignora o cabeçalho.
    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo.
        Paciente paciente;
        sscanf(linha, "%d,%[^,],%[^,],%d,%s",      // Extrai os campos do CSV.
               &paciente.id,
               paciente.cpf, paciente.nome, &paciente.idade, paciente.data_cadastro);
        Node *novo = (Node *)malloc(sizeof(Node)); // Cria um novo nó.
        novo->paciente = paciente;
        novo->proximo = bd->primeiro;              // Insere no início da lista.
        bd->primeiro = novo;
        bd->tamanho++;
    }
    fclose(arquivo);                               // Fecha o arquivo.
}

// Salva os dados do banco de dados no arquivo CSV.
void salvar_dados_csv(BDPaciente *bd, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");      // Abre o arquivo para escrita.
    if (!arquivo) {                                // Verifica se o arquivo foi aberto.
        perror("Erro ao salvar o arquivo CSV");
        return;
    }
    fprintf(arquivo, "ID,CPF,Nome,Idade,Data_Cadastro\n"); // Escreve o cabeçalho.
    Node *atual = bd->primeiro;
    while (atual) {                               // Percorre todos os nós.
        fprintf(arquivo, "%d,%s,%s,%d,%s\n",      // Escreve os dados no arquivo.
                atual->paciente.id,
                atual->paciente.cpf,
                atual->paciente.nome,
                atual->paciente.idade,
                atual->paciente.data_cadastro);
        atual = atual->proximo;
    }
    fclose(arquivo);                              // Fecha o arquivo.
    printf("Dados salvos com sucesso no arquivo '%s'.\n", nome_arquivo);
}

// Consulta um paciente pelo CPF ou Nome.
Paciente *consultar_paciente(BDPaciente *bd, const char *consulta) {
    Node *atual = bd->primeiro;
    if (strlen(consulta) == 11 && validar_cpf(consulta)) { // Verifica se é um CPF válido.
        while (atual) {
            if (strcmp(atual->paciente.cpf, consulta) == 0) return &atual->paciente;
            atual = atual->proximo;
        }
    } else { // Caso contrário, busca por nome.
        while (atual) {
            if (strstr(atual->paciente.nome, consulta)) return &atual->paciente;
            atual = atual->proximo;
        }
    }
    return NULL; // Retorna NULL se nenhum paciente for encontrado.
}

// Consulta um paciente pelo CPF numérico.
Paciente *consultar_paciente_por_cpf(BDPaciente *bd, const char *cpf) {
    Node *atual = bd->primeiro;
    while (atual) {
        if (strcmp(atual->paciente.cpf, cpf) == 0) return &atual->paciente;
        atual = atual->proximo;
    }
    return NULL; // Retorna NULL se nenhum paciente for encontrado.
}

// Insere um novo paciente no banco de dados.
void inserir_paciente(BDPaciente *bd, const char *cpf, const char *nome, int idade, const char *data_cadastro) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->paciente.id = bd->tamanho + 1; // Gera um ID único.
    if (!validar_cpf(cpf)) {             // Valida o CPF antes de armazenar.
        printf("CPF inválido! Deve conter exatamente 11 dígitos numéricos.\n");
        free(novo);                      // Libera a memória alocada para o nó.
        return;
    }
    strcpy(novo->paciente.cpf, cpf);     // Armazena o CPF sem formatação.
    strcpy(novo->paciente.nome, nome);
    novo->paciente.idade = idade;
    strcpy(novo->paciente.data_cadastro, data_cadastro);
    novo->proximo = bd->primeiro;        // Insere no início da lista.
    bd->primeiro = novo;
    bd->tamanho++;
    printf("Paciente inserido com sucesso!\n");
}

// Atualiza os dados de um paciente existente.
void atualizar_paciente(BDPaciente *bd, int id, const char *cpf, const char *nome, int idade, const char *data_cadastro) {
    Node *atual = bd->primeiro;
    while (atual) {
        if (atual->paciente.id == id) {  // Localiza o paciente pelo ID.
            if (cpf) strcpy(atual->paciente.cpf, cpf); // Atualiza CPF apenas se fornecido.
            if (nome) strcpy(atual->paciente.nome, nome); // Atualiza nome apenas se fornecido.
            atual->paciente.idade = idade; // Atualiza idade.
            if (data_cadastro) strcpy(atual->paciente.data_cadastro, data_cadastro); // Atualiza data apenas se fornecida.
            return;
        }
        atual = atual->proximo;
    }
}

// Remove um paciente do banco de dados.
void remover_paciente(BDPaciente *bd, int id) {
    Node *anterior = NULL;
    Node *atual = bd->primeiro;
    while (atual) {
        if (atual->paciente.id == id) {  // Localiza o paciente pelo ID.
            if (anterior) anterior->proximo = atual->proximo;
            else bd->primeiro = atual->proximo;
            free(atual);                 // Libera o nó.
            bd->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

// Imprime todos os pacientes cadastrados.
void imprimir_pacientes(BDPaciente *bd) {
    Node *atual = bd->primeiro;
    if (!atual) {                        // Verifica se a lista está vazia.
        printf("Nenhum paciente cadastrado.\n");
        return;
    }
    printf("\n=== Lista de Pacientes ===\n");
    printf("%-5s %-15s %-20s %-7s %-12s\n", "ID", "CPF", "Nome", "Idade", "Data_Cadastro");
    printf("-------------------------------------------------------------\n");
    while (atual) {
        char cpf_formatado[15];
        formatar_cpf(atual->paciente.cpf, cpf_formatado); // Formata o CPF para exibição.
        printf("%-5d %-15s %-20s %-7d %-12s\n",
               atual->paciente.id,
               cpf_formatado,
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.data_cadastro);
        atual = atual->proximo;
    }
}