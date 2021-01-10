/*Funcoes Gerais*/
float rd (float minimo, float maximo) {
    if (minimo > maximo) {
        float temp = minimo;
        minimo = maximo;
        maximo = temp;
    }
    int intervalo = (maximo-minimo)*100;
    int r = rand ();
    float a = (r%(intervalo+1));
    float retorno = (minimo + a/100);
    return retorno;
}
/*Fim do Bloco de Funcoes gerais*/


/*Fun?es para Leitura de Teclado*/
void checaTeclas (bool *tecla, ALLEGRO_EVENT ev)  {
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch(ev.keyboard.keycode)	{
			case ALLEGRO_KEY_UP:
			*(tecla + 0) = true;
			break;
			case ALLEGRO_KEY_DOWN:
			*(tecla + 1) = true;
			break;
			case ALLEGRO_KEY_LEFT:
			*(tecla + 2) = true;
			break;
			case ALLEGRO_KEY_RIGHT:
			*(tecla + 3) = true;
			break;
			case ALLEGRO_KEY_ENTER:
			*(tecla + 4) = true;
			break;
			case ALLEGRO_KEY_SPACE:
			*(tecla + 5) = true;
			break;
			case ALLEGRO_KEY_ESCAPE:
			*(tecla + 6) = true;
			break;
			default:
			break;
		}
	} else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
		switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
			*(tecla + 0) = false;
			break;
			case ALLEGRO_KEY_DOWN:
			*(tecla + 1) = false;
			break;
			case ALLEGRO_KEY_LEFT:
			*(tecla + 2) = false;
			break;
			case ALLEGRO_KEY_RIGHT:
			*(tecla + 3) = false;
			break;
			case ALLEGRO_KEY_ENTER:
			*(tecla + 4) = false;
			break;
			case ALLEGRO_KEY_SPACE:
			*(tecla + 5) = false;
			break;
			case ALLEGRO_KEY_ESCAPE:
			*(tecla + 6) = false;
			break;
			default:
			break;
		}
	}
}

void movePersonagem (int *x, int *y, bool tecla[7], int speedX, int speedY) {
	if (tecla[0]) {
		*y-=speedY;
	}
	if (tecla[1]) {
		*y+=speedY;
	}
	if (tecla[2]) {
		*x-=speedX;
	}
	if (tecla[3]) {
		*x+=speedX;
	}
}

int direcaoMenu (bool teclas[7], bool *buffer) {
	int k, l = 0;
	for (k=2; k<5; k++) {
		if (teclas[k] && !(*(buffer + k))) {
			l = k;
		}
	}
	for (k=0; k<7; k++) {
		if (teclas[k] != *(buffer + k)) {
			*(buffer + k) = teclas[k];
		}
	}
	return l;
}

void selecionaMenu (int *n, int direcaoMenu) {
	switch (direcaoMenu) {
		case 2:
		(*n)--;
		if ((*n) < 1) {
			(*n) = 3;
		}
		break;
		case 3:
		(*n)++;
		if ((*n) > 3) {
			(*n) = 1;
		}
		break;
		case 4:
		(*n) = (*n)*10;
		fadeStart = contador-1;
		break;
		default:
		break;
	}
}
/*Fim do bloco de leitura de teclado*/


/*Bloco de Atributos do Player*/
void initPlayer () {
	jogador.saude = rd (5, 10);
	jogador.energia = rd (4, 10);
	jogador.dinheiro = rd (10, 20);
	jogador.social = rd (5, 8);
	jogador.dedicacao = rd (5, 8);
}

void aplicaEfeitoPlayer (float saude, float energia, float dinheiro, float social, float dedicacao) {
	jogador.saude += saude;
	jogador.energia += energia;
	jogador.dinheiro += dinheiro;
	jogador.social += social;
	jogador.dedicacao += dedicacao;
}
/*Fim do Bloco de Atributos do Player*/


/*Bloco de Fade e Transi?o*/
void imagemComFadeIn (ALLEGRO_BITMAP *imagem, int x, int y, float tempoSegundos) {
	int k = (255*(contador-fadeStart))/(FPS*tempoSegundos);
	if (redraw) {
		if (k < 255) {
			al_draw_tinted_bitmap(imagem, al_map_rgba(k, k, k, k), x, y, 0);
		} else {
			al_draw_bitmap (imagem, x, y, 0);
		}
	}
}

