#ifndef VALIDACAO_H
#define VALIDACAO_H

int validar_cpf(const char *cpf);// Valida se o CPF fornecido é válido (11 dígitos numéricos e formato correto).
int validar_data(const char *data);// Valida se a data está no formato AAAA-MM-DD.
void formatar_cpf(const char *cpf_numerico, char *cpf_formatado);// Formata um CPF numérico (11 dígitos) para o formato xxx.xxx.xxx-xx.

#endif