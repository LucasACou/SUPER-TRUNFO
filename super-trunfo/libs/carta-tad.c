#include "../includes/carta-tad.h"
#include "../includes/terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Carta *criarCarta(char *tipo, int mobilidade, int vida, int ataque,
                  int cura, int ultimate) {
  Carta *nova_carta = malloc(sizeof(Carta));
  if (nova_carta != NULL) {
    nova_carta->tipo = tipo;
    nova_carta->mobilidade = mobilidade;
    nova_carta->vida = vida;
    nova_carta->ataque = ataque;
    nova_carta->cura = cura;
    nova_carta->ultimate = ultimate;
  }
  return nova_carta;
}

// MODELAGEM CARTAS

void printVazio() { printf(BG_GRAY "                         " RESET "\n"); }

void printNome(char *tipo, char *nome) {
  printf(BG_GRAY " " BG_BLACK FG_ORANGE " %s" FG_WHITE " %-18s " BG_GRAY
                 " " RESET "\n",
         tipo, nome);
}
void printIntInfoLine(char *atributo, int value, char *color, char *icone) {
  printf(BG_GRAY " " BG_BLACK " %s%s" FG_WHITE " %-11s " FG_ORANGE
                 " %4d " BG_GRAY "   " RESET "\n",
         color, icone, atributo, value);
}

void modeloCartaInteira(char *nome, Carta *carta, int x, int y) {
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printNome(carta->tipo, nome);
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printIntInfoLine("MOBILIDADE", carta->mobilidade, FG_BLUE, "\u26F8");
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printIntInfoLine("VIDA", carta->vida, FG_RED, "\u2764");
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printIntInfoLine("ATAQUE", carta->ataque, FG_SILVER, "\u2694");
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printIntInfoLine("CURA", carta->cura, FG_GREEN, "\u2720");
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printIntInfoLine("ULTIMATE", carta->ultimate, FG_YELLOW, "\u2605");
  mover_cursor_xy(x, y++);
  printVazio();
}

// Criar Vetor de Cartas
Carta **criarVetorCartas() {
  Carta **vetorCartas = malloc(MAX_CARTAS * sizeof(Carta *));
  if (vetorCartas != NULL) {
    //--------------------------------MB   VD   AT  CR   ULT
    vetorCartas[0] = criarCarta("SS", 9, 5, 8, 3, 10);  // Echo
    vetorCartas[1] = criarCarta("A1", 6, 3, 9, 3, 3);   // Widowmaker
    vetorCartas[2] = criarCarta("A2", 4, 4, 8, 3, 7);   // Ashe
    vetorCartas[3] = criarCarta("A3", 2, 4, 3, 9, 6);   // Ana
    vetorCartas[4] = criarCarta("B1", 5, 4, 7, 5, 8);   // Sombra
    vetorCartas[5] = criarCarta("B2", 1, 8, 8, 4, 7);   // Zarya
    vetorCartas[6] = criarCarta("B3", 8, 4, 7, 9, 7);   // Moira
    vetorCartas[7] = criarCarta("C1", 6, 5, 9, 5, 9);   // Reaper
    vetorCartas[8] = criarCarta("C2", 8, 4, 4, 8, 8);   // Lucio
    vetorCartas[9] = criarCarta("C3", 9, 4, 8, 3, 6);   // Genji
    vetorCartas[10] = criarCarta("D1", 5, 6, 5, 7, 6);  // Brigitte
    vetorCartas[11] = criarCarta("D2", 8, 7, 7, 3, 9);  // D.VA
    vetorCartas[12] = criarCarta("D3", 1, 8, 6, 3, 8);  // Sigma
    vetorCartas[13] = criarCarta("E1", 6, 7, 7, 5, 8);  // Mauga
    vetorCartas[14] = criarCarta("E2", 3, 5, 6, 7, 8);  // Mei
    vetorCartas[15] = criarCarta("E3", 7, 4, 2, 10, 5); // Mercy
    vetorCartas[16] = criarCarta("F1", 6, 10, 6, 3, 7); // Reinhardt
    vetorCartas[17] = criarCarta("F2", 8, 3, 7, 4, 7);  // Tracer
    vetorCartas[18] = criarCarta("F3", 5, 6, 6, 4, 6);  // RainhaJunker
    vetorCartas[19] = criarCarta("G1", 7, 4, 4, 8, 5);  // Kiriko
    vetorCartas[20] = criarCarta("G2", 3, 4, 8, 3, 8);  // Cassidy
    vetorCartas[21] = criarCarta("G3", 9, 7, 8, 3, 6);  // Doomfist
    vetorCartas[22] = criarCarta("H1", 6, 3, 9, 3, 8);  // Hanzo
    vetorCartas[23] = criarCarta("H2", 2, 3, 7, 5, 8);  // Zenyatta
    vetorCartas[24] = criarCarta("H3", 5, 4, 9, 3, 7);  // Junkrat
    vetorCartas[25] = criarCarta("I1", 5, 3, 3, 7, 8);  // Lifeweaver
    vetorCartas[26] = criarCarta("I2", 4, 3, 8, 5, 7);  // Soldado 76
    vetorCartas[27] = criarCarta("I3", 4, 4, 5, 7, 6);  // Illari
    vetorCartas[28] = criarCarta("J1", 1, 3, 10, 3, 5); // Bastion
    vetorCartas[29] = criarCarta("J2", 1, 6, 6, 3, 7);  // Ramatra
    vetorCartas[30] = criarCarta("J3", 5, 4, 8, 3, 4);  // Sojourn
    vetorCartas[31] = criarCarta("K1", 3, 3, 8, 3, 6);  // Symmetra
    vetorCartas[32] = criarCarta("K2", 5, 6, 6, 3, 5);  // Winston
  }
  return vetorCartas;
}

