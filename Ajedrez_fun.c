
#include"Ajedrez_fun.h"

#include<stdio.h>
#include<stdlib.h>



int torre(struct piece * piece, int x, int y, struct piece ***board2)
        {

            int valid_mvs_izq=0;
           int filas=piece->y_axis;
           int columnas=piece->x_axis;
           int n=1;
           //Horizontal
           while(board2[filas][columnas-n]==NULL && columnas-n>=0) {
               valid_mvs_izq++;
               if (board2[filas][columnas - n] != NULL) {
                   if (board2[filas][columnas - n]->color != piece->color && board2[filas][columnas - n]->x_axis == x &&
                       board2[filas][columnas - n]->y_axis == y)
                       return 2;
                   if (board2[filas][columnas - n]->color == piece->color && board2[filas][columnas - n]->x_axis == x &&
                       board2[filas][columnas - n]->y_axis == y)
                       return 0;
               }
               n++;
               piece->mvs++;
           }
           if (valid_mvs_izq>=0 && valid_mvs_izq<=7 && y==piece->y_axis)
               return 1;
           n=1;
           int mov_derecha=0;
           while(board2[filas][columnas+n]==NULL && columnas+n<=7) {
                mov_derecha++;
                if (board2[filas][columnas + n] != NULL) {
                    if (board2[filas][columnas + n]->color != piece->color && board2[filas][columnas + n]->x_axis == x &&
                        board2[filas][columnas + n]->y_axis == y)
                        return 2;
                    if (board2[filas][columnas + n]->color == piece->color && board2[filas][columnas + n]->x_axis == x &&
                        board2[filas][columnas + n]->y_axis == y)
                        return 0;
                }
               n++;
               piece->mvs++;
            }
            if (mov_derecha>=0 && mov_derecha<=7 && y==piece->y_axis)
                return 1;
           //Vertical
           n=1;
           int mov_abajo=0;
            while(board2[filas-n][columnas]==NULL && filas-n>-1) {
                mov_abajo++;
                if (board2[filas-n][columnas] != NULL) {
                    if (board2[filas-n][columnas]->color != piece->color && board2[filas-n][columnas]->y_axis == y &&
                        board2[filas-n][columnas]->x_axis == x)
                        return 2;
                    if (board2[filas-n][columnas]->color == piece->color && board2[filas][columnas]->y_axis == y &&
                        board2[filas-n][columnas]->x_axis == x)
                        return 0;
                }
                n++;
                piece->mvs++;
            }
            if (mov_abajo>=0 && mov_abajo<=7 && x==piece->x_axis)
                return 1;
        n=1;
        int mov_arriba=0;
            while(board2[filas-n][columnas]==NULL && filas-n<=7) {
                mov_arriba++;
                if (board2[filas+n][columnas] != NULL) {
                    if (board2[filas+n][columnas]->color != piece->color && board2[filas+n][columnas]->y_axis == y &&
                        board2[filas+n][columnas]->x_axis == x)
                        return 2;
                    if (board2[filas+n][columnas]->color == piece->color && board2[filas][columnas]->y_axis == y &&
                        board2[filas+n][columnas]->x_axis == x)
                        return 0;
                }
                n++;
                piece->mvs++;
            }
            if (mov_arriba>=0 && mov_arriba<=7 && x==piece->x_axis)
                return 1;

        }



/////////////////////////////////////////////////////////////////////////////////////////

















int Move_Black_Pieces(struct piece * piece, int x ,int y,struct piece ***board2){



if(piece->piece_type=='P'){
            puts("la pieza es un peon Nibba ");
          
            if(y==piece->y_axis+1&&x==piece->x_axis+1 &&x>=0 && y>=0 && x<=7 && y<=7){
                        if(board2[y][x]==NULL)return 0;//commer derecha
                        if(board2[y][x]!=NULL && board2[y][x]->color !=piece->color)return 2;
                        if(board2[y][x]!=NULL && board2[y][x]->color ==piece->color)return 0;


                    }
            if(y==piece->y_axis+1&&x==piece->x_axis-1    &&x>=0 && y>=0 && x<=7 && y<=7){
                        if(board2[y][x]==NULL)return 0;//comer izquierda
                        if(board2[y][x]->color !=piece->color)return 2;
                        if(board2[y][x]->color ==piece->color)return 0;


                    }

            if(piece->mvs==0){
            
                if(y==piece->y_axis+2 && y>piece->y_axis && board2[y][x]==NULL && y<=7 && x==piece->x_axis ) return 1;
                if(y==piece->y_axis+1 && y>piece->y_axis && board2[y][x]==NULL && y<=7 && x==piece->x_axis) return 1;//dos movimientos si el peon no se ha movido
                
                else
                {
                    return 0;
                }
                
             }    

          
            if(piece->mvs>0){

                    if(y==piece->y_axis+1 &&y<piece->y_axis&& y<=7 && board2[y][x]==NULL && x==piece->x_axis)return 1;
                        
                    
                    else
                    {
                        return 0;
                    }

                    
                }

    

            
        }














}









void print_board(struct piece ***board2){
    
 for (int a=0; a<9; a++){
  
    puts("\n");
      printf("%iY",a );
    for(int b=0; b<8; b++){
        
        
       
        if(board2[a][b]==NULL){

            printf(" X- " );
        }
        else  if(a<8)
        {
                    printf(" %c- ",board2[a][b]->piece_type);

        }
        else if(a==8)
        {
                printf(" X%i " ,b);
            
            
        }
        
        
    }
}





}


