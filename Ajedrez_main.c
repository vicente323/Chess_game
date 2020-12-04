#include"Ajedrez_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main(){

// /"Siempre existe una solución y si crees que no existe, solo es que la desconoces"-Show 2020

struct piece **  board1[8];
struct piece **  board2[8];

struct piece *ap0[8];
struct piece *ap1[8];
struct piece *ap2[8];
struct piece *ap3[8];   
struct piece *ap4[8];
struct piece *ap5[8];
struct piece *ap6[8];
struct piece *ap7[8];
//-----------------------------------

struct piece *bp0[8];
struct piece *bp1[8];
struct piece *bp2[8];
struct piece *bp3[8];   
struct piece *bp4[8];
struct piece *bp5[8];
struct piece *bp6[8];
struct piece *bp7[8];
board1[0]=bp0;
board1[1]=bp1;
board1[2]=bp2;
board1[3]=bp3;
board1[4]=bp4;
board1[5]=bp5;
board1[6]=bp6;
board1[7]=bp7;

board2[0]=ap0;
board2[1]=ap1;
board2[2]=ap2;
board2[3]=ap3;
board2[4]=ap4;
board2[5]=ap5;
board2[6]=ap6;
board2[7]=ap7;
struct gamestate new_game;

struct piece * blancas[16];
struct piece * negras[16];


new_game.blancas=blancas;
new_game.Negras=negras;
new_game.turn=1;


init_game(board2);


int x=0;
int y=0;
int x1=0;
int y1=0;

int opt=0;
int result=0;

//board2[6][7]=NULL;

//board2[6][0]=NULL;
board2[6][3]=NULL;

//board2[0][0]=NULL;
board2[1][4]=NULL;
//board2[6][3]=NULL;
board2[1][3]=NULL;
board2[1][7]=NULL;

//board2[2][7]=board2[1][1];

//clean_board(board2);
piece_count(board2,&new_game);
int count=0;

/*while (new_game.Negras[count]!=NULL && count<16)
{   

  
    printf("%i",count);
    printf("pieza %c\n",new_game.Negras[count]->piece_type);
    count++;

   
    
    
 
}*/
init_game(board1);

clean_board(board1);

