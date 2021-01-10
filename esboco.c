#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include "objetos.h"
#include "funcoes.h"
#include "fases.h"

const int LARGURA = 1020;
const int ALTURA = 840;
const int FPS = 60;

int menu = 1, n = 0;
bool teclas[7] = {0, 0, 0, 0, 0, 0, 0};

int main () {
	/*Inicializa Allegro*/
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
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

	/*Rotina do Jogo*/
	while (menu != 0) {
        /*Captura do teclado*/
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		checaTeclas(&teclas[0], ev);
		/*Fim do bloco de Captura do teclado*/

		if (menu == 1) {
			menu = menuPrincipal(acao, &n);
		} else if (menu == 2) {
			menu = menuSaida(acao, &n);
		} else {
			if (!n) {
				setPlayer ();
				timer();
				n = 1;
			}
			n = fase (n, acao);
			mostraStats();
			if (n == 99) {
				termina ();
				salvaPontuacao ();
				menu = 2;
			}
		}

		/*Bloco de Redesenho*/
		if (ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(event_queue)) {
			al_draw_bitmap  (fundoMenu, 0, 0, 0);
			//desenhaElementos (arrayElementos);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
		/*Fim do Bloco de Redesenho*/
	}
	/*Fim Jogo*/

	/*Destrói Allegro*/
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
	al_destroy_display(display);
	return 0;
	/*Fim*/
}