bool imagemFadeOut (ALLEGRO_BITMAP *imagem, int x, int y, float tempoSegundos) {
	int k = 255-((255*(contador-fadeStart))/(FPS*tempoSegundos));
	if (redraw) {
		if (k > 0) {
			al_draw_tinted_bitmap(imagem, al_map_rgba(k, k, k, k), x, y, 0);
		} else {
			return true;
		}
	}
	return false;
}

bool initBg (int q) {
	int k = 255-((255*(contador-fadeStart2))/(FPS/4));
	if (k == 255) {
		switch (q) {
			case 1:
			background = al_load_bitmap ("sprites/cenarios/cama.png");
			break;
			case 2:
			background = al_load_bitmap ("sprites/cenarios/mesa.png");
			break;
			case 3:
			background = al_load_bitmap ("sprites/cenarios/pontoOnibus.png");
			break;
			case 4:
			background = al_load_bitmap ("sprites/cenarios/ifscEntrada.png");
			break;
			case 5:
			background = al_load_bitmap ("sprites/cenarios/joaoHall.png");
			break;
			case 6:
			background = al_load_bitmap ("sprites/cenarios/entraSala.png");
			break;
			case 7:
			background = al_load_bitmap ("sprites/cenarios/salaPI.png");
			break;
			case 8:
			background = al_load_bitmap ("sprites/cenarios/saiSala.png");
			break;
			case 9:
			background = al_load_bitmap ("sprites/cenarios/cantina.png");
			break;
			case 10:
			background = al_load_bitmap ("sprites/cenarios/lugarPatio.png");
			break;
			case 11:
			background = al_load_bitmap ("sprites/cenarios/ginasioJogo.png");
			break;
			case 12:
			background = al_load_bitmap ("sprites/cenarios/indoAlmocar.png");
			break;
			case 13:
			background = al_load_bitmap ("sprites/cenarios/salaMatematica.png");
			break;
			case 14:
			background = al_load_bitmap ("sprites/cenarios/patio.png");
			break;
			case 15:
			background = al_load_bitmap ("sprites/cenarios/mona.png");
			break;
			case 16:
			background = al_load_bitmap ("sprites/cenarios/labFisica.png");
			break;
			case 17:
			background = al_load_bitmap ("sprites/cenarios/saidaHall.png");
			break;
			case 18:
			background = al_load_bitmap ("sprites/cenarios/malucos.png");
			break;
			case 50:
			background = al_load_bitmap ("sprites/cenarios/quadra.png");
			break;
			case 51:
			background = al_load_bitmap ("sprites/cenarios/role.png");
			break;
			case 52:
			background = al_load_bitmap ("sprites/cenarios/subway.png");
			break;
			case 53:
			background = al_load_bitmap ("sprites/cenarios/grelhados.png");
			break;
			case 54:
			background = al_load_bitmap ("sprites/cenarios/shopping.png");
			break;
			case 98:
            background = al_load_bitmap ("sprites/cenarios/telaYouWon.png");
            break;
			case 99:
            background = al_load_bitmap ("sprites/cenarios/telaGameOver.png");
            break;
			default:
            background = al_load_bitmap ("sprites/cenarios/ifscFachada.png");
            break;
		}
	} else if (k >= 0) {
		al_draw_filled_rectangle(0, 0, LARGURA, ALTURA, al_map_rgba(0, 0, 0, k));
	} else {
		return true;
	}
	return false;
}

bool endBg (float tempoSegundos) {
	int k = (255*(contador-fadeStart))/(FPS*tempoSegundos);
	if (redraw) {
		if (k <= 255) {
			al_draw_filled_rectangle(0, 0, LARGURA, ALTURA, al_map_rgba(0, 0, 0, k));
			if (k==255) {
				background = NULL;
                al_destroy_bitmap(background);
				fadeStart2 = contador + 2;
			}
		} else {
			return true;
		}
	}
	return false;
}
/*Fim do Bloco de Fade e Transi?o*/