int Move_white_Pieces(struct piece * piece, int x ,int y,struct piece ***board2){
    //Esta funcion recibe la referencia de una pieza y  verifica si la coordenada deseada es valida para moverse retorna 0 para movs no validos 1 para movs validos y 2 para comer piezas
   
   

        if(piece->piece_type=='p'){
            puts("la pieza es un peon blanco ");
            if(y==piece->y_axis-1&&x==piece->x_axis+1 &&x>=0 && y>=0 && x<=7 && y<=7){
                        if(board2[y][x]==NULL)return 0;//commer derecha
                        if(board2[y][x]!=NULL && board2[y][x]->color !=piece->color)return 2;
                        if(board2[y][x]!=NULL && board2[y][x]->color ==piece->color)return 0;


                    }
            if(y==piece->y_axis-1&&x==piece->x_axis-1    &&x>=0 && y>=0 && x<=7 && y<=7){
                        if(board2[y][x]==NULL)return 0;//comer izquierda
                        if(board2[y][x]->color !=piece->color)return 2;
                        if(board2[y][x]->color ==piece->color)return 0;

                    }

            if(piece->mvs==0){
            
                if(y==piece->y_axis-2 && y<piece->y_axis && board2[y][x]==NULL &&y>=0 &&x==piece->x_axis) return 1;
                if(y==piece->y_axis-1 && y<piece->y_axis && board2[y][x]==NULL &&y>=0 && x==piece->x_axis) return 1;//dos movimientos si el peon no se ha movido
                
                else
                {
                    return 0;
                }
                
             }    

          
            if(piece->mvs>0){

                    if(y==piece->y_axis-1 &&y<piece->y_axis&& y>=0 && board2[y][x]==NULL &&x==piece->x_axis)return 1;
                        
                    
                    else
                    {
                        return 0;
                    }

                    
                }

    

            
        }
        if(piece->piece_type=='c'){
















            
        }



        if(piece->piece_type=='t'){

























        }





        else{
            
                return 0;
            }
            



       



 }











void init_game( struct piece ***board2){

    //esta funcion recibe un apuntador triple o un arreglo de apuntadores dobles osea un arreglo de 2D que guarda referencias a nuestras piezas 




for (int a=0; a<8; a++){
 
    for(int b=0; b<8; b++){
       
       if (a==0&&b==0 || a==0&&b==7){

       struct piece * caster =malloc(sizeof(struct piece));
       caster->color='B';
       caster->piece_type='T';
       caster->mvs=0;
       caster->y_axis=a;
       caster->x_axis=b;
        *(board2[a]+b)=caster;//Torres
       }
       if(a==0&&b==1 || a==0&&b==6){
           struct piece * caster =malloc(sizeof(struct piece));
           caster->color='B';
           caster->piece_type='C';
           caster->mvs=0;//caballos 
           caster->y_axis=a;
           caster->x_axis=b;
           *(board2[a]+b)=caster;


           
       }
       if(a==0&&b==2 || a==0 && b==5){
            //arfiles 

            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->mvs=0;
            caster->piece_type='A';
            caster->y_axis=a;
            caster->x_axis=b;
             *(board2[a]+b)=caster;




       }
       if(a==0&&b==3 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->piece_type='K';
            caster->mvs=0;
            caster->y_axis=a;
            caster->x_axis=b;
            *(board2[a]+b)=caster; //rey

          
       }
       if(a==0&&b==4 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->piece_type='R';
            caster->mvs=0;
            caster->y_axis=a;
            caster->x_axis=b;
            *(board2[a]+b)=caster; //reyna

          
       }
        if(a==1){
             struct piece * caster =malloc(sizeof(struct piece));
             caster->color='B';
             caster->piece_type='P';
             caster->mvs=0;
             caster->y_axis=a;
             caster->x_axis=b;
             *(board2[a]+b)=caster; //peones




        }
        if(a==6){


             struct piece * caster =malloc(sizeof(struct piece));
             caster->color='W';
             caster->piece_type='p';
             caster->mvs=0;
             caster->y_axis=a;
             caster->x_axis=b;
             *(board2[a]+b)=caster; //peones

        }
        



       
        if (a==7&&b==0 || a==7&&b==7){

       struct piece * caster =malloc(sizeof(struct piece));
       caster->color='W';
       caster->piece_type='t';
       caster->mvs=0;
       caster->y_axis=a;
       caster->x_axis=b;
        *(board2[a]+b)=caster;//Torres
       }

         if(a==7&&b==1 || a==7&&b==6){
           struct piece * caster =malloc(sizeof(struct piece));
           caster->color='W';
           caster->piece_type='c';
           caster->mvs=0;//caballos 
           caster->y_axis=a;
           caster->x_axis=b;
           *(board2[a]+b)=caster;


         
       }

       if(a==7&&b==2 || a==7 && b==5){
            //arfiles 

            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->mvs=0;
            caster->piece_type='a';
            caster->y_axis=a;
            caster->x_axis=b;
             *(board2[a]+b)=caster;




       }
    if(a==7&&b==3 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->piece_type='k';
            caster->mvs=0;
            caster->y_axis=a;
             caster->x_axis=b;
            *(board2[a]+b)=caster; //reye

          
       }
        if(a==7&&b==4 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->piece_type='r';
            caster->mvs=0;
            caster->y_axis=a;
             caster->x_axis=b;
            *(board2[a]+b)=caster; //reyna
          
       }

    if(a==2||a==3||a==4||a==5){
    *(board2[a]+b)=NULL;


    }



       
  
        
        
        
    }
}





/*for (int a=0; a<9; a++){
  
    puts("\n");
      printf("%iY",a );
    for(int b=0; b<8; b++){
        
        
       
        if(board2[a][b]==NULL){

            printf(" X- " );
        }
        else  if(a<8)
        {
                    printf(" %c- ",board2[a][b]->piece_type);

        }
        else if(a==8)
        {
                printf(" X%i " ,b);
            
            
        }
        
        
    }
}
*/






}