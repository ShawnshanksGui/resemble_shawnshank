#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>

int a[4][4] = {0};

int empty = 0;
int old_x = 0;
int old_y = 0;

void draw();
void play();
void init();
void draw_one(int y, int x);
void cnt_value(int *new_y, int *new_x);
int game_over();
int cnt_one(int y, int x);

int main()
{
	init();
	play();
	endwin();

	return 0;
}

void init()
{
	int x = 0;
	int y = 0;

	initscr();
	cbreak();
	noecho();

	curs_set(0);

	empty = 15;
	srand(time(0));
	x = rand() % 4;
	y = rand() % 4;
	a[y][x] = 2;
	draw();
}

void draw()
{
	int n, m, x, y = 0;
	char c[4] = {'0', '0', '0', '0'};

	clear();
	for(n = 0; n < 9; n += 2)
	{
		for(m = 0; m < 21; m ++)
		{
			move(n, m);
			addch('-');
			refresh();
		}
	}

	for(m = 0; m < 22; m += 5)
	{
		for(n = 1; n < 8; n++)
		{
			move(n, m);
			addch('|');
			refresh();
		}
	}
	for(y = 0; y < 4; y++)
	{
		for(x = 0; x < 4; x++)
		{
			draw_one(y, x);
		}
	}

}

void draw_one(int y, int x)
{
	int i, m, k, j = 0;

	char c[4] = {'0', '0', '0', '0'};

	i = a[y][x];
	m = 0;
	do
	{
		j = i % 10;
		c[m++] = j + '0';
		i = i / 10;
	}while(i > 10);

	m = 0;
	k = (x + 1) * 5 - 1;

	while(c[m] != '0')
	{
		move(2*y+1, k);
		addch(c[m++]);
		k--;
	}
}
/*
void draw_one(int y, int x)
{
	int i, m, k, j = 0;
	char c[4] = {'0', '0', '0', '0'};

	i = a[y][x];
	m = 0;
	do 
	{
		j = i % 10;
		c[m++] = j + '0';
		i = i / 10;
	}while(i > 10);

	m = 0;
	k = (x + 1) * 5 - 1;

	while(c[m] != '0')
	{
	}
}
*/
void play()
{
	int x, y, i, new_x, new_y, temp = 0;
	int old_empty, move = 0;
	char ch = '\0';

	while(1)
	{
		move = 0;
		old_empty = empty;
		
		ch = getch();
		switch(ch)
		{
			case 'A':
			case 'a':
				for(y = 0; y < 4; y++)
				{
					for(x = 0; x < 4;)
					{
						if(a[y][x] == 0)
						{
							x++;
							continue;
						}
						else
						{
							for(i = x + 1; i < 4; i++)
							{
								if(a[y][x] == 0)
								{
									continue;
								}
								else
								{
									if(a[y][x] == a[y][i])
									{
										a[y][x] += a[y][i];
										a[y][i] = 0;
										x = i + 1;
										empty++;
										break;
									}
									else
									{
										x = i;
										break;
									}
								}
							}
							x = i;
						}
					}
				}
				for(y = 0; y < 4; y++)	
					for(x = 0; x < 4; x++)
					{
						if(a[y][x] == 0)
						{
							continue;
						}
						else
						{
							for(i = x; (i > 0) && (a[y][i-1] == 0);
							i--)
							{
								a[y][i-1] = a[y][i];
								a[y][i] = 0;

								move = 1;
							}
						}
					}
				break;
			case 'D':
			case 'd':
				for(y = 0; y < 4; y++)
					for(x = 3; x >= 0; )
					{
						if(a[y][x] == 0)
						{
							x--;
							continue;
						}
						else
						{
							for(i = x-1; i >= 0; i--)
							{
								if(a[y][i] == 0)
								{
									continue;
								}
								else if(a[y][x] == a[y][i])
								{
									a[y][x] += a[y][i];
									a[y][i] = 0;
									x = i - 1;
									empty++;
									break;
								}
								else
								{
									x = i; 
									break;
								}
							}
							x = i;
						}
					}
				for (y = 0; y < 4; y++)
					for(x = 3; x >= 0; x--)
					{
						if(a[y][x] == 0)
						{
							continue;
						}
						else
						{
							for(i = x; (i < 3) && (a[y][i+1]) == 0;
							i++)
							{
								a[y][i+1] = a[y][i];
								a[y][i] = 0;

								move = 1;
							}
						}
					}
				break;

				case 'W':
				case 'w':
					for(x = 0; x < 4; x++)
					{
						for(y = 0; y < 4; )
						{
							if(a[y][x] == 0)
							{
								y++;
								continue;
							}
							else
							{
								for(i = y+1; i< 4; i++)
								{
									if(a[i][x] == 0)
									{
										continue;
									}
									else if(a[y][x] == a[i][x])
									{
										a[y][x] += a[i][x];
										a[i][x] = 0;
										y = i + 1;
										empty++;
										break;
									}
									else
									{
										y = i;
										break;
									}
								}
								y = i;
							}
						}
					}
		}
	}
}
