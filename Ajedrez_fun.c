
#include"Ajedrez_fun.h"

#include<stdio.h>
#include<stdlib.h>



void piece_count(struct piece ***board2,struct gamestate * game){

int b=0;
int n=0;
for(int u=0; u<16; u++){

    game->Negras[u]=NULL;
    game->blancas[u]=NULL;

}

for(int x=0; x<8; x++){

    for(int y=0; y<8; y++){

        if(board2[x][y]!=NULL){

            if(board2[x][y]->color=='W'){

                game->blancas[b]=board2[x][y];
                b++;




            }
            if(board2[x][y]->color=='B'){


                game->Negras[n]=board2[x][y];
                n++;

            }




        }



    }




}





}

void swap(struct piece ***board2,int y, int x, int ny, int nx, int result ){
    struct piece * help;

    if(result==1){
            board2[y][x]->mvs++;
            help=board2[y][x];
            board2[ny][nx]=help;
            board2[ny][nx]->x_axis=nx;
            board2[ny][nx]->y_axis=ny;
            board2[y][x]=NULL;


    }
    if (result==2){
           board2[y][x]->mvs++;
           help=board2[ny][nx];
           board2[ny][nx]=board2[y][x];
           board2[ny][nx]->x_axis=nx;
            board2[ny][nx]->y_axis=ny;
           board2[y][x]=NULL;
           free(help);


    }


}


 int Torre(struct piece * piece, int x, int y, struct piece *** board2){

            int filasT=piece->y_axis;
            int columnaT=piece->x_axis;
         
            if(x==piece->x_axis&&  y<piece->y_axis &&   y<=7){
             
                int conto=0;
                filasT=filasT-1;
                int bandera=0;

                while (bandera==0)
                    {   
                        if(filasT>=0){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                filasT--; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                //conto++;
                            }
                        
                            
                        }
                        
                        if(filasT == -1)bandera=1;
                    }
                    int max_idx_y=piece->y_axis-conto;
                   
                    int ret2=0;
                    if (board2[max_idx_y-1][columnaT]!=NULL){
                       
                        ret2=conto+1;
                        int h=ret2;
                        ret2=piece->y_axis-h;
                        
                        }

                   

                    
                    if(x==piece->x_axis && y>=max_idx_y)return 1;
                    if(board2[ret2][x]!=NULL){
                        
                         if(x==piece->x_axis && y==ret2  && board2[ret2][x]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                   
                    else
                    {
                        return 0;
                    }
                    


                


            }
            if(x==piece->x_axis&&  y>piece->y_axis &&   y<=7){
                

                int conto=0;
                filasT=filasT+1;
                int bandera=0;

                while (bandera==0)
                    {   
                        if(filasT>=0&&filasT<=7){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                filasT++; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                //conto++;
                            }
                            
                        
                            
                        }
                        
                        if(filasT ==8)bandera=1;
                    }
                int max_idx_y=piece->x_axis+conto;
                  
                  int ret2=0;
                    if (board2[max_idx_y+1][columnaT]!=NULL){
                      
                        
                        ret2=max_idx_y+1;
                      
                        }
                     
                   
                    if(x==piece->x_axis && y<=max_idx_y)return 1;

                    if(board2[ret2][x]!=NULL){
                       
                         if(x==piece->x_axis && y==ret2  && board2[ret2][x]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                    else
                    {
                        return 0;
                    }
                    

                        
                


            }





            if(y==piece->y_axis&&  x<piece->x_axis &&   x<=7){
              

                    int conto=0;
                    int bandera =0;
                    columnaT=columnaT-1;

                    while (bandera==0)
                    {   
                        if(columnaT>=0){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                columnaT--; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                
                            }
                           
                            
                        }
                        
                        if(columnaT ==-1)bandera=1;
                    }
                    int max_idx_x=piece->x_axis-conto;
                    int ret2=0;
                   
              
                    if (board2[filasT][columnaT]!=NULL){
                           
                                ret2=columnaT-1;
                                
                                }
                   
                    if(y==piece->y_axis && x>=max_idx_x)return 1;
                                

                     if(board2[y][ret2]!=NULL){
                       
                         if(y==piece->y_axis && x==ret2  && board2[y][ret2]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                     else
                    {
                        return 0;
                    }






            }






                    if(y==piece->y_axis&&  x>piece->x_axis && x<=7){
                           

                                    int conto=0;
                                    int bandera =0;
                                    columnaT=columnaT+1;

                                    while (bandera==0)
                                    {   
                                        if(columnaT>=0 &&columnaT<=7){
                                            if (board2[filasT][columnaT]==NULL)
                                            {
                                                columnaT++; 
                                                conto++;
                                            }
                                            if (board2[filasT][columnaT]!=NULL)
                                            {
                                                bandera=1;
                                                
                                            }
                                            
                                            
                                        }
                                        
                                        if(columnaT ==8)bandera=1;
                                    }
                                    int max_idx_x=piece->x_axis+conto;
                                    int ret2=0;
                                  

                                    if (board2[filasT][columnaT]!=NULL){
                                                ret2=columnaT;
                                                }
                                    if(y==piece->y_axis && x<=max_idx_x)return 1;
                                                

                                    if(board2[y][ret2]!=NULL){
                                        if(y==piece->y_axis && x==ret2  && board2[y][ret2]->color!=piece->color)return 2;
                                        else
                                        {
                                            return 0;
                                        }
                                        
                                    }
                                    else
                                    {
                                        return 0;
                                    }






                            }
                            else
                            {
                                return 0;
                            }
                            























                


}














int Reyna(struct piece * piece, int x ,int y,struct piece ***board2){


          int filasT=piece->y_axis;
            int columnaT=piece->x_axis;
         
            if(x==piece->x_axis&&  y<piece->y_axis &&   y<=7){
             
                int conto=0;
                filasT=filasT-1;
                int bandera=0;

                while (bandera==0)
                    {   
                        if(filasT>=0){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                filasT--; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                //conto++;
                            }
                        
                            
                        }
                        
                        if(filasT == -1)bandera=1;
                    }
                    int max_idx_y=piece->y_axis-conto;
                   
                    int ret2=0;
                    if (board2[max_idx_y-1][columnaT]!=NULL){
                       
                        ret2=conto+1;
                        int h=ret2;
                        ret2=piece->y_axis-h;
                        
                        }

                   

                    
                    if(x==piece->x_axis && y>=max_idx_y)return 1;
                    if(board2[ret2][x]!=NULL){
                        
                         if(x==piece->x_axis && y==ret2  && board2[ret2][x]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                   
                    else
                    {
                        return 0;
                    }
                    


                


            }
            if(x==piece->x_axis&&  y>piece->y_axis &&   y<=7){
                

                int conto=0;
                filasT=filasT+1;
                int bandera=0;

                while (bandera==0)
                    {   
                        if(filasT>=0&&filasT<=7){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                filasT++; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                //conto++;
                            }
                            
                        
                            
                        }
                        
                        if(filasT ==8)bandera=1;
                    }
                int max_idx_y=piece->x_axis+conto;
                  
                  int ret2=0;
                    if (board2[max_idx_y+1][columnaT]!=NULL){
                      
                        
                        ret2=max_idx_y+1;
                      
                        }
                     
                   
                    if(x==piece->x_axis && y<=max_idx_y)return 1;

                    if(board2[ret2][x]!=NULL){
                       
                         if(x==piece->x_axis && y==ret2  && board2[ret2][x]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                    else
                    {
                        return 0;
                    }
                    

                        
                


            }





            if(y==piece->y_axis&&  x<piece->x_axis &&   x<=7){
              

                    int conto=0;
                    int bandera =0;
                    columnaT=columnaT-1;

                    while (bandera==0)
                    {   
                        if(columnaT>=0){
                            if (board2[filasT][columnaT]==NULL)
                            {
                                columnaT--; 
                                conto++;
                            }
                            if (board2[filasT][columnaT]!=NULL)
                            {
                                bandera=1;
                                
                            }
                           
                            
                        }
                        
                        if(columnaT ==-1)bandera=1;
                    }
                    int max_idx_x=piece->x_axis-conto;
                    int ret2=0;
                   
              
                    if (board2[filasT][columnaT]!=NULL){
                           
                                ret2=columnaT-1;
                                
                                }
                   
                    if(y==piece->y_axis && x>=max_idx_x)return 1;
                                

                     if(board2[y][ret2]!=NULL){
                       
                         if(y==piece->y_axis && x==ret2  && board2[y][ret2]->color!=piece->color)return 2;
                         else
                         {
                             return 0;
                         }
                         
                    }
                     else
                    {
                        return 0;
                    }






            }






                    if(y==piece->y_axis&&  x>piece->x_axis && x<=7){
                           

                                    int conto=0;
                                    int bandera =0;
                                    columnaT=columnaT+1;

                                    while (bandera==0)
                                    {   
                                        if(columnaT>=0 &&columnaT<=7){
                                            if (board2[filasT][columnaT]==NULL)
                                            {
                                                columnaT++; 
                                                conto++;
                                            }
                                            if (board2[filasT][columnaT]!=NULL)
                                            {
                                                bandera=1;
                                                
                                            }
                                            
                                            
                                        }
                                        
                                        if(columnaT ==8)bandera=1;
                                    }
                                    int max_idx_x=piece->x_axis+conto;
                                    int ret2=0;
                                  

                                    if (board2[filasT][columnaT]!=NULL){
                                                ret2=columnaT;
                                                }
                                    if(y==piece->y_axis && x<=max_idx_x)return 1;
                                                

                                    if(board2[y][ret2]!=NULL){
                                        if(y==piece->y_axis && x==ret2  && board2[y][ret2]->color!=piece->color)return 2;
                                        else
                                        {
                                            return 0;
                                        }
                                        
                                    }
                                    else
                                    {
                                        return 0;
                                    }






                            }






















































































          if(piece->x_axis<x && piece->y_axis>y){
                
                puts("entro al if derecha up");

            int bandera=0;
            int filas=piece->y_axis-1;
            int columna=piece->x_axis+1;
            int conto=0;
            while (bandera==0){
                    

                    if(filas>=0 &&columna<=7){
                      
                                printf("cont:%i\n",conto);
                                if (board2[filas][columna]==NULL){
                                        columna++; 
                                        filas--;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8 || filas==-1)bandera=1;

            }
            printf("filas:%i\n",filas);
            printf("columnas:%i\n",columna);
            int max_dx_y=piece->y_axis-conto;
            int max_dx_x=piece->x_axis+conto;
            printf("max idx y %i\n",max_dx_y);
            printf("max idx x %i\n",max_dx_x);
            int ret2x=0;
            int ret2y=0;
            if(max_dx_x<7 && max_dx_y>0){
                if(board2[max_dx_y-1][max_dx_x+1]!=NULL){
                    ret2x=max_dx_x+1;
                    ret2y=max_dx_y-1;
                }
            }
            printf("rety %i\n",ret2y);
            printf("retx %i\n",ret2x);
            if(x<=max_dx_x && y>=max_dx_y)return 1;

            if (board2[ret2y][ret2x]!=NULL)
            {   
                if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                else
                {
                    return 0;
                }
                
               
            }
            else
            {
                return 0;
            }
            
        
            

        
        }
        if(piece->y_axis<y && piece->x_axis<x){
            puts("entro a la derecha para abajo");
            int bandera=0;
            int filas=piece->y_axis+1;
            int columna=piece->x_axis+1;
            int conto=0;
            
            while (bandera==0){
                    

                    if(filas<=7 &&columna<=7){
                      
                                //printf("cont:%i\n",conto);
                                if (board2[filas][columna]==NULL){
                                        columna++; 
                                        filas++;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8 || filas==8)bandera=1;

            }

            printf("filas:%i\n",filas);
            printf("columnas:%i\n",columna);
            int max_dx_y=piece->y_axis+conto;
            int max_dx_x=piece->x_axis+conto;
            printf("max idx y %i\n",max_dx_y);
            printf("max idx x %i\n",max_dx_x);
            int ret2x=0;
            int ret2y=0;

            if(max_dx_y<7 && max_dx_x<7){
                if (board2[max_dx_y+1][max_dx_x+1]!=NULL)
                {
                    ret2x=max_dx_x+1;
                    ret2y=max_dx_y+1;
                }
                
            }
            printf("rety %i\n",ret2y);
            printf("retx %i\n",ret2x);
            if(x<=max_dx_x && x>0 && y<=max_dx_y &&y>0)return 1;
            if (board2[ret2y][ret2x]!=NULL){
                if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                else
                {
                    return 0;
                }

            }


        }

        if (x<piece->x_axis && y>piece->y_axis )
        {
                puts("entro  a la izquierda abajo");
                int bandera=0;
                int filas=piece->y_axis+1;
                int columna=piece->x_axis-1;
                int conto=0;
                while (bandera==0){
               

                    if(filas<=7 &&columna>=0){
                        
                      
                                if (board2[filas][columna]==NULL){
                                        columna--; 
                                        filas++;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                    printf("Encontre algo no Null\n");
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8|| filas==-1)bandera=1;

                 }


                 printf("filas:%i\n",filas);
                 printf("columnas:%i\n",columna);
                 int max_dx_y=piece->y_axis+conto;
                 int max_dx_x=piece->x_axis-conto;
                 int ret2x=0;
                 int ret2y=0;
                 if(max_dx_y<7 && max_dx_x>0){
                    if (board2[max_dx_y+1][max_dx_x-1]!=NULL)
                    {
                        ret2x=max_dx_x-1;
                        ret2y=max_dx_y+1;
                    }
                
                 }
                 printf("rety %i\n",ret2y);
                 printf("retx %i\n",ret2x);
                 printf("max idx x %i\n",max_dx_x);
                 printf("max idx y %i\n",max_dx_y);
                 printf("contador %i\n",conto);

                 if(x>=max_dx_x && y<=max_dx_y )return 1;
                 if (board2[ret2y][ret2x]!=NULL){

                        if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                        else
                        {
                            return 0;
                        }


                 }
                 else
                 {
                     return 0;
                 }
                 
                    









        }
        if (x<piece->x_axis && y<piece->y_axis)
        {       puts("entro  a la izquierda arriba");
                int bandera=0;
                int filas=piece->y_axis-1;
                int columna=piece->x_axis-1;
                int conto=0;




                while (bandera==0){
               

                    if(filas>=0 &&columna>=0){
                        
                      
                                if (board2[filas][columna]==NULL){
                                        columna--; 
                                        filas--;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                    printf("Encontre algo no Null\n");
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==-1|| filas==-1)bandera=1;

                 }
                 printf("filas:%i\n",filas);
                 printf("columnas:%i\n",columna);
                 int max_dx_y=piece->y_axis-conto;
                 int max_dx_x=piece->x_axis-conto;
                 int ret2x=0;
                 int ret2y=0;
                 if(max_dx_y>0 && max_dx_x>0){
                    if (board2[max_dx_y-1][max_dx_x-1]!=NULL)
                    {
                        ret2x=max_dx_x-1;
                        ret2y=max_dx_y-1;
                    }
                
                 }
                 printf("rety %i\n",ret2y);
                 printf("retx %i\n",ret2x);
                 printf("max idx x %i\n",max_dx_x);
                 printf("max idx y %i\n",max_dx_y);
                 printf("contador %i\n",conto);
                 if(x>=max_dx_x && y>=max_dx_y )return 1;
                 if (board2[ret2y][ret2x]!=NULL){

                        if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                        else
                        {
                            return 0;
                        }


                 }
                else
                {
                    return 0;
                }
                














        }
        


        else
        {
            return 0;
        }
        


















































}





















int alfil(struct piece * piece, int x, int y, struct piece *** board2){
    
        if(piece->x_axis<x && piece->y_axis>y){
                
                puts("entro al if derecha up");

            int bandera=0;
            int filas=piece->y_axis-1;
            int columna=piece->x_axis+1;
            int conto=0;
            while (bandera==0){
                    

                    if(filas>=0 &&columna<=7){
                      
                                printf("cont:%i\n",conto);
                                if (board2[filas][columna]==NULL){
                                        columna++; 
                                        filas--;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8 || filas==-1)bandera=1;

            }
            printf("filas:%i\n",filas);
            printf("columnas:%i\n",columna);
            int max_dx_y=piece->y_axis-conto;
            int max_dx_x=piece->x_axis+conto;
            printf("max idx y %i\n",max_dx_y);
            printf("max idx x %i\n",max_dx_x);
            int ret2x=0;
            int ret2y=0;
            if(max_dx_x<7 && max_dx_y>0){
                if(board2[max_dx_y-1][max_dx_x+1]!=NULL){
                    ret2x=max_dx_x+1;
                    ret2y=max_dx_y-1;
                }
            }
            printf("rety %i\n",ret2y);
            printf("retx %i\n",ret2x);
            if(x<=max_dx_x && y>=max_dx_y)return 1;

            if (board2[ret2y][ret2x]!=NULL)
            {   
                if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                else
                {
                    return 0;
                }
                
               
            }
            else
            {
                return 0;
            }
            
        
            

        
        }
        if(piece->y_axis<y && piece->x_axis<x){
            puts("entro a la derecha para abajo");
            int bandera=0;
            int filas=piece->y_axis+1;
            int columna=piece->x_axis+1;
            int conto=0;
            
            while (bandera==0){
                    

                    if(filas<=7 &&columna<=7){
                      
                                //printf("cont:%i\n",conto);
                                if (board2[filas][columna]==NULL){
                                        columna++; 
                                        filas++;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8 || filas==8)bandera=1;

            }

            printf("filas:%i\n",filas);
            printf("columnas:%i\n",columna);
            int max_dx_y=piece->y_axis+conto;
            int max_dx_x=piece->x_axis+conto;
            printf("max idx y %i\n",max_dx_y);
            printf("max idx x %i\n",max_dx_x);
            int ret2x=0;
            int ret2y=0;

            if(max_dx_y<7 && max_dx_x<7){
                if (board2[max_dx_y+1][max_dx_x+1]!=NULL)
                {
                    ret2x=max_dx_x+1;
                    ret2y=max_dx_y+1;
                }
                
            }
            printf("rety %i\n",ret2y);
            printf("retx %i\n",ret2x);
            if(x<=max_dx_x && x>0 && y<=max_dx_y &&y>0)return 1;
            if (board2[ret2y][ret2x]!=NULL){
                if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                else
                {
                    return 0;
                }

            }


        }

        if (x<piece->x_axis && y>piece->y_axis )
        {
                puts("entro  a la izquierda abajo");
                int bandera=0;
                int filas=piece->y_axis+1;
                int columna=piece->x_axis-1;
                int conto=0;
                while (bandera==0){
               

                    if(filas<=7 &&columna>=0){
                        
                      
                                if (board2[filas][columna]==NULL){
                                        columna--; 
                                        filas++;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                    printf("Encontre algo no Null\n");
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==8|| filas==-1)bandera=1;

                 }


                 printf("filas:%i\n",filas);
                 printf("columnas:%i\n",columna);
                 int max_dx_y=piece->y_axis+conto;
                 int max_dx_x=piece->x_axis-conto;
                 int ret2x=0;
                 int ret2y=0;
                 if(max_dx_y<7 && max_dx_x>0){
                    if (board2[max_dx_y+1][max_dx_x-1]!=NULL)
                    {
                        ret2x=max_dx_x-1;
                        ret2y=max_dx_y+1;
                    }
                
                 }
                 printf("rety %i\n",ret2y);
                 printf("retx %i\n",ret2x);
                 printf("max idx x %i\n",max_dx_x);
                 printf("max idx y %i\n",max_dx_y);
                 printf("contador %i\n",conto);

                 if(x>=max_dx_x && y<=max_dx_y )return 1;
                 if (board2[ret2y][ret2x]!=NULL){

                        if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                        else
                        {
                            return 0;
                        }


                 }
                 else
                 {
                     return 0;
                 }
                 
                    









        }
        if (x<piece->x_axis && y<piece->y_axis)
        {       puts("entro  a la izquierda arriba");
                int bandera=0;
                int filas=piece->y_axis-1;
                int columna=piece->x_axis-1;
                int conto=0;




                while (bandera==0){
               

                    if(filas>=0 &&columna>=0){
                        
                      
                                if (board2[filas][columna]==NULL){
                                        columna--; 
                                        filas--;
                                        conto++;
                                            }
                                if (board2[filas][columna]!=NULL){
                                    printf("Encontre algo no Null\n");
                                            bandera=1;
                                                            
                                            }
                                                        
                                                        
                                }
                            
                    if(columna==-1|| filas==-1)bandera=1;

                 }
                 printf("filas:%i\n",filas);
                 printf("columnas:%i\n",columna);
                 int max_dx_y=piece->y_axis-conto;
                 int max_dx_x=piece->x_axis-conto;
                 int ret2x=0;
                 int ret2y=0;
                 if(max_dx_y>0 && max_dx_x>0){
                    if (board2[max_dx_y-1][max_dx_x-1]!=NULL)
                    {
                        ret2x=max_dx_x-1;
                        ret2y=max_dx_y-1;
                    }
                
                 }
                 printf("rety %i\n",ret2y);
                 printf("retx %i\n",ret2x);
                 printf("max idx x %i\n",max_dx_x);
                 printf("max idx y %i\n",max_dx_y);
                 printf("contador %i\n",conto);
                 if(x>=max_dx_x && y>=max_dx_y )return 1;
                 if (board2[ret2y][ret2x]!=NULL){

                        if (x==ret2x&&y==ret2y&& board2[ret2y][ret2x]->color!=piece->color)return 2;
                        else
                        {
                            return 0;
                        }


                 }
                else
                {
                    return 0;
                }
                














        }
        


        else
        {
            return 0;
        }
        






 }











int Black_Pawn(struct piece * piece, int x ,int y,struct piece ***board2){



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

void is_king_safe(struct piece ***board2,struct gamestate * game, int opt){

int count=0;
        if(opt==1){
            while (count<16||game->Negras[count]!=NULL)
            {

                count++;
                /* code */
            }
            




        }








    
}






void print_board(struct piece ***board2 ){
    
 for (int a=0; a<9; a++){
  
    puts("\n");
      printf("%iY",a );
    for(int b=0; b<8; b++){
        
        if (a<8){
       
        if(board2[a][b]==NULL&&a<8){

            printf(" X- ");
        }
        else  if(a<8&&board2[a][b]!=NULL){
        
            printf(" %c- ",board2[a][b]->piece_type);   
            
                    
            
            }
                    
                    
            
                    
                    
    
                    
                    

       
        
        }

        if(a==8)
        {
                printf(" X%i " ,b);
            
            
        }
        
        
    }
}





}


int White_Pawn(struct piece * piece, int x ,int y,struct piece ***board2){
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



 }



int caballo(struct piece * piece, int x ,int y,struct piece ***board2){
    
        if(piece->piece_type=='c'|| piece->piece_type=='C'){
              
                printf("la pieza es un c\n");
            if(x>7 ||x<0 || y>7|| y<0)return 0;  
                          
                
                

            if(x==piece->x_axis-2&& y==piece->y_axis-1){
                
                
                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }

 
                
                }
            if(x==piece->x_axis+1 && y==piece->y_axis-2){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }



            }


            if(x==piece->x_axis-1 && y==piece->y_axis-2){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->piece_type!=piece->piece_type)return 2;
                }



            }
            if(x==piece->x_axis-2 && y==piece->y_axis+1){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }



            }
            if(x==piece->x_axis-2 && y==piece->y_axis-1){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }



            }
            if(x==piece->x_axis+2 && y==piece->y_axis-1){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }



            }

              if(x==piece->x_axis+2 && y==piece->y_axis+1){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }



              }

              if(x==piece->x_axis+1 && y==piece->y_axis+2){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2; }
               
              }


            
              if(x==piece->x_axis-1 && y==piece->y_axis+2){

                if(board2[y][x]==NULL)return 1;
                if(board2[y][x]!=NULL){ 
                    if(board2[y][x]->color==piece->color)return 0;
                    if(board2[y][x]->color!=piece->color)return 2;
                }




              }

      



    }

          

 
}



int king(struct piece * piece, int x ,int y,struct piece ***board2){
  if(piece->piece_type=='k'|| piece->piece_type=='K'){

            printf("la pieza es un k\n");
            if(x>7 ||x<0 || y>7|| y<0)return 0;  

            if(piece->x_axis+1==x &&piece->y_axis==y){

                        //uno hacia derecha
                        if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }

                }
            if(piece->x_axis-1==x&&piece->y_axis==y){
                //izquierda 
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }


            if(piece->x_axis==x&&piece->y_axis+1==y){
                //uno para arriba 
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }

            if(piece->x_axis==x&&piece->y_axis-1==y){
                //uno para abajo- 
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }


            if(piece->x_axis+1==x&&piece->y_axis+1==y){
                //diagonal derecha
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }

            if(piece->x_axis-1==x&&piece->y_axis+1==y){
                            //diagonal izquierda
                            if(board2[y][x]==NULL)return 1;
                                    if(board2[y][x]!=NULL){
                                        if(board2[y][x]->color==piece->color)return 0;
                                        if(board2[y][x]->color!=piece->color) return 1;

                                    }
                            
                        }
            if(piece->x_axis+1==x&&piece->y_axis-1==y){
                //diagonal para abajo derecha 
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }
            if(piece->x_axis-1==x&&piece->y_axis-1==y){
                //diagonal para abajo izquierda
                if(board2[y][x]==NULL)return 1;
                        if(board2[y][x]!=NULL){
                            if(board2[y][x]->color==piece->color)return 0;
                            if(board2[y][x]->color!=piece->color) return 1;

                        }
                
            }








            else
            {
                return 0;
            }
            
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