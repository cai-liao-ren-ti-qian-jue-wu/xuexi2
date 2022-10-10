#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int a = 1;
	while (1)
	{
		printf("********************************************\n");
		printf("*****请输入数字：1.开始游戏；0.结束游戏*****\n");
		printf("********************************************\n");
		scanf("%d", &a);
		if (a == 1)
		{
			printf("游戏开始！！\n");
			game();
		}
		else if (a == 0)
		{
			printf("游戏结束！！\n");
			break;
		}
		    else
			printf("输入有误，请再次输入\n");

	}
    	return 0;
}