#include "../includes/menu.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include "../includes/player-tad.h"
#include "../includes/turno-tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printLogo() {
  printf(FG_ORANGE
         "                       #############                       " RESET
         "\n");
  printf(FG_ORANGE
         "                 #########################                 " RESET
         "\n");
  printf(FG_ORANGE
         "             #################################             " RESET
         "\n");
  printf(FG_GRAY "         ," FG_ORANGE
                 " ##################################### " FG_GRAY
                 ",         " RESET "\n");
  printf(FG_GRAY "       ,,,," FG_ORANGE
                 "   ########               ########   " FG_GRAY
                 ",,,,       " RESET "\n");
  printf(FG_GRAY "     ,,,,,,,," FG_ORANGE
                 "   ###                     ###   " FG_GRAY
                 ",,,,,,,,     " RESET "\n");
  printf(FG_GRAY
         "   ,,,,,,,,,,,                               ,,,,,,,,,,,   " RESET
         "\n");
  printf(FG_GRAY
         "  ,,,,,,,,,,                                   ,,,,,,,,,,  " RESET
         "\n");
  printf(FG_GRAY
         " ,,,,,,,,,,                ,   ,                ,,,,,,,,,, " RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,,,                ,,   ,,                ,,,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,,               ,,,,   ,,,,               ,,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,               ,,,,,   ,,,,,               ,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,              ,,,,,,   ,,,,,,              ,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,           ,,,,,,,,,   ,,,,,,,,,           ,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,,       ,,,,,,,,,,,,   ,,,,,,,,,,,,       ,,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         ",,,,,,,,,,    ,,,,,,,,,,,,       ,,,,,,,,,,,,    ,,,,,,,,,," RESET
         "\n");
  printf(FG_GRAY
         " ,,,,,,,,,,,,,,,,,,,,,,,           ,,,,,,,,,,,,,,,,,,,,,,, " RESET
         "\n");
  printf(FG_GRAY
         "  ,,,,,,,,,,,,,,,,,,,                 ,,,,,,,,,,,,,,,,,,,  " RESET
         "\n");
  printf(FG_GRAY
         "   ,,,,,,,,,,,,,,,,                     ,,,,,,,,,,,,,,,,   " RESET
         "\n");
  printf(FG_GRAY
         "     ,,,,,,,,,,,,                         ,,,,,,,,,,,,     " RESET
         "\n");
  printf(FG_GRAY
         "       ,,,,,,,,,,,,,,,               ,,,,,,,,,,,,,,,       " RESET
         "\n");
  printf(FG_GRAY
         "          ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,          " RESET
         "\n");
  printf(FG_GRAY
         "             ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,             " RESET
         "\n");
  printf(FG_GRAY
         "                 ,,,,,,,,,,,,,,,,,,,,,,,,,                 " RESET
         "\n");
  printf(FG_GRAY
         "                       ,,,,,,,,,,,,,                       " RESET
         "\n");
  printf("\n");
}

void menu() {

  char numero;

  do {

    system("clear");

    printLogo();

    printf("[1] - Jogar\n");
    printf("[2] - Regras\n");
    printf("[3] - Creditos\n");
    printf("[4] - Sair\n\n");
    printf("\n");
    printf("Escolha alguma opção:\n");

    scanf("%s", &numero);

    switch (numero) {

    case '1':
      break;
    case '2':
      system("clear");
      printf("Quantidade de jogadores são 3\n");
      printf("Jogo por turnos e acada turno recebe uma carta diferente\n");
      printf("Em cada turno o player que começa escolhe o tipo que sera "
             "disputado\n");
      printf("Pegar os emotes\n");
      printf("Apos a pessoa que inicia o turno escolher o tipo que sera "
             "disputado\n");
      printf("O jogador que fizer x pontos ganha\n");
      printf("\nAperte enter pra voltar pro menu principal\n");
      getchar();
      getchar();
      break;
    case '3':
      system("clear");
      printf("└-----------------------┘\n");
      printf("|   Lucas - Matricula   |\n");
      printf("|   Lucas - Matricula   |\n");
      printf("|   Eu    - 2222130034  |\n");
      printf("└-----------------------┘\n");
      printf("\nAperte enter pra voltar pro menu principal\n");
      getchar();
      getchar();
      break;
    case '4':
      exit(0);
    default:
      printf("Opção invalida\n");
    }

  } while (numero != '1');
}

void jogar() {

  system("clear");

  char opcoes_dificuldade;

  printf("[1] - Singleplayer\n");
  printf("[2] - Multiplayer\n");
  printf("\nEscolha alguma opção:\n");
  scanf("%s", &opcoes_dificuldade);

  char nome_player1[50];
  char nome_player2[50];
  char nome_player3[50];

  Deck *baralho = criarDeck();
  prencherDeck(baralho);

  Deck *baralho_pessoal1 = criarDeck();
  Deck *baralho_pessoal2 = criarDeck();
  Deck *baralho_pessoal3 = criarDeck();
  dividirDeck(baralho, baralho_pessoal1, baralho_pessoal2, baralho_pessoal3);

  switch (opcoes_dificuldade) {

  case '1':
    system("clear");

    printf("\nEntre com nome do player 1\n");
    scanf("%s%*c", nome_player1);
    strcpy(nome_player2, "Comp1");
    strcpy(nome_player3, "Comp2");

    Player *player1 = criarPlayer(nome_player1, baralho_pessoal1);
    Player *player2 = criarPlayer(nome_player2, baralho_pessoal2);
    Player *player3 = criarPlayer(nome_player3, baralho_pessoal3);
         
       loopTurnoComp(player1, player2, player3, nome_player1);
    break;

  case '2':
    system("clear");

    printf("Entre com nome do player 1:\n");
    scanf("%s%*c", nome_player1);
    printf("Entre com nome do player 2:\n");
    scanf("%s%*c", nome_player2);
    printf("Entre com nome do player 3:\n");
    scanf("%s%*c", nome_player3);

    Player *player1_m = criarPlayer(nome_player1, baralho_pessoal1);
    Player *player2_m = criarPlayer(nome_player2, baralho_pessoal2);
    Player *player3_m = criarPlayer(nome_player3, baralho_pessoal3);

    loopTurno(player1_m, player2_m, player3_m);
    break;

  default:
    printf("erro");
  }
}
