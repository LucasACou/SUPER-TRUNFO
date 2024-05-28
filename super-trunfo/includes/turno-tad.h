#ifndef TURNO_H
#define TURNO_H

#include "carta-tad.h"
#include "deck-tad.h"
#include "player-tad.h"

typedef struct no_turno No_Turno;
struct no_turno {
  Player *dado;
  No_Turno *prox;
};

typedef struct lista_turno {
  No_Turno *inicio;
  unsigned int num_jogadores;
} Lista_Turno;

No_Turno *criarNoTurno(Player *dado);
Lista_Turno *criarListaTurno();
void inserirInicio(Lista_Turno *lista, Player **dado);
void loopTurno(Player *player1, Player *player2, Player *player3);


#endif // TURNO_H