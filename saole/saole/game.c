#include "game.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void game()
{
	//nandu();
	char min[hs][ls]={0};
	char show[hs][ls] = {0};
	chushihua(min, hs, ls,'0');
	chushihua(show, hs, ls, '*');
	setmin(min, h, l);
	chazhao(min, show, h, l);
}

void chushihua(char min[hs][ls], int hs1, int ls1,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < hs1; i++)
	{
		for (j = 0; j < ls1; j++)
			min[i][j] = set;
	}
}

void zhanshi(char min[hs][ls], int h1, int l1)
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i <= h1; i++)
	{
		printf("%-2d", i);
	}
	printf("\n");
	for (i = 1; i <= h1; i++)
	{
		printf("%-2d ", i);
		for (j = 1; j <= l1; j++)
			printf("%c ", min[i][j]);
		    printf("\n");
	}
}

void setmin(char min[hs][ls], int h1, int l1)
{
	int c = gs;
	while (c)
	{
		int x = rand() % h + 1;
		int y = rand() % l + 1;
		if (min[x][y] == '0')
		{
			min[x][y] = '1';
			c--;
		}
	}
}

void chazhao(char min[hs][ls], char show[hs][ls], int h1, int l1)
{
	int x=0;
	int y=0;
	int win = 0;
	zhanshi(show, h, l);
	while (win<h*l-gs)
	{
		printf("请输入排查的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= h && y >= 1 && y <= l)
		{
			if (min[x][y] == '1')
			{
				printf("踩到了雷，游戏结束\n");
				zhanshi(min, h, l);
				break;
			}
			else
			{
				liansuo(min, show, x, y);
				zhanshi(show, h, l);
				win++;
			}
		}
		else
			printf("输入的坐标超出范围，请再次输入");
	}
	if (win == h * l - gs)
	{
		printf("游戏胜利");
		zhanshi(min, h, l);
	}
}

int jisuan(char min[hs][ls], int x, int y)
{
	int c = 0;
	c = min[x + 1][y] + min[x + 1][y + 1] + min[x - 1][y] + min[x - 1][y + 1] +
		min[x - 1][y - 1] + min[x][y + 1] + min[x][y - 1]+min[x+1][y - 1]-8*'0';//'3'-'0'=3  '0'-'0'=0 '2'-'0'=2
	return c;
}
int liansuo(char min[hs][ls], char show[hs][ls], int x, int y)
{
	int i;
	int j;
	int count;
		count = jisuan(min, x, y);
		if (count != 0)
		{
			show[x][y] = '0' + count;
		}
		else
		{
			for (i = -1; i < 2; i++)
			{
				for (j = -1; j < 2; j++)
				{
					if (i == 0 && j == 0)
					{
						show[x + i][y + j] = ' ';
					}
					else if ((i==-1)&& (j == -1)|| (i == -1) && (j == 1) || (i == 1) && (j == -1) || (i == 1) && (j == 1))
					{
						;
					}
					else if(show[x+i][y+j] == '*' && x+i < l+1 && y+j < h+1 && x + i >0 && y + j > 0)
					{
						count = jisuan(min, x + i, y + j);
						if (count != 0)
							show[x + i][y + j] = '0' + count;//将数字转化为字符
						else
						{
							show[x + i][y + j] = ' ';
							liansuo(min, show, x + i, y + j);
						}
					}
				}
			}
		}
	return 0;
}
//
//int nandu()
//{
//
//	while (1)
//	{
//		printf("请选择难度：1.简单  2.中等   3.困难");
//		int x = 0;
//		scanf("%d", &x);
//		if (x = 1)
//		{
//			
//			break;
//		}
//		else if (x = 2)
//		{
//			
//			break;
//		}
//		else if (x = 3)
//		{
//			
//			break;
//		}
//		else
//			printf("选择有误请重新选择\n");
//
//	}
//	return 0;
//}
