
#include"Ajedrez_fun.h"

#include<stdio.h>
#include<stdlib.h>
void init_game(int **board, struct piece ***board2){

for (int a=0; a<8; a++){
    puts("\n");
    for(int b=0; b<8; b++){
     *(board[a]+b)=0;
        
        
        
    }
}
for (int a=0; a<9; a++){
    puts("\n");
    printf("%i$ ",a);
    
    for(int b=0; b<8; b++){
        
        
        if (a<8) printf(" %i- ",*(board[a]+b));
      
        if(a==8)printf(" %i- ",b);
        
    }
}


for (int a=0; a<8; a++){
 
    for(int b=0; b<8; b++){
       
       if (a==0&&b==0 || a==0&&b==7){

       struct piece * caster =malloc(sizeof(struct piece));
       caster->color='B';
       caster->piece_type='T';
       caster->mvs=0;
        *(board2[a]+b)=caster;//Torres
       }
       if(a==0&&b==1 || a==0&&b==6){
           struct piece * caster =malloc(sizeof(struct piece));
           caster->color='B';
           caster->piece_type='C';
           caster->mvs=0;//caballos 
           *(board2[a]+b)=caster;


           
       }
       if(a==0&&b==2 || a==0 && b==5){
            //arfiles \

            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->mvs=0;
            caster->piece_type='A';
             *(board2[a]+b)=caster;




       }
       if(a==0&&b==3 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->piece_type='K';
            caster->mvs=0;
            *(board2[a]+b)=caster; //rey

          
       }
       if(a==0&&b==4 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='B';
            caster->piece_type='R';
            caster->mvs=0;
            *(board2[a]+b)=caster; //reyna

          
       }
        if(a==1){
             struct piece * caster =malloc(sizeof(struct piece));
             caster->color='B';
             caster->piece_type='P';
             caster->mvs=0;
             *(board2[a]+b)=caster; //peones




        }
        if(a==6){


             struct piece * caster =malloc(sizeof(struct piece));
             caster->color='W';
             caster->piece_type='P';
             caster->mvs=0;
             *(board2[a]+b)=caster; //peones

        }
        



       
        if (a==7&&b==0 || a==7&&b==7){

       struct piece * caster =malloc(sizeof(struct piece));
       caster->color='W';
       caster->piece_type='T';
       caster->mvs=0;
        *(board2[a]+b)=caster;//Torres
       }

         if(a==7&&b==1 || a==7&&b==6){
           struct piece * caster =malloc(sizeof(struct piece));
           caster->color='W';
           caster->piece_type='C';
           caster->mvs=0;//caballos 
           *(board2[a]+b)=caster;


           
       }

       if(a==7&&b==2 || a==7 && b==5){
            //arfiles \

            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->mvs=0;
            caster->piece_type='A';
             *(board2[a]+b)=caster;




       }
    if(a==7&&b==3 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->piece_type='K';
            caster->mvs=0;
            *(board2[a]+b)=caster; //rey

          
       }
        if(a==7&&b==4 ){
            
            
            struct piece * caster =malloc(sizeof(struct piece));
            caster->color='W';
            caster->piece_type='R';
            caster->mvs=0;
            *(board2[a]+b)=caster; //reyna

          
       }

    if(a==2||a==3||a==4||a==5){
    *(board2[a]+b)=NULL;


    }



       
  
        
        
        
    }
}





for (int a=0; a<8; a++){
    puts("\n");
    
    for(int b=0; b<8; b++){
        
        
       
        if(board2[a][b]==NULL){

            printf(" X- " );
        }
        else
        {
                    printf(" %c- ",board2[a][b]->piece_type);

        }
        
      
    
        
    }
}







}