/*Fun?es para Indicadores da Barra Superior*/
void escreveAtributo (char label[], float *buffer, float att, int x, int y, ALLEGRO_FONT *fonte) {
	char atributo[6];
	int r = 202, g = 202, b = 202;

	if (*buffer < att) {
		if (att - *buffer < 0.01) {
			*buffer = att;
		} else {
			*buffer = *buffer + (att-*buffer)/6;
		}
		r = 124;
		g = 239;
		b = 138;
	} else if (*buffer > att) {
		if (*buffer - att < 0.01) {
			*buffer = att;
		} else {
			*buffer = *buffer + (att-*buffer)/6;
		}
		r = 244;
		g = 129;
		b = 129;
	}
	sprintf(atributo, "%.2f", *buffer);
	strcat(label, atributo);
	al_draw_text (fonte, al_map_rgb(r, g, b), x, y, ALLEGRO_ALIGN_LEFT, label);
}

void indicadorStats (ALLEGRO_FONT *fonte) {
	al_draw_filled_rectangle(0, 0, LARGURA, 50, al_map_rgba(0, 0, 0, 180));

	char labelSaude[] = "S:";
	escreveAtributo (labelSaude, &jogador.bufferSaude, jogador.saude, 40, 5, fonte);
	char labelEnergia[] = "*:";
	escreveAtributo (labelEnergia, &jogador.bufferEnergia, jogador.energia, 310, 5, fonte);
	char labelDinheiro[] = "$:";
	escreveAtributo (labelDinheiro, &jogador.bufferDinheiro, jogador.dinheiro, 580, 5, fonte);
	char labelSocial[] = "@:";
	escreveAtributo (labelSocial, &jogador.bufferSocial, jogador.social, 850, 5, fonte);
	char labelDedicacao[] = "!:";
	escreveAtributo (labelDedicacao, &jogador.bufferDedicacao, jogador.dedicacao, 1120, 5, fonte);
}
/*Fim do Bloco de Indicadores*/


/*Fun?es para os Menus de Sele?o*/
void setOpcao (struct opcao *o, char nomeArquivo[], float saude, float energia, float dinheiro, float social, float dedicacao) {
	char endereco[] = "sprites/menus/opcoes/";
	strcat(endereco, nomeArquivo);
	o->saude = saude;
	o->energia = energia;
	o->dinheiro = dinheiro;
	o->social = social;
	o->dedicacao = dedicacao;
	o->sprite = al_load_bitmap (endereco);
}

void initMenuSelecao () {
	fundoMenu = al_load_bitmap ("sprites/menus/esqueletoMenuSelecao.jpg");
	selecaoMenu = 1;
	numeroExecucao++;
	fadeStart = contador-1;
}

void redesenhaMenuSelecao (ALLEGRO_FONT *fonteTitulo, char texto[]) {
	if (selecaoMenu < 10) {
		int k = ((150/(FPS*0.3))*(contador-fadeStart));
		imagemComFadeIn (fundoMenu, 175, 100, 0.3);
		imagemComFadeIn (opcao1.sprite, 269, 350, 0.3);
		imagemComFadeIn (opcao2.sprite, 572, 350, 0.3);
		imagemComFadeIn (opcao3.sprite, 875, 350, 0.3);

		k = ((255/(FPS*0.3))*(contador-fadeStart));
		if (k < 255) {
			al_draw_text(fonteTitulo, al_map_rgba(255, 255, 255, k), 700, 180, ALLEGRO_ALIGN_CENTRE, texto);
			al_draw_rectangle(selecaoMenu*303-31, 353, selecaoMenu*303+221, 605, al_map_rgba(128, 24, 21, k), 6);
		} else {
			al_draw_text(fonteTitulo, al_map_rgba(255, 255, 255, 255), 700, 180, ALLEGRO_ALIGN_CENTRE, texto);
			al_draw_rectangle(selecaoMenu*303-31, 353, selecaoMenu*303+221, 605, al_map_rgb(128, 24, 21), 6);
		}
	} else {
		int k = 150 - ((150/(FPS*0.2))*(contador-fadeStart));
		k = 255 - ((255/(FPS*0.2))*(contador-fadeStart));
		if (k > 0) {
            //al_draw_text(fonteTitulo, al_map_rgba(255, 255, 255, k), 700, 180, ALLEGRO_ALIGN_CENTRE, texto);
			int s = selecaoMenu/10;
			al_draw_rectangle(s*303-31, 353, s*303+221, 605, al_map_rgba(128, 24, 21, k), 6);
		}
		if (imagemFadeOut (fundoMenu, 175, 100, 0.2) && imagemFadeOut (opcao1.sprite, 269, 350, 0.2) && imagemFadeOut (opcao2.sprite, 572, 350, 0.2) && imagemFadeOut (opcao3.sprite, 875, 350, 0.2)) {
			numeroExecucao++;
		}
	}
}

