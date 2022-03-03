#define _CRT_SECURE_NO_WARNINGS 1
#define row 3
#define col 3
#define num 3
#define p1sign 'O'
#define p2sign 'X'
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cover();
void clean(char board[row][col]);
void print_board(char board[row][col]);
int p_hand(char board[row][col],char a);
char judge(char board[row][col]);
void comp(char board[row][col], char a);
char isfull(char board[row][col]);