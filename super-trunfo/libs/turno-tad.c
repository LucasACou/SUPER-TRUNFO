#include "../includes/turno-tad.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include "../includes/player-tad.h"
#include "../includes/terminal.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// função para a criar nós de turno que têm como dado um player
No_Turno *criarNoTurno(Player *dado) {
  No_Turno *novo_no = malloc(sizeof(No_Turno));
  if (novo_no != NULL) {
    novo_no->dado = dado;
    novo_no->prox = NULL;
  }
  return novo_no;
}

// função que cria a lista circular encadeada que quando chega no final volta
// pro inicio e fica assim ate acabar o jogo

Lista_Turno *criarListaTurno() {
  Lista_Turno *lista_turno = malloc(sizeof(Lista_Turno));
  if (lista_turno != NULL) {
    lista_turno->inicio = NULL;
    lista_turno->num_jogadores = 0;
  }
  return lista_turno;
}

// funcão para inserir cada nó na lista de forma que vire uma lista circular
// encadeada
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

// função utilizada para comparar dois numeros para saber que é o maior
int compAtributo(int x, int y) {
  if (x > y) {
    return x;
  }
  return y;
}

// função utilizada pelos bot para escolher o atributo com o maior valor para
// ser jogado automaticamente
char maxAtributosComp(Player *player) {
  int resultado = compAtributo(
      compAtributo(
          compAtributo(
              compAtributo(
                  player->carta_atual
                      ->mobilidade, // uso de recursão para comparar todos os
                                    // atributos das cartas para saber qual
                                    // maior, retornando assim o numero q
                                    // representa o atributo no menu de
                                    // atributos
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

// funcao de loop de turno para o multiplayer
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

    player_atual = turno_atual->dado;

    // inicio do turno todos players compram uma carta

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
      scanf("%c%*c", &atributo);

    } while (atributo != '1' && atributo != '2' && atributo != '3' &&
             atributo != '4' && atributo != '5');

    system("clear");
    mover_cursor_xy(1, 41);
    //nesta parte é printado o nome do atributo q foi escolhido
    if (atributo == '1') {
      printf("O atributo escolhido foi mobilidade\n");
    }
    if (atributo == '2') {
      printf("O atributo escolhido foi vida\n");
    }
    if (atributo == '3') {
      printf("O atributo escolhido foi ataque\n");
    }
    if (atributo == '4') {
      printf("O atributo escolhido foi cura\n");
    }
    if (atributo == '5') {
      printf("O atributo escolhido foi ultimate\n");
    }
    // aqui acontece a comparação do turno
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

    mover_cursor_xy(1, 44);

    for (int i = 0; i < MAX_PLAYERS; i++) {// printa o score de cada player ao final do turno
      printf("score %s: %d\n", vetor_players[i]->nome, vetor_players[i]->score);
    }
    printf("\nAperte enter para continuar o jogo\n");

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
      else if (player2->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player1->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // empate 5 - 5
      else if (player1->score == 5 && player2->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player2->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player1->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // ganha com 5
      else if (player1->score == 5) {
        printf("%s ganhou!\n", player1->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player2->score == 5) {
        printf("%s ganhou!\n", player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player3->score == 5) {
        printf("%s ganhou!\n", player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
    }
  }
}

// funcao loop de turno para o singleplay
void loopTurnoComp(Player *player1, Player *player2, Player *player3,
                   char *nome) {

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

  while (fim_de_jogo == 0) {

    player_atual = turno_atual->dado;

    // inicio do turno todos players compram uma carta

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

      if (player_atual->nome == nome) { // quando é o player real
        menuAtributos();
        scanf("%c%*c", &atributo);
      }
      if (player_atual->nome != nome) { // quando é um bot
        atributo = maxAtributosComp(player_atual);
      }

    } while (atributo != '1' && atributo != '2' && atributo != '3' &&
             atributo != '4' && atributo != '5');

    system("clear");
    mover_cursor_xy(1, 41);
    //nesta parte é printado o nome do atributo q foi escolhido
    if (atributo == '1') {
      printf("O atributo escolhido foi mobilidade\n");
    }
    if (atributo == '2') {
      printf("O atributo escolhido foi vida\n");
    }
    if (atributo == '3') {
      printf("O atributo escolhido foi ataque\n");
    }
    if (atributo == '4') {
      printf("O atributo escolhido foi cura\n");
    }
    if (atributo == '5') {
      printf("O atributo escolhido foi ultimate\n");
    }
    // aqui acontece a comparação do turno
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

    mover_cursor_xy(1, 44);

    for (int i = 0; i < MAX_PLAYERS; i++) { // printa o score de cada player ao final do turno
      printf("score %s: %d\n", vetor_players[i]->nome, vetor_players[i]->score);
    }
    printf("\nAperte enter para continuar o jogo\n");

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
      else if (player2->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player1->score == 4 && player3->score == 4) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // empate 5 - 5
      else if (player1->score == 5 && player2->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player2->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player2->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player1->score == 5 && player3->score == 5) {
        printf("%s e %s empataram!\n", player1->nome, player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      // ganha com 5
      else if (player1->score == 5) {
        printf("%s ganhou!\n", player1->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player2->score == 5) {
        printf("%s ganhou!\n", player2->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
      else if (player3->score == 5) {
        printf("%s ganhou!\n", player3->nome);
        printf("fim de jogo\n");
        fim_de_jogo = 1;
      }
    }
  }
}
