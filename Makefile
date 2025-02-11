CC = gcc
CFLAGS = -Wall -g
TARGET = sistema_pacientes # Nome do executável final.

all: $(TARGET)

# Linka os objetos para gerar o executável.
$(TARGET): main.o menu.o bd_paciente.o validacao.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o menu.o bd_paciente.o validacao.o

# Compila o arquivo main.c.
main.o: main.c menu.h bd_paciente.h
	$(CC) $(CFLAGS) -c main.c

# Compila o arquivo menu.c.
menu.o: menu.c menu.h bd_paciente.h validacao.h
	$(CC) $(CFLAGS) -c menu.c

# Compila o arquivo bd_paciente.c.
bd_paciente.o: bd_paciente.c bd_paciente.h validacao.h
	$(CC) $(CFLAGS) -c bd_paciente.c

# Compila o arquivo validacao.c.
validacao.o: validacao.c validacao.h
	$(CC) $(CFLAGS) -c validacao.c

# Limpa arquivos compilados e o executável.
clean:
	rm -f *.o $(TARGET)