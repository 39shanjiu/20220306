#include "������.h"
#include <stdio.h>
//�ж������Ƿ�����.
int full(char arr[R][C], int r, int c)
{
	int i = 0;
	int k = 0;
	for (i = 0; i < r; i++)
	{
		for (k = 0; k < c; k++)
		{
			if (arr[i][k] == ' ')//��⵽�����С� ����Ϊδ��
			{
				return 0;
			}
		}
	}
	return 1;//û����Ϊ��
}
void remakeqipan(char arr[R][C], int r, int c)
{
	int n = 0;
	for (n = 0; n < r; n++)//��
	{
		int m = 0;
		for (m = 0; m < c; m++)//��
		{
			arr[n][m] = ' ';//��ʼ�����̣��ÿո�����������顣
		}
	}

}
void playermove(char arr[R][C], int r, int c)
{
	printf("������������꣺");
	int n = 0;
	int m = 0;	
	while (1)
	{
		scanf_s("%d%d", &n, &m);
		if (n >=1 && n <= r && m >= 1 && m <= c  )
		{
			if (arr[n-1][m-1] == ' ')
			{
				 arr[n - 1][m - 1] = 'x';//ֱ�Ӹ�ֵ����Ӧ����
				break;
			}
			else
			{
				printf("�����걻ռ��\n");
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
}
void computermove(char arr[R][C], int r, int c)
{
	printf("�����������꣺\n");
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
	//�ж�ÿ���Ƿ���ͬ
	for (i = 0; i < r; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
			return arr[i][0];
	}
	//�ж�ÿ���Ƿ���ͬ
	for (i = 0; i < c; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
			return arr[0][i];
	}
	//�жϽ���������Ƿ���ͬ
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ')
		return arr[0][0];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	//�ж��Ƿ�������δ��
	if (1 == full(arr, r, c))
		return 'Q';
	if (0 == full(arr, r, c))
		return 'G';
}
void qipan(char arr[R][C], int r, int c)
{
	int n = 0;
	int m = 0;
	for (n = 0; n < r; n++)//��
	{
			for (m = 0; m < c; m++)//��
			{
				printf(" %c ",arr[n][m]);//ÿ���м䶼��Ԫ��Ϊ0�����飬����ӡ������Ӧ���ƶ����ٸ�ֵ��ȥ.
				if (m < c - 1)//���һ������Ҫ
				{
					printf("|");
				}
			}
			printf("\n");
			for (m = 0; m < c; m++)//��
			{
				if (n < r - 1)//���һ�в���Ҫ
				{
					printf("---");
					if (m < c - 1)
						printf("|");
				}
			}
			printf("\n");
	}
}
