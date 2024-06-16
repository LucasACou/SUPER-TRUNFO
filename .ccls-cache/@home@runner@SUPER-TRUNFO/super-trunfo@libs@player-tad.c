#include "../includes/player-tad.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// função usada para criação dos players usando a estrutura Player
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
// função que permite do player comprar uma carta de seu baralho pessoal
Carta *playerCompra(Player *player) {
  player->carta_atual = pegarCartaTopo(player->deck_pessoal);
  return player->carta_atual;
}
// função de menu que o player usa pra escolher o atributo
void menuAtributos() {
  printf("\n[1] - mobilidade\n");
  printf("[2] - vida\n");
  printf("[3] - ataque\n");
  printf("[4] - cura\n");
  printf("[5] - ultimate\n");
  printf("\nEscolha um atributo:\n");
}

// função que compara os atributos de dois players para saber quem tem o maior
// atributo
Player *max(Player *player1, Player *player2, char atributo) {
  if (atributo == '1') { // MOBILIDADE
    if (player1->carta_atual->mobilidade >
        player2->carta_atual->mobilidade) { // se mobilidade1 > mobilidade2
      return player1;
    } else if (player1->carta_atual->mobilidade ==
               player2->carta_atual
                   ->mobilidade) { // se mobilidade1 == mobilidade2

      Player *vetor_players[] = {player1, player2};
      srand(time(0));
      int resultado = rand() % 2;
      return vetor_players[resultado]; // retorna um dos dois players
                                       // aleatoriamente
    }
    return player2;
  } else if (atributo == '2') { // VIDA
    if (player1->carta_atual->vida >
        player2->carta_atual->vida) { // se vida1 > vida2
      return player1;
    } else if (player1->carta_atual->vida ==
               player2->carta_atual->vida) { // se vida1 == vida2

      Player *vetor_players[] = {player1, player2};
      srand(time(0));
      int resultado = rand() % 2;
      return vetor_players[resultado]; // retorna um dos dois players
                                       // aleatoriamente
    }
    return player2;
  } else if (atributo == '3') { // ATAQUE
    if (player1->carta_atual->ataque >
        player2->carta_atual->ataque) { // se ataque1 > ataque2
      return player1;
    } else if (player1->carta_atual->ataque ==
               player2->carta_atual->ataque) { // se ataque1 == ataque2

      Player *vetor_players[] = {player1, player2};
      srand(time(0));
      int resultado = rand() % 2;
      return vetor_players[resultado]; // retorna um dos dois players
                                       // aleatoriamente
    }
    return player2;
  } else if (atributo == '4') { // CURA
    if (player1->carta_atual->cura >
        player2->carta_atual->cura) { // se cura1 > cura2
      return player1;
    } else if (player1->carta_atual->cura ==
               player2->carta_atual->cura) { // se ataque1 == ataque2

      Player *vetor_players[] = {player1, player2};
      srand(time(0));
      int resultado = rand() % 2;
      return vetor_players[resultado]; // retorna um dos dois players
                                       // aleatoriamente
    }
    return player2;
  } else if (atributo == '5') { // ULTIMATE
    if (player1->carta_atual->ultimate >
        player2->carta_atual->ultimate) { // se ultimate1 > ultimate2
      return player1;
    } else if (player1->carta_atual->ultimate ==
               player2->carta_atual->ultimate) { // se ataque1 == ataque2

      Player *vetor_players[] = {player1, player2};
      srand(time(0));
      int resultado = rand() % 2;
      return vetor_players[resultado]; // retorna um dos dois players
                                       // aleatoriamente
    }
    return player2;
  }
  return NULL;
}

// função que mostra o vencedor da rodada
void compararAtributos(Player *player1, Player *player2, Player *player3,
                       char atributo) {
  Player *vencedor =
      max(max(player1, player2, atributo), player3,
          atributo); // uso de recursão para comparar os atributos dos 3 players
  vencedor->score++;
  printf("\nJogador vencedor do turno atual: %s\n", vencedor->nome);
}
