#include<stdio.h>
#include"Ajedrez_fun.h"


void init_game(int **board){

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






}