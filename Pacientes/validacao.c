#include "validacao.h"
#include <stdio.h>
#include <string.h>

// Função para validar o CPF
int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11) return 0; // O CPF deve ter exatamente 11 caracteres
    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') return 0; // Todos os caracteres devem ser dígitos
    }
    return 1; // CPF válido
}

// Função para validar a data no formato AAAA-MM-DD
int validar_data(const char *data) {
    if (strlen(data) != 10) return 0; // A data deve ter exatamente 10 caracteres
    if (data[4] != '-' || data[7] != '-') return 0; // Verifica os separadores '-'

    int ano, mes, dia;
    sscanf(data, "%4d-%2d-%2d", &ano, &mes, &dia);

    // Verifica se a data é válida
    if (ano < 1900 || ano > 2100) return 0; // Ano deve estar em um intervalo razoável
    if (mes < 1 || mes > 12) return 0; // Mês deve estar entre 1 e 12
    if (dia < 1 || dia > 31) return 0; // Dia deve estar entre 1 e 31

    // Verifica meses com 30 dias
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) return 0;

    // Verifica fevereiro
    if (mes == 2) {
        if (dia > 29) return 0; // Fevereiro tem no máximo 29 dias
        if (dia == 29 && (ano % 4 != 0 || (ano % 100 == 0 && ano % 400 != 0))) return 0; // Ano bissexto
    }

    return 1; // Data válida
}

// Função para converter CPF numérico para formato xxx.xxx.xxx-xx
void formatar_cpf(const char *cpf_numerico, char *cpf_formatado) {
    if (strlen(cpf_numerico) != 11) {
        // Se o CPF não tiver 11 dígitos, retorna uma string vazia
        strcpy(cpf_formatado, "CPF_INVALIDO");
        return;
    }

    snprintf(cpf_formatado, 15, "%c%c%c.%c%c%c.%c%c%c-%c%c",
             cpf_numerico[0], cpf_numerico[1], cpf_numerico[2],
             cpf_numerico[3], cpf_numerico[4], cpf_numerico[5],
             cpf_numerico[6], cpf_numerico[7], cpf_numerico[8],
             cpf_numerico[9], cpf_numerico[10]);
}