void endMenuSelecao () {
	float saude, energia, dinheiro, social, dedicacao;
	switch (selecaoMenu/10) {
		case 1:
		saude = opcao1.saude;
		energia = opcao1.energia;
		dinheiro = opcao1.dinheiro;
		social = opcao1.social;
		dedicacao = opcao1.dedicacao;
		break;
		case 2:
		saude = opcao2.saude;
		energia = opcao2.energia;
		dinheiro = opcao2.dinheiro;
		social = opcao2.social;
		dedicacao = opcao2.dedicacao;
		break;
		case 3:
		saude = opcao3.saude;
		energia = opcao3.energia;
		dinheiro = opcao3.dinheiro;
		social = opcao3.social;
		dedicacao = opcao3.dedicacao;
		break;
		default:
		break;
	}
	aplicaEfeitoPlayer(saude, energia, dinheiro, social, dedicacao);

	fundoMenu = NULL;
	opcao1.sprite = NULL;
	opcao2.sprite = NULL;
	opcao3.sprite = NULL;
	al_destroy_bitmap(opcao1.sprite);
    al_destroy_bitmap(opcao2.sprite);
    al_destroy_bitmap(opcao3.sprite);
	numeroFase++;
	numeroExecucao = 0;
}
/*Fim do Bloco de Menu de Sele?o*/


/*Fun?es para os Menus de Leitura*/
bool redesenhaMenuLeitura (ALLEGRO_FONT *fonteTitulo, char linha1[], char linha2[], char linha3[], char linha4[], char linha5[]) {
	int k = ((180/(FPS*0.5))*(contador-fadeStart));
	if (k < 180) {
		al_draw_rectangle(175, 100, 1225, 700, al_map_rgba(128, 24, 21, k), 6);
		al_draw_filled_rectangle(175, 100, 1225, 700, al_map_rgba(0, 0, 0, k));
	} else {
		al_draw_rectangle(175, 100, 1225, 700, al_map_rgba(128, 24, 21, 180), 6);
		al_draw_filled_rectangle(175, 100, 1225, 700, al_map_rgba(0, 0, 0, 180));
		al_draw_text(fonteTitulo, al_map_rgb(255, 255, 255), 250, 160, ALLEGRO_ALIGN_LEFT, linha1);
		al_draw_text(fonteTitulo, al_map_rgb(255, 255, 255), 250, 260, ALLEGRO_ALIGN_LEFT, linha2);
		al_draw_text(fonteTitulo, al_map_rgb(255, 255, 255), 250, 360, ALLEGRO_ALIGN_LEFT, linha3);
		al_draw_text(fonteTitulo, al_map_rgb(255, 255, 255), 250, 460, ALLEGRO_ALIGN_LEFT, linha4);
		al_draw_text(fonteTitulo, al_map_rgb(255, 255, 255), 250, 560, ALLEGRO_ALIGN_LEFT, linha5);
		return true;
	}
	return false;
}

void fimMenuLeitura () {
	int k = 180-((180/(FPS*0.3))*(contador-fadeStart));
	if (k > 0) {
		al_draw_rectangle(175, 100, 1225, 700, al_map_rgba(128, 24, 21, k), 6);
		al_draw_filled_rectangle(175, 100, 1225, 700, al_map_rgba(0, 0, 0, k));
	} else {
		numeroFase++;
		numeroExecucao = 0;
	}
}
/*Fim do Bloco de Menu de Leitura*/


