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
		printf("*****���������֣�1.��ʼ��Ϸ��0.������Ϸ*****\n");
		printf("********************************************\n");
		scanf("%d", &a);
		if (a == 1)
		{
			printf("��Ϸ��ʼ����\n");
			game();
		}
		else if (a == 0)
		{
			printf("��Ϸ��������\n");
			break;
		}
		    else
			printf("�����������ٴ�����\n");

	}
    	return 0;
}