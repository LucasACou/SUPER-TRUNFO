#ifndef TERMINAL_H
#define TERMINAL_H

#include <termios.h>


void mantem_pressionar_enter_para_leitura();
void ignora_pressionar_enter_para_leitura();

void esconde_texto_digitado_para_leitura();
void exibe_texto_digitado_para_leitura();


void resetar_fonte();
void definir_propriedade_da_fonte(int propriedade);

void exibir_cursor();
void ocultar_cursor();
void mover_cursor_xy(int x, int y);
void limpar_tela();
void limpar_linha();

#endif // TERMINAL_H