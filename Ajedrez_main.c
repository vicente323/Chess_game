#include"Ajedrez_fun.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main(){

// /"Siempre existe una solución y si crees que no existe, solo es que la desconoces"-Show 2020


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

board2[6][7]=NULL;

//board2[6][0]=NULL;
board2[6][4]=NULL;

//board2[0][0]=NULL;
board2[1][0]=NULL;
board2[6][6]=NULL;
board2[1][0]=NULL;
board2[1][4]=NULL;

//board2[2][7]=board2[1][1];



 while(new_game.turn>0){
        print_board(board2);
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
                printf("valor en y de la pieza\n");
                scanf("%i",&y);
                printf("valor en x   de la pieza\n");
                scanf("%i",&x);

                printf("nueva  coordenada y\n");
                scanf("%i",&y1);
                printf("nueva coordenada x\n");
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
            new_game.turn=1;
            puts("Turno de las negras \n");

            printf("valor en y de la pieza\n");
            scanf("%i",&y);
            printf("valor en x   de la pieza\n");
            scanf("%i",&x);

            printf("nueva  coordenada y\n");
            scanf("%i",&y1);
            printf("nueva coordenada x\n");
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
                            printf("valor en y de la pieza\n");
                            scanf("%i",&y);
                            printf("valor en x   de la pieza\n");
                            scanf("%i",&x);

                            printf("nueva  coordenada y\n");
                            scanf("%i",&y1);
                            printf("nueva coordenada x\n");
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
                        }  





            printf("el resultado fue %i\n",result);
            swap(board2, y, x,  y1, x1,  result );
            piece_count(board2,&new_game);
        }




       
    }


 }