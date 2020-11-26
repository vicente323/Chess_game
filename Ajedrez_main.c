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
struct gamestate new_game;
new_game.turn=1;
init_game(board2);
print_board(board2);

    puts("\n");
int x=0;
int y=0;
int x1=0;
int y1=0;

int opt=0;
int result=0;





while(new_game.turn>0){


    puts("\n");
    puts("\n");
    puts("\n");
    puts("\n");
    puts("\n");
   


    if(new_game.turn==1){

        puts("Turno de las blancas \n");

        
        printf("valor en y de la pieza\n");
        scanf("%i",&y);
        printf("valor en x   de la pieza\n");
        scanf("%i",&x);


        printf("nueva  coordenada y\n");
        scanf("%i",&y1);
        printf("nueva coordenada x\n");
        scanf("%i",&x1);


        while (board2[y][x]==NULL||board2[y][x]->color!='W')
        {   puts("hey eso es ilegal");
            printf("valor en y de la pieza\n");
            scanf("%i",&y);
            printf("valor en x   de la pieza\n");
            scanf("%i",&x);

            
            printf("nueva  coordenada y\n");
            scanf("%i",&y1);
            printf("nueva coordenada x\n");
            scanf("%i",&x1);

        }
            
        if(board2[y][x]->piece_type=='p'){
           result= White_Pawn(board2[y][x],x1,y1,board2);
            new_game.turn=2;


        }
        if(board2[y][x]->piece_type=='t'){

            result=torre(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }

        if(board2[y][x]->piece_type=='c'){

            result=caballo(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }

        
        if(board2[y][x]->piece_type=='a'){

            result=alfil(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }
        if(board2[y][x]->piece_type=='k'){

           result=king(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }
       
        


        printf("el resultado fue %i\n",result);

    }
    if(new_game.turn==2){
        puts("Turno de las negras \n");
        
        
        printf("valor en y de la pieza\n");
        scanf("%i",&y);
        printf("valor en x   de la pieza\n");
        scanf("%i",&x);


        printf("nueva  coordenada y\n");
        scanf("%i",&y1);
        printf("nueva coordenada x\n");
        scanf("%i",&x1);


        while (board2[y][x]==NULL||board2[y][x]->color!='B')
        {   puts("hey eso es ilegal");
            printf("valor en y de la pieza\n");
            scanf("%i",&y);
            printf("valor en x   de la pieza\n");
            scanf("%i",&x);


            printf("nueva  coordenada y\n");
            scanf("%i",&y1);
            printf("nueva coordenada x\n");
            scanf("%i",&x1);


        }
            
        if(board2[y][x]->piece_type=='P'){
            result=Black_Pawn(board2[y][x],x1,y1,board2);
            new_game.turn=2;


        }

         if(board2[y][x]->piece_type=='T'){

            result=torre(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }

        if(board2[y][x]->piece_type=='C'){

            result=caballo(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }

        
        if(board2[y][x]->piece_type=='A'){

            result=alfil(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }
        if(board2[y][x]->piece_type=='K'){

           result=king(board2[y][x],x1,y1,board2);
            new_game.turn=2;

        }

        printf("el resultado fue %i",result);

    }









}









/*
board2[6][3]->piece_type='a';

print_board(board2);

 
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

int a=alfil(board2[y][x],x1,y1,board2);

printf("la opcion fue %i\n",a);




*/



    
}