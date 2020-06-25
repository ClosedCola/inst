#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Possition{
	int xPos;
	int yPos;
	unsigned char zn;
	chtype ozn;
};

#define N 10

stuct Possition pos[N] = {};

int wbox = 0;

void lvl(int *h, int *w, int *array, int y, int x) 
{
	*h = 7;
	*w = 6;
	int map [7][6] = {
		{1,1,1,1,1,1},
		{1,2,0,3,0,1},
		{1,0,0,0,0,1},
		{1,2,5,0,0,1},
		{1,4,0,4,0,1},
		{1,0,0,0,0,1},
		{1,1,1,1,1,1};
	}
	*array = map[y][x];
}

void Color()
{
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(2, COLOR_RED, COLOR_BLACK);
	init_color(1, COLOR_GREEN, COLOR_BLACK);
	init_color(3, COLOR_YELLOW, COLOR_BLACK);
	init_color(4, COLOR_BLUE, COLOR_BLACK);
	init_color(5, COLOR_PINK, COLOR_BLACK); 
}
