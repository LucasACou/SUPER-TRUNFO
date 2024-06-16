#include "../includes/turno-tad.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include "../includes/player-tad.h"
#include "../includes/terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

No_Turno *criarNoTurno(Player *dado) {
  No_Turno *novo_no = malloc(sizeof(No_Turno));
  if (novo_no != NULL) {
    novo_no->dado = dado;
    novo_no->prox = NULL;
  }
  return novo_no;
}

Lista_Turno *criarListaTurno() {
  Lista_Turno *lista_turno = malloc(sizeof(Lista_Turno));
  if (lista_turno != NULL) {
    lista_turno->inicio = NULL;
    lista_turno->num_jogadores = 0;
  }
  return lista_turno;
}

void inserirInicio(Lista_Turno *lista, Player **dado) {
  if (lista != NULL) {
    for (int i = 0; i < MAX_PLAYERS; i++) {
      No_Turno *novo_no = criarNoTurno(dado[i]);
      if (novo_no == NULL)
        return;
      if (!lista->inicio) {
        lista->inicio = novo_no;
        novo_no->prox = novo_no;
        lista->num_jogadores = 1;
      } else {
        novo_no->prox = lista->inicio;
        No_Turno *ultimo = lista->inicio;
        while (ultimo->prox != lista->inicio) {
          ultimo = ultimo->prox;
        }
        ultimo->prox = novo_no;
        lista->inicio = novo_no;
      }
      lista->num_jogadores++;
    }
  }
}

int compAtributo(int x, int y) {
  if (x > y) {
    return x;
  }
  return y;
}
char maxAtributosComp(Player *player) {
  int resultado = compAtributo(
      compAtributo(compAtributo(compAtributo(player->carta_atual->mobilidade,
                                             player->carta_atual->vida),
                                player->carta_atual->ataque),
                   player->carta_atual->cura),
      player->carta_atual->ultimate);

  if (resultado == player->carta_atual->mobilidade)
    return '1';
  if (resultado == player->carta_atual->vida)
    return '2';
  if (resultado == player->carta_atual->ataque)
    return '3';
  if (resultado == player->carta_atual->cura)
    return '4';

  return '5';
}

