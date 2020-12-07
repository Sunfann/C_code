#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <windows.h>
#include <time.h>
#pragma warning(disable:4996)

#define ROW 3
#define COL 3

#define P_COLOR 'X'
#define C_COLOR 'O'
#define NEXT 'N'
#define DRAW 'D'

int Meun(int choice);
void Game();



#endif