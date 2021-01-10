/*Incluindo Bibiliotecas*/
#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
/*Fim Bloco de Inclusão*/

/*Constantes para construir o Jogo*/
const int LARGURA = 1400;
const int ALTURA = 800;
const int FPS = 30;
/*Fim do bloco de constantes*/

/*Variáveis Globais*/
int gameState = 1, numeroFase = 1, numeroExecucao = 0;
int contador = 0, fadeStart = 0, fadeStart2 = 2;
int selecaoMenu = 1;
bool redraw;
bool teclas[7] = {0, 0, 0, 0, 0, 0, 0}, bufferTeclas[7] = {0, 0, 0, 0, 0, 0, 0};
/*Fim do Bloco de Variáveis Globais*/

/*Inicializando Imagens*/
ALLEGRO_BITMAP *background = NULL;
ALLEGRO_BITMAP *fundoMenu = NULL;
/*Imagens Inicializadas*/

/*Incluindo Arquivos com objetos e funções*/
#include "objetos.h"
#include "funcoes.h"
#include "fases.h"
/*Fim do Bloco de Inclusão*/

int main () {
	/*Inicializa Allegro*/
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
    srand (time(NULL));
	if(!al_init())
		return -1;

    display = al_create_display(LARGURA, ALTURA);
    if(!display)
      return -1;

  al_init_primitives_addon();
  al_install_keyboard();
  al_init_image_addon();

  event_queue = al_create_event_queue();
  timer = al_create_timer(1.0 / FPS);

  al_register_event_source(event_queue, al_get_keyboard_event_source());
  al_register_event_source(event_queue, al_get_timer_event_source(timer));
  al_register_event_source(event_queue, al_get_display_event_source(display));

  al_start_timer(timer);
	/*Allegro Incializado*/

    /*Inicializando Fontes*/
  al_init_font_addon();
  al_init_ttf_addon();

  ALLEGRO_FONT *pixeled70 = al_load_font("fonts/pixeled.ttf", 70, 0);
  ALLEGRO_FONT *outline48 = al_load_font("fonts/outline.ttf", 48, 0);
    /*Fontes inicializadas*/

	/*Rotina do Jogo*/
  while (gameState) {
        /*Permite Captura do teclado*/
    ALLEGRO_EVENT ev;
    al_wait_for_event(event_queue, &ev);
    checaTeclas(&teclas[0], ev);
		/*Fim do bloco de Captura do teclado*/

        /*Bloco definir se redesenha ou não*/
    if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(event_queue)) {
        redraw = true;
            /*Se vai redesenhar já imprime o fundo*/
        if (background != NULL) {
            al_draw_bitmap (background, 0, 0, 0);
        }
    } else {
        redraw = false;
    }
        /*Fim do bloco para decisão de redesenho*/

        /*Bloco de Game State*/
    switch (gameState) {
       case 1:
            if (!numeroExecucao) {
                background = al_load_bitmap ("sprites/cenarios/telaInicial.png");
                numeroExecucao++;
            } else {
                if (redraw && contador%40 < 30)
                    al_draw_text (outline48, al_map_rgb(25, 45, 25), LARGURA/2, ALTURA-50, ALLEGRO_ALIGN_CENTER, "PRESSIONE ENTER PARA COMECAR!");
                if (teclas[6])
                    gameState = 0;
                if (teclas[4]) {
                    initPlayer ();
                    fadeStart2 = contador + 1;
                    gameState = 2;
                    numeroExecucao = 0;
                }
            }
       break;
       case 2:
       fase (&numeroFase, pixeled70);
       if (redraw)
           indicadorStats (outline48);
       if (jogador.saude <= 0 || jogador.energia <= 0 || jogador.dinheiro <= 0 || jogador.social <= 0 || jogador.dedicacao <= 0) {
           fadeStart = contador;
           gameState = 3;
           numeroFase = 1;
           numeroExecucao = 0;
       }
    break;
    case 3:
        if (endBg (0.5)) {
            if (initBg(99)) {
                if (redraw && contador%40 < 30) {
                    al_draw_text (outline48, al_map_rgb(25, 45, 25), LARGURA/2, 10, ALLEGRO_ALIGN_CENTER, "PRESSIONE ESPACO PARA VOLTAR AO INICIO");
                    al_draw_text (outline48, al_map_rgb(25, 45, 25), LARGURA/2, ALTURA-50, ALLEGRO_ALIGN_CENTER, "OU ESC PARA FECHAR");
                }
                if (teclas[6])
                    gameState = 0;
                if (teclas[5])
                    if (endBg(0.5))
                        gameState = 1;

            }
        }
    break;
    case 4:
        if (endBg (0.5)) {
            if (initBg(98)) {
                if (redraw && contador%40 < 30) {
                    al_draw_text (outline48, al_map_rgb(25, 45, 25), LARGURA/2, ALTURA-50, ALLEGRO_ALIGN_CENTER, "ESC PARA FECHAR");
                }
                if (teclas[6])
                    gameState = 0;

            }
        }
    break;
    default:
    gameState = 0;
    break;
}
        /*Fim bloco de Game State*/

        /*Bloco para dar o flip e zerar a tela*/
if (redraw) {
    al_flip_display();
    al_clear_to_color(al_map_rgb(0,0,0));
    contador++;
}
        /*Fim do de redesenho*/
}
	/*Fim Jogo*/

	/*Destrói Allegro*/
al_destroy_bitmap(opcao1.sprite);
al_destroy_bitmap(opcao2.sprite);
al_destroy_bitmap(opcao3.sprite);

al_destroy_font(pixeled70);
al_destroy_font(outline48);

al_destroy_bitmap(background);
al_destroy_bitmap(fundoMenu);

al_destroy_event_queue(event_queue);
al_destroy_timer(timer);
al_destroy_display(display);
	/*Fim*/

return 0;
}
