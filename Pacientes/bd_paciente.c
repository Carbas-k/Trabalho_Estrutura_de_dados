#include "bd_paciente.h"

// Cria uma nova instancia do BDPaciente
BDPaciente *criar_bdpaciente() {
    BDPaciente *bd = (BDPaciente *)malloc(sizeof(BDPaciente));
    if (!bd) {
        perror("Erro ao alocar memória para BDPaciente");
        return NULL;
    }
    bd->primeiro = NULL;
    bd->tamanho = 0;
    return bd;
}

// Libera a memoria alocada para o TAD
void liberar_bdpaciente(BDPaciente *bd) {
    Paciente *atual = bd->primeiro;
    while (atual) {
        Paciente *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(bd);
}

// Carrega os dados do arquivo CSV para o TAD
void carregar_dados_csv(BDPaciente *bd, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo CSV");
        return;
    }

    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Ignora o cabecalho

    while (fgets(linha, sizeof(linha), arquivo)) {
        Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
        if (!novo) {
            perror("Erro ao alocar memória para Paciente");
            fclose(arquivo);
            return;
        }

        sscanf(linha, "%d,%[^,],%[^,],%d,%s", &novo->id, novo->cpf, novo->nome, &novo->idade, novo->data_cadastro);
        novo->proximo = bd->primeiro;
        bd->primeiro = novo;
        bd->tamanho++;
    }

    fclose(arquivo);
}

// Salva os dados do TAD no arquivo CSV
void salvar_dados_csv(BDPaciente *bd, const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao salvar o arquivo CSV");
        return;
    }

    fprintf(arquivo, "ID,CPF,Nome,Idade,Data_Cadastro\n");
    Paciente *atual = bd->primeiro;
    while (atual) {
        fprintf(arquivo, "%d,%s,%s,%d,%s\n", atual->id, atual->cpf, atual->nome, atual->idade, atual->data_cadastro);
        atual = atual->proximo;
    }

    fclose(arquivo);
}

// Insere um novo paciente
void inserir_paciente(BDPaciente *bd, const char *cpf, const char *nome, int idade, const char *data_cadastro) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (!novo) {
        perror("Erro ao alocar memória para Paciente");
        return;
    }

    novo->id = bd->tamanho + 1;
    strcpy(novo->cpf, cpf);
    strcpy(novo->nome, nome);
    novo->idade = idade;
    strcpy(novo->data_cadastro, data_cadastro);
    novo->proximo = bd->primeiro;
    bd->primeiro = novo;
    bd->tamanho++;
}

// Consulta um paciente pelo CPF ou Nome
Paciente *consultar_paciente(BDPaciente *bd, const char *cpf_ou_nome) {
    Paciente *atual = bd->primeiro;
    while (atual) {
        if (strcmp(atual->cpf, cpf_ou_nome) == 0 || strstr(atual->nome, cpf_ou_nome)) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

// Atualiza os dados de um paciente
void atualizar_paciente(BDPaciente *bd, int id, const char *cpf, const char *nome, int idade, const char *data_cadastro) {
    Paciente *atual = bd->primeiro;
    while (atual) {
        if (atual->id == id) {
            if (strcmp(cpf, "-") != 0) strcpy(atual->cpf, cpf);
            if (strcmp(nome, "-") != 0) strcpy(atual->nome, nome);
            if (idade != -1) atual->idade = idade;
            if (strcmp(data_cadastro, "-") != 0) strcpy(atual->data_cadastro, data_cadastro);
            return;
        }
        atual = atual->proximo;
    }
}

// Remove um paciente pelo ID
void remover_paciente(BDPaciente *bd, int id) {
    Paciente *anterior = NULL;
    Paciente *atual = bd->primeiro;

    while (atual) {
        if (atual->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                bd->primeiro = atual->proximo;
            }
            free(atual);
            bd->tamanho--;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

// Imprime todos os pacientes
void imprimir_pacientes(BDPaciente *bd) {
    Paciente *atual = bd->primeiro;
    printf("ID\tCPF\t\tNome\t\tIdade\tData_Cadastro\n");
    while (atual) {
        printf("%d\t%s\t%s\t%d\t%s\n", atual->id, atual->cpf, atual->nome, atual->idade, atual->data_cadastro);
        atual = atual->proximo;
    }
}