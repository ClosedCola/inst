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
int lve = 0;

void lvllist(int *h, int *w, int *array, int y, int x, int n)
{
	if (n == 0 )
	{
		*h = 7;
		*w = 6;
		int map0[7][6] = {
			{1,1,1,1,1,1},
			{1,2,0,3,0,1},
			{1,0,0,0,0,1},
			{1,2,5,0,0,1},
			{1,4,0,4,0,1},
			{1,0,0,0,0,1},
			{1,1,1,1,1,1};
		};
		*array = map0[y][x];
	}
	else if (n == 1)
	{
		*h = 9;
		*w = 10;
		int map1[9][10] = {
			{1,1,1,1,1,1,1,1,1,1};
			{1,0,0,0,0,0,0,0,0,1};
			{1,0,0,0,0,2,0,0,0,1};
			{1,0,0,0,0,0,0,0,0,1};
			{1,0,4,0,0,0,0,0,0,1};
			{1,0,0,0,0,0,0,0,0,1};
			{1,0,0,0,0,5,0,0,0,1};
			{1,0,0,0,0,0,0,0,0,1};
			{1,1,1,1,1,1,1,1,1,1};
	};
	*array = map1[y][x];
}
}


void Color()
{
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(2, COLOR_RED, COLOR_BLACK);
	init_color(1, COLOR_GREEN, COLOR_BLACK);
	init_color(3, COLOR_YELLOW, COLOR_BLACK);
	init_color(4, COLOR_BLUE, COLOR_BLACK);
	init_color(5, COLOR_PINK, COLOR_BLACK); 	// pink
}

void Level (int n)
{
	clear();
	mvprintw(2,1, "Move - WASD Restart - R Exit - Q");
	int x = 0, y = 0, h = 1, w = 1, map;
	wbox = 0;

	for (y = 0; y < h; y++)
	{
		for (x = 0; x < w; x++)
		{
			lvllist(&h, &w, &map, y, x, n);
			swtch(map)
			{
				case 0: mvaddch (y+4,x+10,'-' | COLOR_PAIR(4)); break;
				case 1: mvaddch (y+4,x+10,'#' | COLOR_PAIR(1)); break;
				case 2: mvaddch (y+4,x+10,'x' | COLOR_PAIR(2)); break;
				case 4:
					mvaddch (y+4,x+10,'-' | COLOR_PAIR(4));
					wbox += 1;
					obj[wbox].ozn = mvinch(y+4,x+10);
					obj[wbox].yPos = y+4;
					obj[wbox].xPos = x+10;
					obj[wbox].zn = '@';
					mvaddch(obj[wbox].yPos,obj[wbox].xPos,obj[wbox].zn | COLOR_PAIR(5));
					break;
				case 5:
					mvaddch(y+4,x+10,'-' | COLOR_PAIR(4));
					obj[0].ozn = mvinch(y+4,x+10);
					obj[0].yPos = y+4;
					obj[0].xPos = x+10;
					obj[0].zn = 'P';
					mvaddch(obj[0].yPos,obj[0].xPos,obj[0].zn | COLOR_PAIR(3));
					break;
				}
			}
		}
		move(obj[0].yPos,obj[0].xPos);
	}
	void Play(nt input)
	{
		bool restart = FALSE;
		chtype up, lf, dw, rg, oup, olf, odw, org;  // движение игрока и толкание ящика
		up = (mvinch(obj[0].yPos-1,obj[0].xPos) & A_CHARTEXT);
		lf = (mvinch(obj[0].yPos,obj[0].xPos-1) & A_CHARTEXT);
		dw = (mvinch(obj[0].yPos+1,obj[0].xPos) & A_CHARTEXT);
		rg = (mvinch(obj[0].yPos,obj[0].xPos+1) & A_CHARTEXT);
		oup = (mvinch(obj[0].yPos-2,obj[0].xPos) & A_CHARTEXT);
		olf = (mvinch(obj[0].yPos,obj[0].xPos-2) & A_CHARTEXT);
		odw = (mvinch(obj[0].yPos+2,obj[0].xPos) & A_CHARTEXT);
		org = (mvinch(obj[0].yPos,obj[0].xPos+2) & A_CHARTEXT);
}
