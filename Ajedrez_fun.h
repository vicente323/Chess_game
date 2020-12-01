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
     int haque;
     struct piece **Negras;
     struct piece ** blancas;
     

};

void swap(struct piece ***board2,int y, int x, int ny, int nx, int result );
void is_king_safe(struct piece ***board2,struct gamestate * game, int opt);

 int Torre(struct piece * piece, int x, int y, struct piece *** board2);
void begin(struct gamestate game);

void init_game( struct piece ***board2);

void print_board(struct piece ***board2);
int White_Pawn(struct piece * piece,int x ,int y,struct piece ***board2);
int Black_Pawn(struct piece * piece, int x ,int y,struct piece ***board2);

int caballo(struct piece * piece, int x ,int y,struct piece ***board2);
int alfil(struct piece * piece, int x, int y, struct piece *** board2);
        
int torre(struct piece * piece, int x ,int y,struct piece ***board2);
int king(struct piece * piece, int x ,int y,struct piece ***board2);

void piece_count(struct piece ***board2,struct gamestate * game);
#endif