// Embaralhar Vetor de Cartas
void embaralhar(Carta **vetorcartas) {

  for (int i = 0; i < MAX_CARTAS; i++) {
    srand(time(0));
    int j = rand() % MAX_CARTAS;
    Carta *temp = vetorcartas[i];
    vetorcartas[i] = vetorcartas[j];
    vetorcartas[j] = temp;
  }
}

// Printar cartas
void printCarta(Carta *carta, int x, int y) {
  if (strcmp(carta->tipo, "SS") == 0) { // Carta SS
    modeloCartaInteira("ECHO", carta, x, y);

  } else if (strcmp(carta->tipo, "A1") == 0) { // Carta A1
    modeloCartaInteira("WIDOWMAKER", carta, x, y);

  } else if (strcmp(carta->tipo, "A2") == 0) { // Carta A2
    modeloCartaInteira("ASHE", carta, x, y);

  } else if (strcmp(carta->tipo, "A3") == 0) { // Carta A3
    modeloCartaInteira("ANA", carta, x, y);

  } else if (strcmp(carta->tipo, "B1") == 0) { // Carta B1
    modeloCartaInteira("SOMBRA", carta, x, y);

  } else if (strcmp(carta->tipo, "B2") == 0) { // Carta B2
    modeloCartaInteira("ZARYA", carta, x, y);

  } else if (strcmp(carta->tipo, "B3") == 0) { // Carta B3
    modeloCartaInteira("MOIRA", carta, x, y);

  } else if (strcmp(carta->tipo, "C1") == 0) { // Carta C1
    modeloCartaInteira("REAPER", carta, x, y);

  } else if (strcmp(carta->tipo, "C2") == 0) { // Carta C2
    modeloCartaInteira("LUCIO", carta, x, y);

  } else if (strcmp(carta->tipo, "C3") == 0) { // Carta C3
    modeloCartaInteira("GENJI", carta, x, y);

  } else if (strcmp(carta->tipo, "D1") == 0) { // Carta D1
    modeloCartaInteira("BRIGITTE", carta, x, y);

  } else if (strcmp(carta->tipo, "D2") == 0) { // Carta D2
    modeloCartaInteira("D.VA", carta, x, y);

  } else if (strcmp(carta->tipo, "D3") == 0) { // Carta D3
    modeloCartaInteira("SIGMA", carta, x, y);

  } else if (strcmp(carta->tipo, "E1") == 0) { // Carta E1
    modeloCartaInteira("MAUGA", carta, x, y);

  } else if (strcmp(carta->tipo, "E2") == 0) { // Carta E2
    modeloCartaInteira("MEI", carta, x, y);

  } else if (strcmp(carta->tipo, "E3") == 0) { // Carta E3
    modeloCartaInteira("MERCY", carta, x, y);

  } else if (strcmp(carta->tipo, "F1") == 0) { // Carta F1
    modeloCartaInteira("REINHARDT", carta, x, y);

  } else if (strcmp(carta->tipo, "F2") == 0) { // Carta F2
    modeloCartaInteira("TRACER", carta, x, y);

  } else if (strcmp(carta->tipo, "F3") == 0) { // Carta F3
    modeloCartaInteira("RAINHA JUNKER", carta, x, y);

  } else if (strcmp(carta->tipo, "G1") == 0) { // Carta G1
    modeloCartaInteira("KIRIKO", carta, x, y);

  } else if (strcmp(carta->tipo, "G2") == 0) { // Carta G2
    modeloCartaInteira("CASSIDY", carta, x, y);

  } else if (strcmp(carta->tipo, "G3") == 0) { // Carta G3
    modeloCartaInteira("DOOMFIST", carta, x, y);

  } else if (strcmp(carta->tipo, "H1") == 0) { // Carta H1
    modeloCartaInteira("HANZO", carta, x, y);

  } else if (strcmp(carta->tipo, "H2") == 0) { // Carta H2
    modeloCartaInteira("ZENYATTA", carta, x, y);

  } else if (strcmp(carta->tipo, "H3") == 0) { // Carta H3
    modeloCartaInteira("JUNKRAT", carta, x, y);

  } else if (strcmp(carta->tipo, "I1") == 0) { // Carta I1
    modeloCartaInteira("LIFEWEAVER", carta, x, y);

  } else if (strcmp(carta->tipo, "I2") == 0) { // Carta I2
    modeloCartaInteira("SOLDADO 76", carta, x, y);

  } else if (strcmp(carta->tipo, "I3") == 0) { // Carta I3
    modeloCartaInteira("ILLARI", carta, x, y);

  } else if (strcmp(carta->tipo, "J1") == 0) { // Carta J1
    modeloCartaInteira("BASTION", carta, x, y);

  } else if (strcmp(carta->tipo, "J2") == 0) { // Carta J2
    modeloCartaInteira("RAMATRA", carta, x, y);

  } else if (strcmp(carta->tipo, "J3") == 0) { // Carta J3
    modeloCartaInteira("SOJOURN", carta, x, y);

  } else if (strcmp(carta->tipo, "K1") == 0) { // Carta K1
    modeloCartaInteira("SYMMETRA", carta, x, y);

  } else if (strcmp(carta->tipo, "K2") == 0) { // Carta K2
    modeloCartaInteira("WINSTON", carta, x, y);

  } else {
    printf("Tipo de carta inválido\n" RESET);
  }
}

