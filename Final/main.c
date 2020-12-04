#include"Ajedrez.h"
#include<stdio.h>
#include<stdlib.h>


int main() {
    setbuf(stdout, NULL);
    struct piece **board2[8];

    struct piece *ap0[8];
    struct piece *ap1[8];
    struct piece *ap2[8];
    struct piece *ap3[8];
    struct piece *ap4[8];
    struct piece *ap5[8];
    struct piece *ap6[8];
    struct piece *ap7[8];


    board2[0] = ap0;
    board2[1] = ap1;
    board2[2] = ap2;
    board2[3] = ap3;
    board2[4] = ap4;
    board2[5] = ap5;
    board2[6] = ap6;
    board2[7] = ap7;

    struct gamestate new_game;
    struct piece * blancas[16];
    struct piece * negras[16];


    new_game.blancas= blancas;
    new_game.Negras= negras;
    new_game.turn = 1;




    init_game(board2);



    puts("Bienvenido al ajedrez ");

    // arreglo de partidas
    struct piece ****games = malloc(sizeof(struct piece ***) * 2);
    int *jaque_state = calloc(sizeof(int), 2);
    int current_size = 1;
    jaque_state[0] = 0;
    games[0] = create_empty_board();
    copiar_tablero(board2, games[0]);

    puts("\n");
    int x = 0;
    int y = 0;
    int x1 = 0;
    int y1 = 0;

    int opt = 0;
    int result = 0;
    int carga;
    char guardar;

    piece_count(board2,&new_game);


    while (new_game.turn > 0) {
        print_board(board2);

        puts("\n");
        puts("\n");


        puts("Que quieres hacer: \n 0 Salir del juego\n 1 mover piezas \n 2 Cargar un juego\n 3 volver a una partida pasada");
        scanf("%i", &carga);

        if (carga == 0) {
            puts("Gracias por jugar con usted mismo, esperamos que la haya disfrutado");
            return 0;
        }

        if (carga == 2) {
            FILE *f = NULL;
            do {
                puts("Cual numero de juego quieres cargar");
                int number = 0;
                puts("Ingresa numero de partida: ");
                scanf("%d", &number);
                char filename[256] = {0};

                sprintf(filename, "tablero%d.bin", number);
                f = fopen(filename, "rb");
            } while (f == NULL);

            fread(&current_size, sizeof(int), 1, f);
            games = realloc(games, sizeof(struct piece ***) * current_size);

            jaque_state = realloc(games, sizeof(int) * current_size);
            fread(jaque_state, sizeof(int), current_size, f);

            for (int i = 0; i < current_size; ++i) {
                games[i] = create_empty_board();
                load_game(games[i], f);
            }
            copiar_tablero(games[current_size - 1], board2);

            fclose(f);
            puts("Su tablero ha sido cargado con exito");
        }

        if (carga == 3) {
            if (current_size - 1 < 1) {
                puts("No hay partidas pasadas");
            } else {
                int num = 0;
                printf("Se jugaron %d movimientos\n", current_size);
                do {
                    printf("A cual quieres regrsar? (valido 1 a %d)", current_size - 1);
                    scanf("%d", &num);
                } while (num < 1 || num >= current_size);
                for (int i = num; i < current_size; ++i) {
                    struct piece ***board_to_delete = games[i];
                    for (int j = 0; j < 8; ++j) {
                        for (int k = 0; k < 8; ++k) {
                            if (board_to_delete[j][k] != NULL) {
                                free(board_to_delete[j][k]);
                            }
                        }
                        free(board_to_delete[j]);
                    }
                }
                current_size = num;
                games = realloc(games, sizeof(struct piece ***) * current_size);
                copiar_tablero(games[num - 1], board2);
                new_game.jaque = jaque_state[num - 1];
            }
        }

        if (carga == 1) {

            if (new_game.turn == 1) {

                int sf= is_king_safe(board2,&new_game,new_game.turn);

                puts("Turno de las blancas \n");
                printf("el estado del rey es %i\n",sf);

                printf("valor en y de la pieza\n");
                scanf("%i", &y);
                printf("valor en x   de la pieza\n");
                scanf("%i", &x);


                printf("nueva  coordenada y\n");
                scanf("%i", &y1);
                printf("nueva coordenada x\n");
                scanf("%i", &x1);


                while (board2[y][x] == NULL || board2[y][x]->color != 'W') {
                    puts("hey eso es ilegal");
                    printf("valor en y de la pieza\n");
                    scanf("%i", &y);
                    printf("valor en x   de la pieza\n");
                    scanf("%i", &x);


                    printf("nueva  coordenada y\n");
                    scanf("%i", &y1);
                    printf("nueva coordenada x\n");
                    scanf("%i", &x1);

                }

                if (board2[y][x]->piece_type == 'p') {
                    puts("la pieza es un peon Privilegiado ");
                    result = White_Pawn(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }

                if (board2[y][x]->piece_type == 't') {
                    puts("la pieza es una torre ");
                    result = torre(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }

                if (board2[y][x]->piece_type == 'c') {
                    puts("la pieza es un caballo ");
                    result = caballo(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }

                if (board2[y][x]->piece_type == 'a') {
                    puts("la pieza es un alfil ");
                    result = alfil(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }

                if (board2[y][x]->piece_type == 'k') {
                    puts("la pieza es el Rey ");
                    result = king(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }
                if (board2[y][x]->piece_type == 'R') {
                    puts("la pieza es la Reina ");
                    result = reyna(board2[y][x], x1, y1, board2);
                    new_game.turn = 2;
                }
                printf("el resultado fue %i\n", result);

                swap(board2, y, x, y1, x1, result);
                piece_count(board2,&new_game);

            }


            print_board(board2);
            puts("\n");
            puts("\n");

            if (new_game.turn == 2) {
                int sf=is_king_safe(board2,&new_game,new_game.turn);
                puts("Turno de las negras \n");
                printf("el estado del rey es %i\n",sf);

                printf("valor en y de la pieza\n");
                scanf("%i", &y);
                printf("valor en x   de la pieza\n");
                scanf("%i", &x);


                printf("nueva  coordenada y\n");
                scanf("%i", &y1);
                printf("nueva coordenada x\n");
                scanf("%i", &x1);

                while (board2[y][x] == NULL || board2[y][x]->color != 'B') {
                    puts("hey eso es ilegal");

                    printf("valor en y de la pieza\n");
                    scanf("%i", &y);
                    printf("valor en x   de la pieza\n");
                    scanf("%i", &x);


                    printf("nueva  coordenada y\n");
                    scanf("%i", &y1);
                    printf("nueva coordenada x\n");
                    scanf("%i", &x1);

                }

                if (board2[y][x]->piece_type == 'P') {
                    puts("la pieza es un peon Nibba ");
                    result = Black_Pawn(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;
                }

                if (board2[y][x]->piece_type == 'T') {
                    puts("la pieza es una torre ");
                    result = torre(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;
                }

                if (board2[y][x]->piece_type == 'C') {
                    puts("la pieza es un caballo ");
                    result = caballo(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;
                }

                if (board2[y][x]->piece_type == 'A') {
                    puts("la pieza es un alfil ");
                    result = alfil(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;

                }
                if (board2[y][x]->piece_type == 'K') {
                    puts("la pieza es el Rey ");
                    result = king(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;

                }
                if (board2[y][x]->piece_type == 'R') {
                    puts("la pieza es la Reina ");
                    result = reyna(board2[y][x], x1, y1, board2);
                    new_game.turn = 1;
                }

                printf("el resultado fue %i\n\n", result);
                swap(board2, y, x, y1, x1, result);
                print_board(board2);
                piece_count(board2,&new_game);
                puts("\n");

            }
            games[current_size] = create_empty_board();
            jaque_state[current_size++] = new_game.jaque;
            games = realloc(games, sizeof(struct piece ***) * (current_size + 1));
            jaque_state = realloc(jaque_state, sizeof(int) * (current_size + 1));
            copiar_tablero(board2, games[current_size - 1]);
            // ---------------------------

            puts("Quieres guardar el tablero s es para si, cualquier otra letra es no");
            getc(stdin);
            scanf("%c", &guardar);

            if (guardar == 's') {
                int number = 0;
                puts("Ingresa numero de partida: ");
                scanf("%d", &number);
                char filename[256] = {0};
                sprintf(filename, "tablero%d.bin", number);
                FILE *f = fopen(filename, "wb");
                fwrite(&current_size, sizeof(int), 1, f);
                fwrite(jaque_state, sizeof(int), current_size, f);

                for (int i = 0; i < current_size; ++i) {
                    save_game(games[i], f);
                }
                fclose(f);
                puts("Se guardaron los ultimos movimientos");
            }
            // -----------------
        }


    }

}





