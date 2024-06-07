#ifndef PESSOA_H
#define PESSOA_H

#include "carta-tad.h"
#include "deck-tad.h"

typedef struct player {
  char *nome;
  Carta *carta_atual;
  Deck *deck_pessoal;
  int score;
} Player;

Player *criarPlayer(char *nome, Deck *deck);
Carta *playerCompra(Player *player);
void menuAtributos();
Player *max(Player *player1, Player *player2, char atributo);
void compararAtributos(Player *player1, Player *player2, Player *player3,
                       char atributo);

#endif // PESSOA_H