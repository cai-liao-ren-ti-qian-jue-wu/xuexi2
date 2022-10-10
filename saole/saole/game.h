#pragma once
#define h 18
#define l 18
#define hs h+2
#define ls l+2
#define gs 40
void game();
void chushihua(char min[hs][ls], int hs1, int ls1,char set);
void zhanshi(char min[hs][ls], int h1, int l1);
void setmin(char min[hs][ls], int h1, int l1);
void chazhao(char min[hs][ls], char show[hs][ls], int h1, int l1);
int  jisuan(char min[hs][ls], int x, int y);
int liansuo(char min[hs][ls], char show[hs][ls], int x, int y);
int nandu();