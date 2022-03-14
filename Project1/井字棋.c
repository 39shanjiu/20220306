#include "井字棋.h"
#include <stdio.h>
//判断棋盘是否下满.
int full(char arr[R][C], int r, int c)
{
	int i = 0;
	int k = 0;
	for (i = 0; i < r; i++)
	{
		for (k = 0; k < c; k++)
		{
			if (arr[i][k] == ' ')//检测到棋盘有‘ ’则为未满
			{
				return 0;
			}
		}
	}
	return 1;//没有则为满
}
void remakeqipan(char arr[R][C], int r, int c)
{
	int n = 0;
	for (n = 0; n < r; n++)//行
	{
		int m = 0;
		for (m = 0; m < c; m++)//列
		{
			arr[n][m] = ' ';//初始化棋盘，用空格代替已填数组。
		}
	}

}
void playermove(char arr[R][C], int r, int c)
{
	printf("玩家请输入坐标：");
	int n = 0;
	int m = 0;	
	while (1)
	{
		scanf_s("%d%d", &n, &m);
		if (n >=1 && n <= r && m >= 1 && m <= c  )
		{
			if (arr[n-1][m-1] == ' ')
			{
				 arr[n - 1][m - 1] = 'x';//直接赋值到相应坐标
				break;
			}
			else
			{
				printf("该坐标被占用\n");
			}
		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
}
void computermove(char arr[R][C], int r, int c)
{
	printf("电脑输入坐标：\n");
	int n = 0;
	int m = 0;	
	while (1)
	{
		n = rand() % r;
		m = rand() % c;
		if (arr[n][m] == ' ')
		{
		    arr[n][m] = '#';
			break;
		}
	}
}
char win(char arr[R][C], int r, int c)
{
	int k = 0;
	int i = 0;
	//判断每行是否都相同
	for (i = 0; i < r; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	//判断每列是否都相同
	for (i = 0; i < c; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	//判断交叉的两条是否相同
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	//判断是否和棋或者未满
	if (1 == full(arr, r, c))
		return 'Q';
	if (0 == full(arr, r, c))
		return 'G';
}
void qipan(char arr[R][C], int r, int c)
{
	int n = 0;
	int m = 0;
	for (n = 0; n < r; n++)//行
	{
			for (m = 0; m < c; m++)//列
			{
				printf(" %c ",arr[n][m]);//每格中间都是元素为0的数组，不打印，到相应方移动是再赋值上去.
				if (m < c - 1)//最后一个不需要
				{
					printf("|");
				}
			}
			printf("\n");
			for (m = 0; m < c; m++)//列
			{
				if (n < r - 1)//最后一列不需要
				{
					printf("---");
					if (m < c - 1)
						printf("|");
				}
			}
			printf("\n");
	}
}