//print_board(board1);

 while(new_game.turn>0){
     


        if(new_game.turn==1){
            
            puts("\n");
            puts("\n");
            puts("\n");
            puts("\n");
            puts("\n");
            print_board(board2);
            puts("\n");
            int sf=is_king_safe(board2,&new_game,new_game.turn);
   /* if (sf==3)
    {       clean_board(board1);
            coppy_board(board2,board1);
            puts("tu rey esta en haque\n");
            struct gamestate secondary;
            struct piece * blancas[16];
            struct piece * negras[16];
            secondary.blancas=blancas;
            secondary.Negras=negras;















































    }*/
    





   
            puts("Turno de las blancas \n");
            printf("el estado del rey es %i\n",sf);
            puts("valor en y de la pieza\n");
            scanf("%i",&y);
            puts("valor en x   de la pieza\n");
            scanf("%i",&x);

            puts("nueva  coordenada y\n");
            scanf("%i",&y1);
            puts("nueva coordenada x\n");
            scanf("%i",&x1);
            
            
     
            
             if(board2[y][x]!=NULL&&board2[y][x]->color=='W'){

                        if(board2[y][x]->piece_type=='p'){
                            result= White_Pawn(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                             printf("%i es el resultado del peon",result);

                        }
                        if(board2[y][x]->piece_type=='t'){
                            result=Torre(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                            printf("%i es el resultado de la torre\n",result);
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
                        if (board2[y][x]->piece_type=='r')
                        {
                            result=Reyna(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                        }
                        




                }



            while (board2[y][x]==NULL||board2[y][x]->color!='W'||result==0)
            {   puts("hey eso es ilegal");
                puts("valor en y de la pieza\n");
                scanf("%i",&y);
                puts("valor en x   de la pieza\n");
                scanf("%i",&x);

                puts("nueva  coordenada y\n");
                scanf("%i",&y1);
                puts("nueva coordenada x\n");
                scanf("%i",&x1);
                if(board2[y][x]!=NULL&&board2[y][x]->color=='W'){

                        if(board2[y][x]->piece_type=='p'){
                            result= White_Pawn(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                           

                        }
                        if(board2[y][x]->piece_type=='t'){
                            result=Torre(board2[y][x],x1,y1,board2);
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
                        if (board2[y][x]->piece_type=='r')
                        {
                            result=Reyna(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                        }





                }
            }  
            
    

            printf("el resultado fue %i\n",result);
            swap(board2, y, x,  y1, x1,  result );
             piece_count(board2,&new_game);
        }
        if(new_game.turn==2){
            
            puts("\n");
            puts("\n");
            puts("\n");
            puts("\n");
            puts("\n");
            print_board(board2);
            puts("\n");
            int sf=is_king_safe(board2,&new_game,new_game.turn);
            puts("Turno de las negras \n");
            printf("el estado del rey es %i\n",sf);


            puts("valor en y de la pieza\n");
            scanf("%i",&y);
            puts("valor en x   de la pieza\n");
            scanf("%i",&x);

            puts("nueva  coordenada y\n");
            scanf("%i",&y1);
            puts("nueva coordenada x\n");
            scanf("%i",&x1);
               
             if(board2[y][x]!=NULL&&board2[y][x]->color=='B'){

                        if(board2[y][x]->piece_type=='P'){
                            result= Black_Pawn(board2[y][x],x1,y1,board2);
                            

                        }
                        if(board2[y][x]->piece_type=='T'){
                            result=Torre(board2[y][x],x1,y1,board2);
                            
                        }
                        if(board2[y][x]->piece_type=='C'){
                            result=caballo(board2[y][x],x1,y1,board2);
                            
                        }

                        if(board2[y][x]->piece_type=='A'){
                            result=alfil(board2[y][x],x1,y1,board2);
                            
                        }
                        if(board2[y][x]->piece_type=='K'){
                            result=king(board2[y][x],x1,y1,board2);
                            
                        }
                        if (board2[y][x]->piece_type=='R')
                        {
                            result=Reyna(board2[y][x],x1,y1,board2);
                            new_game.turn=2;
                        }





                }






                    while (board2[y][x]==NULL||board2[y][x]->color!='B'||result==0)
                        {   puts("hey eso es ilegal");
                            puts("valor en y de la pieza\n");
                            scanf("%i",&y);
                            puts("valor en x   de la pieza\n");
                            scanf("%i",&x);

                            puts("nueva  coordenada y\n");
                            scanf("%i",&y1);
                            puts("nueva coordenada x\n");
                            scanf("%i",&x1);
                            if(board2[y][x]!=NULL&&board2[y][x]->color=='B'){

                                    if(board2[y][x]->piece_type=='P'){
                                        result= Black_Pawn(board2[y][x],x1,y1,board2);
                                       

                                    }
                                    if(board2[y][x]->piece_type=='T'){
                                        result=Torre(board2[y][x],x1,y1,board2);
                                    }
                                    if(board2[y][x]->piece_type=='C'){
                                        result=caballo(board2[y][x],x1,y1,board2);
                                        
                                    }

                                    if(board2[y][x]->piece_type=='A'){
                                        result=alfil(board2[y][x],x1,y1,board2);
                                      
                                    }
                                    if(board2[y][x]->piece_type=='K'){
                                        result=king(board2[y][x],x1,y1,board2);
                                        
                                    }
                                    if (board2[y][x]->piece_type=='R')
                                    {
                                        result=Reyna(board2[y][x],x1,y1,board2);
                                       
                                    }
                                                





                            }
                        }  





            printf("el resultado fue %i\n",result);
            swap(board2, y, x,  y1, x1,  result );
            piece_count(board2,&new_game);
             new_game.turn=1;
        }




       
    }


 }