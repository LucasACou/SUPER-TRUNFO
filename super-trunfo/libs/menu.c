#include "../includes/menu.h"
#include "../includes/carta-tad.h"
#include <stdio.h>
#include <stdlib.h>

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
    
  }while(numero != '1');
}
