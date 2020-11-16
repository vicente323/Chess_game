#ifndef _AJEDEREZ_GAME_GUARD_H
#define _AJEDEREZ_GAME_GUARD_H

struct piece 
{
     char piece_type;
     int  mvs;
     char color;


    
};

void init_game(int **board, struct piece ***board2);


#endif