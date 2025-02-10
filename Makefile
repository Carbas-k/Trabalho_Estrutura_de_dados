# Define o compilador a ser utilizado
CC = gcc 

# Define as flags de compilação
CFLAGS = -Wall -g

# Nome do executável final
TARGET = sistema_pacientes

# Regra padrão para compilar todo o projeto
all: $(TARGET)

# Regra para gerar o executável a partir dos arquivos objeto
$(TARGET): main.o bd_paciente.o
    $(CC) $(CFLAGS) -o $(TARGET) main.o bd_paciente.o

# Regra para compilar o arquivo main.c e gerar main.o
main.o: main.c bd_paciente.h
    $(CC) $(CFLAGS) -c main.c

# Regra para compilar o arquivo bd_paciente.c e gerar bd_paciente.o
bd_paciente.o: bd_paciente.c bd_paciente.h
    $(CC) $(CFLAGS) -c bd_paciente.c

# Regra para limpar os arquivos compilados (.o) e o executavel
clean:
    rm -f *.o $(TARGET)  
