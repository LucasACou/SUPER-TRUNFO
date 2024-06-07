#include "../includes/player-tad.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Player *criarPlayer(char *nome, Deck *deck) {
  Player *novo_player = malloc(sizeof(Player));
  if (novo_player != NULL) {
    novo_player->nome = nome;
    novo_player->carta_atual = NULL;
    novo_player->deck_pessoal = deck;
    novo_player->score = 0;
  }
  return novo_player;
}

Carta *playerCompra(Player *player) {
  player->carta_atual = pegarCartaTopo(player->deck_pessoal);
  return player->carta_atual;
}
void menuAtributos() {
  printf("\nEscolha um atributo:\n\n");
  printf("[1] - mobilidade\n");
  printf("[2] - vida\n");
  printf("[3] - ataque\n");
  printf("[4] - cura\n");
  printf("[5] - ultimate\n");
}

Player *max(Player *player1, Player *player2, char atributo) {
  if (atributo == '1') {
    if (player1->carta_atual->mobilidade > player2->carta_atual->mobilidade) {
      return player1;
    }
    return player2;
  } else if (atributo == '2') {
    if (player1->carta_atual->vida > player2->carta_atual->vida) {
      return player1;
    }
    return player2;
  } else if (atributo == '3') {
    if (player1->carta_atual->ataque > player2->carta_atual->ataque) {
      return player1;
    }
    return player2;
  } else if (atributo == '4') {
    if (player1->carta_atual->cura > player2->carta_atual->cura) {
      return player1;
    }
    return player2;
  } else if (atributo == '5') {
    if (player1->carta_atual->ultimate > player2->carta_atual->ultimate) {
      return player1;
    }
    return player2;
  }
  return NULL;
}

void compararAtributos(Player *player1, Player *player2, Player *player3,
                       char atributo) {
  Player *vencedor = max(max(player1, player2, atributo), player3, atributo);
  vencedor->score++;
  printf("\njogador vencedor do turno atual: %s\n", vencedor->nome);
}
