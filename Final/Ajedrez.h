//
// Created by PC on 19/11/2020.
//
#include <stdio.h>
#ifndef _AJEDEREZ_GAME_GUARD_H
#define _AJEDEREZ_GAME_GUARD_H

struct piece
{
    char piece_type;
    int  mvs;
    char color;
    int x_axis;
    int y_axis;



};
struct gamestate{
    int turn;
    int jaque;
    struct piece ** Negras;
    struct piece ** blancas;
};

void swap(struct piece ***board2,int y, int x, int ny, int nx, int result );
int is_king_safe(struct piece ***board2,struct gamestate * game, int opt);

int torre(struct piece * piece, int x, int y, struct piece *** board2);
void begin(struct gamestate game);

void init_game( struct piece ***board2);

void print_board(struct piece ***board2);
int White_Pawn(struct piece * piece,int x ,int y,struct piece ***board2);
int Black_Pawn(struct piece * piece, int x ,int y,struct piece ***board2);

int caballo(struct piece * piece, int x ,int y,struct piece ***board2);
int alfil(struct piece * piece, int x, int y, struct piece *** board2);


int king(struct piece * piece, int x ,int y,struct piece ***board2);

int reyna(struct piece * piece, int x ,int y,struct piece ***board2);

void piece_count(struct piece ***board2,struct gamestate * game);

void save_game(struct piece *** board2, FILE * file);

void load_game(struct piece *** board2, FILE * file);

void copiar_tablero(struct piece *** source, struct piece *** destination);

void clean_board(struct piece ***board2);

void coppy_board(struct piece ***board2,struct piece ***target);

struct piece ***create_empty_board();
#endif

