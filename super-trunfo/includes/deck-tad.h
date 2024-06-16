#ifndef DECK_H
#define DECK_H

#include "carta-tad.h"

typedef struct no_deck No_Deck;
struct no_deck {
  Carta *dado;
  No_Deck *prox;
};

typedef struct deck {
  No_Deck *topo;
  unsigned int length;
} Deck;

No_Deck *criarNoDeck(Carta *carta);
Deck *criarDeck();
void prencherDeck(Deck *deck);

void dividirDeck(Deck *deck, Deck *deck1, Deck *deck2, Deck *deck3);
Carta *verTopo(Deck *deck);
Carta *pegarCartaTopo(Deck *deck);

#endif // DECK_H