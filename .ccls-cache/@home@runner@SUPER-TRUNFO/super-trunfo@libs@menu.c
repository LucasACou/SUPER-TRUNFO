#include "../includes/menu.h"
#include "../includes/carta-tad.h"
#include "../includes/deck-tad.h"
#include "../includes/player-tad.h"
#include "../includes/turno-tad.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// função que imprime a logo do jogo
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
                 "   ###        SUPER        ###   " FG_GRAY
                 ",,,,,,,,     " RESET "\n");
  printf(FG_GRAY
         "   ,,,,,,,,,,,             TRUNFO            ,,,,,,,,,,,   " RESET
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

// função de menu do jogo

void menu() {

  char numero;

  do {

    do {
      system("clear");

      printLogo();

      printf("[1] - Jogar\n");    // ir para o jogo
      printf("[2] - Regras\n");   // regras do jogo
      printf("[3] - Creditos\n"); // creditos
      printf("[4] - Sair\n\n");   // sair do jogo
      printf("\n");
      printf("Escolha alguma opção:\n");
      scanf("%s", &numero);

    } while (numero != '1' && numero != '2' && numero != '3' && numero != '4');

    switch (numero) {

    case '1':
      break;
    case '2':

      system("clear");
      printf("\n1 - Modo de Jogo\n");
      printf(">> Singleplay: 1 jogador\n");
      printf(">> Multiplay: 3 jogadores\n");
      printf("\n2 - Como jogar\n");
      printf(">> Todo inicio de turno todos os players pegam uma carta, "
             "distribuida de\nmaneira aleatoria, o player que começar deverá "
             "escolher o atributo que desejar.\n");
      printf(">> Após a escolha do player, quem possuir o maior valor deste "
             "atributo\nganhará a rodada e ganhará um ponto no score.\n");
      printf(">> Depois de terminar a rodada, será a vez do proximo jogador a "
             "escolher\no atribuuto desejado.\n");
      printf("\n3 - Condição de vitoria\n");
      printf(">> Quem alcançar 6 pontos primeiro vence o jogo.\n");
      printf(">> Entretanto ao final do jogo podem ocorrer empates.\n");
      printf("\nAperte enter pra voltar pro menu principal\n");
      getchar();
      getchar();
      break;
    case '3':

      system("clear");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_ORANGE " LUCAS ASSUNÇÂO        " BG_GRAY
                     " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_WHITE " MATRICULA  " FG_ORANGE
                     "2222130011 " BG_GRAY " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n\n");

      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_ORANGE " LUCAS CALABRESI       " BG_GRAY
                     " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_WHITE " MATRICULA  " FG_ORANGE
                     "2222130037 " BG_GRAY " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n\n");

      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_ORANGE " VICTOR E.             " BG_GRAY
                     " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY " " BG_BLACK FG_WHITE " MATRICULA  " FG_ORANGE
                     "2222130034 " BG_GRAY " " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n");
      printf(BG_GRAY "                         " RESET "\n\n");

      printf("\nAperte enter pra voltar pro menu principal\n");
      getchar();
      getchar();
      break;
    case '4':
      system("clear");
      exit(0);
    default:
      printf("Opção invalida\n");
    }

  } while (numero != '1');
}

// função que roda o jogo completo
void jogar() {
  char opcoes_dificuldade;

  do {
    system("clear");
    printf("[1] - Singleplayer\n");
    printf("[2] - Multiplayer\n");
    printf("\nEscolha alguma opção:\n");
    scanf("%s", &opcoes_dificuldade);
  } while (opcoes_dificuldade != '1' && opcoes_dificuldade != '2');

  char nome_player1[50];
  char nome_player2[50];
  char nome_player3[50];

  // criação do deck e prenchimento aleatorio dele
  Deck *baralho = criarDeck();
  prencherDeck(baralho);

  // divisão do deck original em 3 outros decks
  Deck *baralho_pessoal1 = criarDeck();
  Deck *baralho_pessoal2 = criarDeck();
  Deck *baralho_pessoal3 = criarDeck();
  dividirDeck(baralho, baralho_pessoal1, baralho_pessoal2, baralho_pessoal3);

  switch (opcoes_dificuldade) {

  case '1': // modo de jogo singleplay
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

  case '2': // modo de jogo multiplay
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