void print0() { printf(BG_WHITE "                         " RESET "\n"); }
void print1() {
  printf(BG_ORANGE "  " BG_GRAY "                     " BG_ORANGE "  " RESET
                   "\n");
}
void print2() {
  printf(BG_ORANGE " " BG_WHITE "                       " BG_ORANGE " " RESET
                   "\n");
}
void print3() {
  printf(BG_WHITE " " BG_GRAY " " BG_WHITE "         " BG_GRAY " " BG_WHITE
                  " " BG_GRAY " " BG_WHITE "         " BG_GRAY " " BG_WHITE
                  " " RESET "\n");
}
void print4() {
  printf(BG_WHITE "  " BG_GRAY " " BG_WHITE "        " BG_GRAY " " BG_WHITE
                  " " BG_GRAY " " BG_WHITE "        " BG_GRAY " " BG_WHITE
                  "  " RESET "\n");
}
void print5() {
  printf(BG_WHITE "   " BG_GRAY "  " BG_WHITE "               " BG_GRAY
                  "  " BG_WHITE "   " RESET "\n");
}
void print6() {
  printf(BG_WHITE "     " BG_ORANGE "   " BG_WHITE "         " BG_ORANGE
                  "   " BG_WHITE "     " RESET "\n");
}
void print7(char *color) {
  printf(BG_WHITE "        %s         " BG_WHITE "        " RESET "\n", color);
}
void print8() {
  printf(BG_WHITE "     " BG_GRAY "    " BG_WHITE "       " BG_GRAY
                  "    " BG_WHITE "     " RESET "\n");
}
void print9() {
  printf(BG_WHITE "   " BG_GRAY "  " BG_WHITE "  " BG_GRAY "   " BG_WHITE
                  "     " BG_GRAY "   " BG_WHITE "  " BG_GRAY "  " BG_WHITE
                  "   " RESET "\n");
}
void print10() {
  printf(BG_WHITE "  " BG_GRAY " " BG_WHITE "     " BG_GRAY "   " BG_WHITE
                  "   " BG_GRAY "   " BG_WHITE "     " BG_GRAY " " BG_WHITE
                  "  " RESET "\n");
}
void print11() {
  printf(BG_WHITE " " BG_GRAY " " BG_WHITE "       " BG_GRAY "   " BG_WHITE
                  " " BG_GRAY "   " BG_WHITE "       " BG_GRAY " " BG_WHITE
                  " " RESET "\n");
}
void print12() {
  printf(BG_WHITE " " BG_GRAY " " BG_WHITE "        " BG_GRAY "  " BG_WHITE
                  " " BG_GRAY "  " BG_WHITE "        " BG_GRAY " " BG_WHITE
                  " " RESET "\n");
}

void printCartaVirada(int x, int y) {
  mover_cursor_xy(x, y++);
  print1();
  mover_cursor_xy(x, y++);
  print2();
  mover_cursor_xy(x, y++);
  print0();
  mover_cursor_xy(x, y++);
  print7(BG_ORANGE);
  mover_cursor_xy(x, y++);
  print6();
  mover_cursor_xy(x, y++);
  print5();
  mover_cursor_xy(x, y++);
  print4();
  mover_cursor_xy(x, y++);
  print3();
  mover_cursor_xy(x, y++);
  print3();
  mover_cursor_xy(x, y++);
  print12();
  mover_cursor_xy(x, y++);
  print11();
  mover_cursor_xy(x, y++);
  print10();
  mover_cursor_xy(x, y++);
  print9();
  mover_cursor_xy(x, y++);
  print8();
  mover_cursor_xy(x, y++);
  print7(BG_GRAY);
  mover_cursor_xy(x, y++);
  print0();
  mover_cursor_xy(x, y++);
  print2();
  mover_cursor_xy(x, y++);
  print1();
}