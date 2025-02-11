#include "menu.h"
#include "bd_paciente.h"
#include <stdio.h>

int main() {
    BDPaciente *bd = criar_bdpaciente(); // Cria o banco de dados
    carregar_dados_csv(bd, "bd_paciente.csv"); // Carrega os dados do arquivo CSV
    f_exibirMenu(bd); // Exibe o menu principal
    salvar_dados_csv(bd, "bd_paciente.csv"); // Salva os dados antes de sair
    liberar_bdpaciente(bd); // Libera a memória alocada para o banco de dados
    return 0;
}