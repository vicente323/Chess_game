#ifndef _AJEDEREZ_GAME_GUARD_H
#define _AJEDEREZ_GAME_GUARD_H
struct gamestate{
     int turn;
     int haque;


};
struct piece 
{
     char piece_type;
     int  mvs;
     char color;
     int x_axis;
     int y_axis; 


    
};
void begin(struct gamestate game);

void init_game( struct piece ***board2);

void print_board(struct piece ***board2);
int White_Pawn(struct piece * piece,int x ,int y,struct piece ***board2);
int Black_Pawn(struct piece * piece, int x ,int y,struct piece ***board2);

int caballo(struct piece * piece, int x ,int y,struct piece ***board2);
int alfil(struct piece * piece, int x, int y, struct piece *** board2);
        
int torre(struct piece * piece, int x ,int y,struct piece ***board2);
int king(struct piece * piece, int x ,int y,struct piece ***board2);
#endif