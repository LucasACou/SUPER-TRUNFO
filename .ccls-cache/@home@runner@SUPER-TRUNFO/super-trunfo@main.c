#include "./includes/carta-tad.h"
#include "./includes/deck-tad.h"
#include "./includes/player-tad.h"
#include "./includes/turno-tad.h"
#include "./includes/terminal.h"
#include "./includes/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main() {

  menu();

  printf("[1] - Singleplay\n");
  printf("[2] - Multiplay\n");
  printf("\nEscolha alguma opção:\n");

  system("clear");

  Deck *baralho = criarDeck();
  prencerDeck(baralho);

  Deck *baralho_pessoal1 = criarDeck();
  Deck *baralho_pessoal2 = criarDeck();
  Deck *baralho_pessoal3 = criarDeck();
  dividirDeck(baralho, baralho_pessoal1, baralho_pessoal2, baralho_pessoal3);

  Player *player1 = criarPlayer("Lucas", baralho_pessoal1);
  Player *player2 = criarPlayer("Cala", baralho_pessoal2);
  Player *player3 = criarPlayer("Vitin", baralho_pessoal3);

  loopTurno(player1,player2,player3);
  

  return 0;
}