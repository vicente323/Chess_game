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

void init_game( struct piece ***board2);
void move_piece(struct piece * piece_mv);
void print_board(struct piece ***board2);


#endif