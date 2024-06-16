#include "../includes/deck-tad.h"
#include "../includes/carta-tad.h"
#include <stdio.h>
#include <stdlib.h>

// Função para criar Nós
No_Deck *criarNoDeck(Carta *dado) {
  No_Deck *novo_no = malloc(sizeof(No_Deck));
  if (novo_no != NULL) {
    novo_no->dado = dado;
    novo_no->prox = NULL;
  }
  return novo_no;
}

// Função para criar Decks
Deck *criarDeck() {
  Deck *deck = malloc(sizeof(Deck));
  if (deck != NULL) {
    deck->length = 0;
    deck->topo = NULL;
  }
  return deck;
}

// Função para prencer o Deck usando o Vetor de Cartas embaralhado
void prencherDeck(Deck *deck) {
  if (deck != NULL) {
    Carta **vetorcartas = criarVetorCartas();
    embaralhar(vetorcartas);
    for (int i = 0; i < MAX_CARTAS; i++) {
      No_Deck *novo_no = criarNoDeck(vetorcartas[i]);
      if (novo_no != NULL) {
        novo_no->prox = deck->topo;
        deck->topo = novo_no;
        deck->length++;
      }
    }
  }
}

// Função que dividi o Deck inteiro em 3 menores Decks
void dividirDeck(Deck *deck, Deck *deck1, Deck *deck2, Deck *deck3) {
  if (deck != NULL && deck->length >= 3) {

    int carta_por_deck = deck->length / 3;

    for (int i = 0; i < carta_por_deck; i++) {
      // deck1
      Carta *carta = pegarCartaTopo(deck);
      No_Deck *novo_no = criarNoDeck(carta);
      if (novo_no != NULL) {
        novo_no->prox = deck1->topo;
        deck1->topo = novo_no;
        deck1->length++;
      }
      // deck2
      carta = pegarCartaTopo(deck);
      novo_no = criarNoDeck(carta);
      if (novo_no != NULL) {
        novo_no->prox = deck2->topo;
        deck2->topo = novo_no;
        deck2->length++;
      }
      // deck3
      carta = pegarCartaTopo(deck);
      novo_no = criarNoDeck(carta);
      if (novo_no != NULL) {
        novo_no->prox = deck3->topo;
        deck3->topo = novo_no;
        deck3->length++;
      }
    }
  } else {
    printf("deck vazio ou não é possível dividir!\n");
  }
}

// Função para ver a carta do topo do Deck
Carta *verTopo(Deck *deck) {
  if (deck != NULL && deck->topo != NULL) {
    return deck->topo->dado;
  } else {
    printf("deck vazio!\n");
    return NULL;
  }
}

// Função para pegar a carta do topo do Deck
Carta *pegarCartaTopo(Deck *deck) {
  if (deck->length != 0) {
    Carta *dado = deck->topo->dado;
    No_Deck *aux = deck->topo;
    deck->topo = aux->prox;
    free(aux);
    deck->length--;
    return dado;
  } else {
    printf("deck vazio!\n");
    return NULL;
  }
}
