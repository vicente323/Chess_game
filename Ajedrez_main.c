#include"Ajedrez_fun.h"
#include<stdio.h>
#include<stdlib.h>
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


int *board[8];
int arr0[8];
int arr1[8];
int arr2[8];
int arr3[8];
int arr4[8];
int arr5[8];
int arr6[8];
int arr7[8];

board[0]=arr0;
board[1]=arr1;
board[2]=arr2;
board[3]=arr3;
board[4]=arr4;
board[5]=arr5;
board[6]=arr6;
board[7]=arr7; 


init_game(board,board2);


    
}