#include"Ajedrez_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main(){

struct piece **  board2[8];

struct piece *ap0[8];
struct piece *ap1[8];
struct piece *ap2[8];
struct piece *ap3[8];   
struct piece *ap4[8];
struct piece *ap5[8];
struct piece *ap6[8];
struct piece *ap7[8];


board2[0]=ap0;
board2[1]=ap1;
board2[2]=ap2;
board2[3]=ap3;
board2[4]=ap4;
board2[5]=ap5;
board2[6]=ap6;
board2[7]=ap7;

init_game(board2);
print_board(board2);

int x=0;
int y=0; 
int x1=0;
int y1=0; 
puts("\n");


printf("valor en y de la pieza\n");
scanf("%i",&y);
printf("valor en x   de la pieza\n");
scanf("%i",&x);
printf("es un %c  \n",board2[y][x]->piece_type);


printf("nueva  coordenada y\n");
scanf("%i",&y1);
printf("nueva coordenada x\n");
scanf("%i",&x1);

int a=Move_white_Pieces(board2[y][x],x1,y1,board2);

printf("la opcion fue %i\n",a);





/*


printf("valor en y de la pieza\n");
scanf("%i",&y);
printf("valor en x   de la pieza\n");
scanf("%i",&x);
printf("es un %c  \n",board2[y][x]->piece_type);


printf("nueva  coordenada y\n");
scanf("%i",&y1);
printf("nueva coordenada x\n");
scanf("%i",&x1);









 a=Move_white_Pieces(board2[y][x],x1,y1,board2);

printf("la opcion fue %i",a);



*/



    
}