void loopTurno(Player *player1, Player *player2, Player *player3) {

  // antes de tudo, criar lista e inserir os players na lista

  Player *vetor_players[] = {player1, player2, player3};
  srand(time(NULL));
  for (int i = 0; i < MAX_PLAYERS; i++) {
    int j = rand() % MAX_PLAYERS;
    Player *temp = vetor_players[i];
    vetor_players[i] = vetor_players[j];
    vetor_players[j] = temp;
  }

  Lista_Turno *lista_turno = criarListaTurno();
  inserirInicio(lista_turno, vetor_players);

  No_Turno *turno_atual = lista_turno->inicio;
  Player *player_atual;

  int fim_de_jogo = 0;
  int x = 15;

  // começo dos turnos

  while (fim_de_jogo == 0) {

    // inicio do turno todos players compram umna carta

    player_atual = turno_atual->dado;

    playerCompra(player1);
    playerCompra(player2);
    playerCompra(player3);

    char atributo;

    do {
      system("clear");

      x = 15;
      // printa as cartas viradas dos players não atuais
      for (int i = 0; i < MAX_PLAYERS; i++) {
        Player *player_nao_atual = vetor_players[i];
        if (player_nao_atual != player_atual) {
          printCartaVirada(x, 1);
          mover_cursor_xy(x, 19);
          printf("%s\n", player_nao_atual->nome);
          x += 50;
        }
      }

      // printar carta do players atual
      printCarta(player_atual->carta_atual, 40, 22);
      mover_cursor_xy(40, 40);
      printf("%s\n", player_atual->nome);

      menuAtributos();
      scanf("%c", &atributo);

    } while (atributo != '1' && atributo != '2' && atributo != '3' &&
             atributo != '4' && atributo != '5');

    system("clear");
    mover_cursor_xy(1, 41);
    compararAtributos(player1, player2, player3, atributo);

    x = 15;
    for (int i = 0; i < MAX_PLAYERS; i++) {
      Player *player_nao_atual = vetor_players[i];
      if (player_nao_atual != player_atual) {
        printCarta(vetor_players[i]->carta_atual, x, 1);
        mover_cursor_xy(x, 19);
        printf("%s\n", player_nao_atual->nome);
        x += 50;
      }
    }

    printCarta(player_atual->carta_atual, 40, 22);
    mover_cursor_xy(40, 40);
    printf("%s\n", player_atual->nome);

    mover_cursor_xy(1, 43);

    for (int i = 0; i < MAX_PLAYERS; i++) {
      printf("score %s: %d\n", vetor_players[i]->nome, vetor_players[i]->score);
    }

    getchar();
    getchar();

    turno_atual = turno_atual->prox;

    if (player1->score == 6) {
      printf("%s ganhou!\n", player1->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }
    if (player2->score == 6) {
      printf("%s ganhou!\n", player2->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }
    if (player3->score == 6) {
      printf("%s ganhou!\n", player3->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }

    if (player1->deck_pessoal->length == 0 ||
        player2->deck_pessoal->length == 0 ||
        player3->deck_pessoal->length == 0) {
      // empate 4 - 4
      if (player1->score == 4 && player2->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player1->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // empate 5 - 5
      if (player1->score == 5 && player2->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player1->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // ganha com 5
      if (player1->score == 5) {
        printf("%s ganhou!\n", player1->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 5) {
        printf("%s ganhou!\n", player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player3->score == 5) {
        printf("%s ganhou!\n", player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
    }
  }
}

void loopTurnoComp(Player *player1, Player *player2, Player *player3,
                   char *nome) {

  Player *vetor_players[] = {player1, player2, player3};
  srand(time(NULL));
  for (int i = 0; i < MAX_PLAYERS; i++) {
    int j = rand() % MAX_PLAYERS;
    Player *temp = vetor_players[i];
    vetor_players[i] = vetor_players[j];
    vetor_players[j] = temp;
  }

  Lista_Turno *lista_turno = criarListaTurno();
  inserirInicio(lista_turno, vetor_players);

  No_Turno *turno_atual = lista_turno->inicio;
  Player *player_atual;

  int fim_de_jogo = 0;
  int x = 15;
  
  while (fim_de_jogo == 0) {

    player_atual = turno_atual->dado;

    playerCompra(player1);
    playerCompra(player2);
    playerCompra(player3);

    char atributo;

    do {
      system("clear");

      x = 15;
      // printa as cartas viradas dos players não atuais
      for (int i = 0; i < MAX_PLAYERS; i++) {
        Player *player_nao_atual = vetor_players[i];
        if (player_nao_atual != player_atual) {
          printCartaVirada(x, 1);
          mover_cursor_xy(x, 19);
          printf("%s\n", player_nao_atual->nome);
          x += 50;
        }
      }

      // printar carta do players atual
      printCarta(player_atual->carta_atual, 40, 22);
      mover_cursor_xy(40, 40);
      printf("%s\n", player_atual->nome);

      if (player_atual->nome == nome) {
        menuAtributos();
        scanf("%c", &atributo);
        getchar();
      }
      if(player_atual->nome != nome) {
        atributo = maxAtributosComp(player_atual);
      }

    } while (atributo != '1' && atributo != '2' && atributo != '3' &&
             atributo != '4' && atributo != '5');

    system("clear");
    mover_cursor_xy(1, 41);
    if(atributo == '1'){
      printf("O atributo escolhido foi mobilidade");
    }
    if(atributo == '2'){
      printf("O atributo escolhido foi vida");
    }
    if(atributo == '3'){
      printf("O atributo escolhido foi ataque");
    }
    if(atributo == '4'){
      printf("O atributo escolhido foi cura");
    }
    if(atributo == '5'){
      printf("O atributo escolhido foi ultimate");
    }
    compararAtributos(player1, player2, player3, atributo);

    x = 15;
    for (int i = 0; i < MAX_PLAYERS; i++) {
      Player *player_nao_atual = vetor_players[i];
      if (player_nao_atual != player_atual) {
        printCarta(vetor_players[i]->carta_atual, x, 1);
        mover_cursor_xy(x, 19);
        printf("%s\n", player_nao_atual->nome);
        x += 50;
      }
    }

    printCarta(player_atual->carta_atual, 40, 22);
    mover_cursor_xy(40, 40);
    printf("%s\n", player_atual->nome);

    mover_cursor_xy(1, 43);

    for (int i = 0; i < MAX_PLAYERS; i++) {
      printf("score %s: %d\n", vetor_players[i]->nome, vetor_players[i]->score);
    }

    getchar();

    turno_atual = turno_atual->prox;

    if (player1->score == 6) {
      printf("%s ganhou!\n", player1->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }
    if (player2->score == 6) {
      printf("%s ganhou!\n", player2->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }
    if (player3->score == 6) {
      printf("%s ganhou!\n", player3->nome);
      printf("fim de jogo\n");
      fim_de_jogo = 1;
    }

    if (player1->deck_pessoal->length == 0 ||
        player2->deck_pessoal->length == 0 ||
        player3->deck_pessoal->length == 0) {
      // empate 4 - 4
      if (player1->score == 4 && player2->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player1->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // empate 5 - 5
      if (player1->score == 5 && player2->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player1->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // ganha com 5
      if (player1->score == 5) {
        printf("%s ganhou!\n", player1->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player2->score == 5) {
        printf("%s ganhou!\n", player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      if (player3->score == 5) {
        printf("%s ganhou!\n", player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
    }
  }
}

