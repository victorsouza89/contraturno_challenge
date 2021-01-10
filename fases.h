void fase (int *n, ALLEGRO_FONT *fonteTitulo) {
    switch (*n) {
        case 1:
        if (!numeroExecucao) {
            if (initBg (1)) {
                fadeStart = contador-1;
                numeroExecucao++;
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Hoje eh o seu primeiro";
                char linha2[] = "contraturno no IFSC.";
                char linha3[] = "Seu objetivo eh";
                char linha4[] = "sobreviver a esse dia.";
                char linha5[] = "Boa sorte, mono!";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 2:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(2)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Todo bom dia comeca no";
                char linha2[] = "cafe da manha.";
                char linha3[] = "E aqui ja temos algumas";
                char linha4[] = "escolhas importantes";
                char linha5[] = "a serem feitas.";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 3:
        if (!numeroExecucao) {
            char img1[] = "cafe.png";
            char img2[] = "agua.png";
            char img3[] = "suco.png";
            setOpcao(&opcao1, img1, rd(-1, 0.5), rd(1, 2.5), 0, 0, 0);
            setOpcao(&opcao2, img2, rd(0, 1), rd(-1, 0), 0, 0, 0);
            setOpcao(&opcao3, img3, rd(-0.2, 1.5), rd(-0.5, 0.5), 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "O QUE VAI BEBER?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 4:
        if (!numeroExecucao) {
            char img1[] = "pao.png";
            char img2[] = "choc.png";
            char img3[] = "bisc.png";
            setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, 0);
            setOpcao(&opcao2, img2, rd(-1.5, -1), rd(0.5, 2), 0, 0, 0);
            setOpcao(&opcao3, img3, rd(-0.5, 0), rd(-0.5, 0.5), 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "O QUE VAI COMER?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 5:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(3)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Chegou a hora de ir.";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Mas como voce vai?";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 6:
        if (!numeroExecucao) {
            char img1[] = "uber.png";
            char img2[] = "bus.png";
            char img3[] = "bike.png";
            setOpcao(&opcao1, img1, 0, 0, -3.5, 0, 0);
            setOpcao(&opcao2, img2, 0, rd(0, 1), rd(-5, -4), 0, 0);
            setOpcao(&opcao3, img3, rd(1, 3), rd(-3, 0), 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "COMO VAI PRA AULA?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 7:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(4)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Chegamos!!";
                char linha2[] = "Mas tudo mal comecou...";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Vamos entrando.";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 8:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(5)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Voce encontrou Joao,";
                char linha2[] = "grande amigo seu.";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Joao tem uma proposta";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 9:
        if (!numeroExecucao) {
            char img1[] = "bol.png";
            char img2[] = "nop.png";
            char img3[] = "pass.png";
            setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, rd(-8, -4));
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, rd(-1, 0.5), 0, rd (1, 2), rd(-8, -4));
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            if (selecaoMenu/10 == 1) {
                *n = 50;
            } else if (selecaoMenu/10 == 3) {
                *n = 52;
            }
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "MATA A AULA?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 10:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(6)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Chegamos na Sala!";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Vamos sentando, mas";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 11:
        if (!numeroExecucao) {
            char img1[] = "fre.png";
            char img2[] = "meio.png";
            char img3[] = "tras.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "ONDE VAI SENTAR?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 12:
        if (!numeroExecucao) {

            if (endBg (0.5)) {
                if (initBg(7)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Uma divertida aula de";
                char linha2[] = "PI comeca.";
                char linha3[] = "";
                char linha4[] = "Mas sao 7:30";
                char linha5[] = "e bateu aquele sono";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 13:
        if (!numeroExecucao) {
            char img1[] = "foco.png";
            char img2[] = "zzz.png";
            char img3[] = "conv.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "COMO LEVA ESSE INICIO?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 14:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(8)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Bateu o Sinal!";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Bora descer";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 15:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(9)) {
                    char img1[] = "nada.png";
                    char img2[] = "salg.png";
                    char img3[] = "bolo.png";
                    setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
                    setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
                    setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
                    initMenuSelecao ();
                }
            }
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "COMER ALGUMA COISA?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 16:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(10)) {
                    char img1[] = "conv.png";
                    char img2[] = "bib.png";
                    char img3[] = "zzz.png";
                    setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
                    setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
                    setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
                    initMenuSelecao ();
                }
            }
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E PRA ONDE VAI?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 17:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(11)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Aula de Educacao Fisica";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Momento de suar";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 18:
        if (!numeroExecucao) {
                    char img1[] = "gain.png";
                    char img2[] = "mig.png";
                    char img3[] = "pass.png";
                    setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
                    setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
                    setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
                    initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "VAI FUNDO NO ESPORTE?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 19:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(12)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Bateu mais um sinal";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Bora pro Almoco";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 20:
        if (!numeroExecucao) {
            char img1[] = "sub.png";
            char img2[] = "grel.png";
            char img3[] = "shop.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            numeroFase = 52 + selecaoMenu/10;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "MAS ONDE?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 21:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(13)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Aula de Matematica";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Bora fazer umas contas";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 22:
        if (!numeroExecucao) {
            char img1[] = "foco.png";
            char img2[] = "exer.png";
            char img3[] = "conv.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "COMO SE PORTAR?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 23:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(14)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Agora vamos para";
                char linha2[] = "o ultimo intervalo";
                char linha3[] = "do dia";
                char linha4[] = "";
                char linha5[] = "E novas emocoes";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 24:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(15)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Voce ve uma linda";
                char linha2[] = "mona no patio.";
                char linha3[] = "As pernas tremem";
                char linha4[] = "e a cabeca roda.";
                char linha5[] = "O que voce faz?";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 25:
        if (!numeroExecucao) {
            char img1[] = "vamo.png";
            char img2[] = "fuga.png";
            char img3[] = "spo.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            if (selecaoMenu/10 == 1) {
                if (rand()%101 < (jogador.social)*5+30) {
                    numeroFase = 56;
                } else {
                    numeroFase = 57;
                }
            }
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "CHEGA NA MENINA?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 26:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(16)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Fim de um Intervalo";
                char linha2[] = "de alguma emocao";
                char linha3[] = "";
                char linha4[] = "Agora o laboratorio";
                char linha5[] = "de fisica";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 27:
        if (!numeroExecucao) {
            char img1[] = "foco.png";
            char img2[] = "mig.png";
            char img3[] = "exer.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E AI?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 28:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(17)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Fim de um longo dia";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Hora da saida";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 29:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(18)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
        } else {
            if (redraw) {
                char linha1[] = "Voce encontra uns";
                char linha2[] = "malucos ali falando";
                char linha3[] = "sobre fazer um jogo";
                char linha4[] = "e eles te convidam pra";
                char linha5[] = "jogar. Anima?";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 30:
        if (!numeroExecucao) {
            char img1[] = "nada.png";
            char img2[] = "pao.png";
            char img3[] = "pro.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            if (selecaoMenu/10 == 3)
                numeroFase = 58;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "O QUE QUER JOGAR?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        //Fases "Opcionais"
        case 50:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(50)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
            numeroFase = 51;
        } else {
            if (redraw) {
                char linha1[] = "Voce fez alguns gols e";
                char linha2[] = "o jogo ate foi legal";
                char linha3[] = "";
                char linha4[] = "Mas chegou a hora da";
                char linha5[] = "segunda aula. Vai?";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 51:
        if (!numeroExecucao) {
            char img1[] = "bol.png";
            char img2[] = "nop.png";
            char img3[] = "pass.png";
            setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, rd(-8, -4));
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, rd(-1, 0.5), 0, rd (1, 2), rd(-8, -4));
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            numeroFase = 10;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E AGORA. MATA A AULA?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 52:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(51)) {
                    fadeStart = contador-1;
                    numeroExecucao++;
                }
            }
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
            numeroFase = 51;
        } else {
            if (redraw) {
                char linha1[] = "Voce deu um passeio";
                char linha2[] = "com um pessoal e";
                char linha3[] = "conheceu gente nova";
                char linha4[] = "Mas eh hora da segunda";
                char linha5[] = "aula. Sai do role?";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 53:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(52)) {
                    char img1[] = "sau.png";
                    char img2[] = "gost.png";
                    char img3[] = "bar.png";
                    setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, rd(-8, -4));
                    setOpcao(&opcao2, img2, rd(-1.5, -1), rd(0.5, 2), 0, 0, 0);
                    setOpcao(&opcao3, img3, rd(-0.5, 0), rd(-0.5, 0.5), 0, 0, 0);
                    initMenuSelecao ();
                }
            }
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            numeroFase = 21;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E O QUE COME AQUI?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 54:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(53)) {
                    char img1[] = "sau.png";
                    char img2[] = "gost.png";
                    char img3[] = "bar.png";
                    setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, rd(-8, -4));
                    setOpcao(&opcao2, img2, rd(-1.5, -1), rd(0.5, 2), 0, 0, 0);
                    setOpcao(&opcao3, img3, rd(-0.5, 0), rd(-0.5, 0.5), 0, 0, 0);
                    initMenuSelecao ();
                }
            }
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            numeroFase = 21;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E O QUE COME AQUI?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 55:
        if (!numeroExecucao) {
            if (endBg (0.5)) {
                if (initBg(54)) {
                    char img1[] = "sau.png";
                    char img2[] = "gost.png";
                    char img3[] = "bar.png";
                    setOpcao(&opcao1, img1, rd(-0.5, 1), rd(-0.5, 0.5), 0, 0, rd(-8, -4));
                    setOpcao(&opcao2, img2, rd(-1.5, -1), rd(0.5, 2), 0, 0, 0);
                    setOpcao(&opcao3, img3, rd(-0.5, 0), rd(-0.5, 0.5), 0, 0, 0);
                    initMenuSelecao ();
                }
            }
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            numeroFase = 21;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "E O QUE COME AQUI?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 56:
        if (!numeroExecucao) {
            fadeStart = contador-1;
            numeroExecucao++;
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
            numeroFase = 26;
        } else {
            if (redraw) {
                char linha1[] = "Deu Certo!";
                char linha2[] = "";
                char linha3[] = "";
                char linha4[] = "";
                char linha5[] = "Voce curtiu o intervalo";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 57:
        if (!numeroExecucao) {
            fadeStart = contador-1;
            numeroExecucao++;
        } else if (numeroExecucao == 2) {
            fimMenuLeitura ();
            fadeStart = contador-1;
            numeroFase = 26;
        } else {
            if (redraw) {
                char linha1[] = "Deu Errado!";
                char linha2[] = "";
                char linha3[] = "Mas quem nunca";
                char linha4[] = "levou um fora?";
                char linha5[] = "Sigamos a vida";
                if (redesenhaMenuLeitura (fonteTitulo, linha1, linha2, linha3, linha4, linha5)) {
                    if (teclas[3] || teclas[5]) {
                        numeroExecucao++;
                    }
                }
            }
        }
        break;
        case 58:
        if (!numeroExecucao) {
            char img1[] = "pao.png";
            char img2[] = "pao.png";
            char img3[] = "pro.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
            if (selecaoMenu/10 == 3)
                numeroFase = 59;
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "QUER JOGAR?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        case 59:
        if (!numeroExecucao) {
            char img1[] = "pao.png";
            char img2[] = "pao.png";
            char img3[] = "pao.png";
            setOpcao(&opcao1, img1, 0, 0, 0, 0, 0);
            setOpcao(&opcao2, img2, 0, 0, 0, 0, 0);
            setOpcao(&opcao3, img3, 0, 0, 0, 0, 0);
            initMenuSelecao ();
        } else if (numeroExecucao == 2) {
            endMenuSelecao ();
        } else {
            selecionaMenu(&selecaoMenu, direcaoMenu(teclas, &bufferTeclas[0]));
            if (redraw) {
                char texto[] = "QUER JOGAR?";
                redesenhaMenuSelecao (fonteTitulo, texto);
            }
        }
        break;
        default:
            gameState = 4;
        break;
    }
}
