struct player {
	char nome[20];
	float saude, energia, dinheiro, social, dedicacao;
	float bufferSaude, bufferEnergia, bufferDinheiro, bufferSocial, bufferDedicacao;
};
struct player jogador = {};

struct opcao {
    ALLEGRO_BITMAP *sprite;
	float saude, energia, dinheiro, social, dedicacao;
};
struct opcao opcao1 = {NULL, 0, 0, 0, 0, 0};
struct opcao opcao2 = {NULL, 0, 0, 0, 0, 0};
struct opcao opcao3 = {NULL, 0, 0, 0, 0, 0};
