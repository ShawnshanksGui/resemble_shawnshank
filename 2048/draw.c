#include<stdio.h>
#include<curses.h>
#include<stdlib.h>
#include<time.h>
#include<signal.h>
#include<unistd.h>

int a[4][4]  = {0};

int empty = 0;
int old_x = 0;
int old_y = 0;

void init();
void draw();
void draw_one();
int game_over();
void play();


int main()
{
	init();
	play();
	endwin();

	return 0;
}

void draw()
{
	int n, m, x, y = 0;
	//char c[4] = {'0', '0', '0', '0'};

	clear();

	for(n = 0; n < 9; n += 2)
	{
		for(m = 0; m < 21; m++)
		{
			move(n, m);
			addch('-');
			refresh();
		}
	}

	for(m = 0; m < 22; m +=5)
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

void draw_one(int x, int y)
{
	int i, m, k, j = 0;
	char c[4] = {'0', '0', '0', '0'};

	i =  a[y][x];
	m = 0;

	do
	{
		j = i % 10;
		c[m++] = j + '0';
		i = i / 10;
	}while(i > 0);

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

	do
	{
		j = i % 10;
		c[m++] = j + '0';
		i = i / 10;
	}while(i > 0);

	m = 0;
	k = (x + 1) * 5 - 1;

	while(c[m] != '0')
	{
		move(2*y+1, k);
		addch(c[m++]);
}
*/

void Is_empty()
{
	int i ,j = 0;
	int is_empty = 0;

	for(i = 0; i <= 3; i++)
		for(j = 0; j <= 3; j++)
		{	
			if((i < 3) && (j < 3))
			{
				if(a[i][j] == a[i+1][j] || a[i][j] == a[i][j+1])
				{
					is_empty= 1;
				}
			}
			else if(i < 3 && j == 3)
			{
				if(a[i][j] == a[i+1][j])
				{
					is_empty = 1;
				}
			}
			else if(i == 3 && j < 3)
			{
				if(a[i][j] == a[i][j+1])
				{
					is_empty = 1;
				}
			}
		}

		if(!is_empty)
		{
			game_over();
		}
}

void play()
{
	int x, y, i, new_x, new_y, tmp = 0;
	int old_empty = 0;
	int move = 0;
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
					for(x = 0; x < 4; )
					{
						if(a[y][x] == 0)
						{
							x++;
							continue;
						}
						else
						{
							for(i = x+1; i < 4; i++)
							{
								if(a[y][i] == 0)
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
				for(y = 0; y < 4; y++)
					for(x = 0; x < 4; x++)
					{
						if(a[y][x] == 0)
						{
							continue;
						}
						else
						{
							for(i = x; (i > 0) && (a[y][i-1] == 0); i--)
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
					for(x = 3; x >=0; )
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
				for(y = 0; y < 4; y++)
					for(x = 3; x >= 0; x--)
					{
						if(a[y][x] == 0)
						{
							continue;
						}
						else
						{
						/*	for(i = x-1; i <= 0; i--)
							{
								if(a[y][i-1] == a[y][i] && i > 0)
								{
									a[y][i-1] = a[y][i];
									a[y][i] = 0;

									move = 1;
								}
							}
						*/	
							for(i = x; (i < 3) && (a[y][i+1] == 0); i++)
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
					for(y = 0; y <4; )
					{
						if(a[y][x] == 0)
						{
							y++;
							continue;
						}
						else
						{
							for(i = y+1; i < 4; i++)
							{
								if( a[i][x] == 0)
								{
									continue;
								}
								else if(a[i][x] == a[y][x])
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

					for(x = 0; x < 4;x++)
						for(y = 0; y < 4; y++)
						{
							if(a[y][x] == 0)
							{
								continue;
							}
							else
							{
								for(i = y; (i > 0) && (a[i-1][x] == 0);
								i--)
								{
									a[i-1][x] = a[i][x];
									a[i][x] = 0;

									move = 1;
								}
							}
						}
					break;

			case 'S':
			case 's':
				for(x = 0; x < 4; x++)
					for(y = 3; y >= 0; )
					{
						if(a[y][x] == 0)
						{
							y--;
							continue;
						}
						else
						{
							for(i = y-1; i >= 0; i--)	
							{
								if(a[i][x] == 0)
								{
									continue;
								}
								else if(a[i][x] == a[y][x])
								{
									a[y][x] += a[i][x];
									a[i][x] = 0;
									y = i - 1;
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

					for(x = 0; x <= 3; x++)
						for(y = 3; y >= 0; y--)
						{
							if(a[y][x] == 0)
							{
								continue;
							}
							else
							{
								for(i = y; (i < 3) && (a[i+1][x] == 0);
								i++)
								{
									a[i+1][x] = a[i][x];
									a[i][x] = 0;
									move = 1;
								}
							}
						}
				break;

			case 'Q':
			case 'q':
				game_over();
				break;
			default:
				continue;
				break;
		}
		
		if(empty <= 0)
		{
			Is_empty();
		}
	//	draw();

		if((empty != old_empty) || (move == 1))
		{
			do
			{
				new_x = rand() % 4;
				new_y = rand() % 4;
			}while(a[new_y][new_x] != 0);
			
			do
			{
				tmp = rand() % 4;
			}while(tmp == 0 || tmp == 2);
			a[new_y][new_x] = tmp + 1;
			empty--;
		//	draw_one(new_y, new_x);
			draw();
		}
	}
}

int game_over()
{
	sleep(1);
	endwin();
	exit(0);
}
