
#define  _CRT_SECURE_NO_WARNINGS 1
#define rows 11
#define cols 11
#define row rows-2
#define col cols-2
#define count_mine 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void content();
int select();
void clean(char board[rows][cols], char a);
void display(char board[rows][cols]);
void set_mine(char board[rows][cols]);
void scout_mine(char mine[rows][cols],char board[rows][cols]);
int calcu_mine(char mine[rows][cols],int a,int b);
int judje(char board[rows][cols]);
void boom_style(char mine[rows][cols],char board[rows][cols],int a,int b);
