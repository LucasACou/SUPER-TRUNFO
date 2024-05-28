#include "../includes/carta-tad.h"
#include "../includes/terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Carta *criarCarta(char *tipo, float mobilidade, int vida, int ataque,
                  float cura, float ultimate) {
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

void printFloatInfoLine(char *atributo, float value, char *color, char *icone) {
  printf(BG_GRAY " " BG_BLACK " %s%s" FG_WHITE " %-11s " FG_ORANGE
                 " %4.1f " BG_GRAY "   " RESET "\n",
         color, icone, atributo, value);
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
  printFloatInfoLine("MOBILIDADE", carta->mobilidade, FG_BLUE, "\u26F8");
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
  printFloatInfoLine("CURA", carta->cura, FG_GREEN, "\u2720");
  mover_cursor_xy(x, y++);
  printVazio();
  mover_cursor_xy(x, y++);
  printFloatInfoLine("ULTIMATE", carta->ultimate, FG_YELLOW, "\u2605");
  mover_cursor_xy(x, y++);
  printVazio();
}

// Criar Vetor de Cartas
Carta **criarVetorCartas() {
  Carta **vetorCartas = malloc(MAX_CARTAS * sizeof(Carta *));
  if (vetorCartas != NULL) {
    //--------------------------------MB   VD   AT  CR   ULT
    vetorCartas[0] = criarCarta("SS", 8.7, 250, 40, 3.6, 10.0);  // Echo
    vetorCartas[1] = criarCarta("A1", 5.7, 200, 45, 3.9, 3.0);   // Widowmaker
    vetorCartas[2] = criarCarta("A2", 4.1, 250, 50, 3.6, 7.2);   // Ashe
    vetorCartas[3] = criarCarta("A3", 1.7, 250, 25, 8.9, 6.2);   // Ana
    vetorCartas[4] = criarCarta("B1", 4.8, 250, 40, 4.8, 8.8);   // Sombra
    vetorCartas[5] = criarCarta("B2", 1.5, 550, 35, 4.6, 7.0);   // Zarya
    vetorCartas[6] = criarCarta("B3", 7.6, 250, 40, 9.2, 7.4);   // Moira
    vetorCartas[7] = criarCarta("C1", 6.4, 300, 50, 5.3, 9.4);   // Reaper
    vetorCartas[8] = criarCarta("C2", 7.8, 250, 35, 7.8, 8.2);   // Lucio
    vetorCartas[9] = criarCarta("C3", 9.0, 250, 45, 3.6, 7.0);   // Genji
    vetorCartas[10] = criarCarta("D1", 5.2, 200, 40, 6.0, 6.8);  // Brigitte
    vetorCartas[11] = criarCarta("D2", 8.0, 500, 40, 3.2, 9.4);  // D.VA
    vetorCartas[12] = criarCarta("D3", 1.5, 600, 35, 3.2, 8.4);  // Sigma
    vetorCartas[13] = criarCarta("E1", 6.2, 525, 40, 5.2, 7.8);  // Mauga
    vetorCartas[14] = criarCarta("E2", 2.2, 300, 35, 6.9, 8.8);  // Mei
    vetorCartas[15] = criarCarta("E3", 7.4, 250, 25, 10.0, 5.9); // Mercy
    vetorCartas[16] = criarCarta("F1", 6.7, 650, 40, 3.2, 7.3);  // Reinhardt
    vetorCartas[17] = criarCarta("F2", 8.3, 175, 35, 4.8, 8.1);  // Tracer
    vetorCartas[18] = criarCarta("F3", 5.0, 525, 40, 5.5, 6.7);  // RainhaJunker
    vetorCartas[19] = criarCarta("G1", 7.1, 250, 30, 8.6, 5.8);  // Kiriko
    vetorCartas[20] = criarCarta("G2", 3.8, 275, 45, 3.2, 8.0);  // Cassidy
    vetorCartas[21] = criarCarta("G3", 9.1, 525, 40, 3.2, 6.2);  // Doomfist
    vetorCartas[22] = criarCarta("H1", 6.2, 250, 50, 3.2, 8.7);  // Hanzo
    vetorCartas[23] = criarCarta("H2", 2.0, 175, 45, 4.4, 8.0);  // Zenyatta
    vetorCartas[24] = criarCarta("H3", 5.8, 250, 50, 3.2, 7.4);  // Junkrat
    vetorCartas[25] = criarCarta("I1", 5.1, 225, 30, 7.5, 7.9);  // Lifeweaver
    vetorCartas[26] = criarCarta("I2", 4.4, 250, 50, 4.9, 6.9);  // Soldado 76
    vetorCartas[27] = criarCarta("I3", 4.0, 250, 35, 7.7, 7.7);  // Illari
    vetorCartas[28] = criarCarta("J1", 1.5, 250, 50, 3.2, 5.1);  // Bastion
    vetorCartas[29] = criarCarta("J2", 1.5, 425, 40, 3.2, 8.4);  // Ramatra
    vetorCartas[30] = criarCarta("J3", 4.9, 250, 45, 3.2, 4.3);  // Sojourn
    vetorCartas[31] = criarCarta("K1", 3.3, 250, 45, 3.2, 6.2);  // Symmetra
    vetorCartas[32] = criarCarta("K2", 4.9, 375, 40, 3.2, 5.8);  // Winston
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

void print0() {
  printf(BG_WHITE "                         " RESET "\n");
}
void print1(){
  printf(BG_ORANGE "  " BG_GRAY "                     " BG_ORANGE "  " RESET "\n");
}
void print2() {
  printf(BG_ORANGE " " BG_WHITE "                       " BG_ORANGE " " RESET "\n");
}
void print3() {
  printf(BG_WHITE " "BG_GRAY" "BG_WHITE"         "BG_GRAY" "BG_WHITE" "BG_GRAY" "BG_WHITE"         "BG_GRAY" "BG_WHITE" " RESET "\n");
}
void print4() {
  printf(BG_WHITE "  "BG_GRAY" "BG_WHITE"        "BG_GRAY" "BG_WHITE" "BG_GRAY" "BG_WHITE"        "BG_GRAY" "BG_WHITE"  " RESET "\n");
}
void print5() {
  printf(BG_WHITE "   "BG_GRAY"  "BG_WHITE"               "BG_GRAY"  "BG_WHITE"   " RESET "\n");
}
void print6() {
  printf(BG_WHITE "     "BG_ORANGE"   "BG_WHITE"         "BG_ORANGE"   "BG_WHITE"     " RESET "\n");
}
void print7(char *color) {
  printf(BG_WHITE "        %s         "BG_WHITE"        " RESET "\n",color);
}
void print8() { 
  printf(BG_WHITE "     "BG_GRAY"    "BG_WHITE"       "BG_GRAY"    "BG_WHITE"     " RESET "\n");
}
void print9() {
  printf(BG_WHITE "   "BG_GRAY"  "BG_WHITE"  "BG_GRAY"   "BG_WHITE"     "BG_GRAY"   "BG_WHITE"  "BG_GRAY"  "BG_WHITE"   "RESET"\n");
}
void print10() {
  printf(BG_WHITE "  "BG_GRAY" "BG_WHITE"     "BG_GRAY"   "BG_WHITE"   "BG_GRAY"   "BG_WHITE"     "BG_GRAY" "BG_WHITE"  " RESET "\n");
}
void print11() {
  printf(BG_WHITE " "BG_GRAY" "BG_WHITE"       "BG_GRAY"   "BG_WHITE" "BG_GRAY"   "BG_WHITE"       "BG_GRAY" "BG_WHITE" " RESET "\n");
}
void print12() {
  printf(BG_WHITE " "BG_GRAY" "BG_WHITE"        "BG_GRAY"  "BG_WHITE" "BG_GRAY"  "BG_WHITE"        "BG_GRAY" "BG_WHITE" " RESET "\n");
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