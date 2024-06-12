#ifndef CARTA_H
#define CARTA_H

#define RESET "\e[0m"
#define BG_BLACK "\e[40m"
#define FG_WHITE "\033[1m\033[38;2;255;255;255m"
#define BG_WHITE "\033[48;2;255;255;255m"

// theme color
#define BG_ORANGE "\033[48;2;247;159;17m"
#define FG_ORANGE "\033[1m\033[38;2;247;159;17m"
#define BG_GRAY "\033[48;2;61;71;74m"
#define FG_GRAY "\033[1m\033[38;2;61;71;74m"

// icone color
#define FG_RED "\033[1m\033[38;2;255;0;0m"
#define FG_GREEN "\033[1m\033[38;2;0;255;0m"
#define FG_BLUE "\033[1m\033[38;2;0;0;255m"
#define FG_YELLOW "\033[1m\033[38;2;255;255;0m"
#define FG_SILVER "\033[1m\033[38;2;192;192;192m"

// maximo de cartas
#define MAX_CARTAS 33
#define MAX_PLAYERS 3

typedef struct carta {
  char *tipo;
  int vida, ataque;
  float mobilidade, cura, ultimate;

} Carta;

// CRIA CARTA
Carta *criarCarta(char *tipo, float mobilidade, int vida, int ataque,
                  float cura, float ultimate);

// MODELAGEM CARTA
void printVazio();
void printNome(char *tipo, char *nome);
void printIntInfoLine(char *atributo, int value, char *color, char *icone);
void modeloCartaInteira(char *nome, Carta *carta, int x, int y);

// CRIAR VETOR DE CARTAS , EMBARALHAR O VETOR E PRINTA CARTA
Carta **criarVetorCartas();
void embaralhar(Carta **vetorcartas);
void printCarta(Carta *carta, int x, int y);

void print0();
void print1();
void print2();
void print3();
void print4();
void print5();
void print6();
void print7(char *color);
void print8();
void print9();
void print10();
void print11();
void print12();
void printCartaVirada(int x, int y);

#endif // CARTA_H