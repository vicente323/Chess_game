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
int move_Black_pieces(struct piece * piece,int x ,int y,struct piece ***board2);
void print_board(struct piece ***board2);


#endif