#include <stdio.h>
#include <stdlib.h>
//����ͷ�ļ���rand��srand������
//rand--����һ���������0��0x7fffff��ʮ������))���ǲ��������й̶������޷����������������
//��ʱҪ��srand����--����ָ��rand����ָ�������������������srand��ָ������ҲҪһ�������������sand
//����ӽ���������Ի�Ҫ����һ������time��
//srand((unsigned int)time(NULL));����time����
#include <time.h>
//����ͷ�ļ���time��ʱ���
//time�������Ը���ʱ�����һ���������ڵ�ʱ���ȥ1970��1��1����ת����һ���������õ�λΪ������룬���Կ���
//��ʱ�����ﵽ�����
//2.�˵�
void meau()
{
	printf("----------------\n");
	printf("1.play   0.exit \n");
	printf("----------------\n");
}
//��Ϸ����.
void game()
{
	int guess = 0;
	printf("������\n");
	int ret = 0;
	ret = rand() % 100 + 1;//rand���������Χ������ % �ѷ�Χ��Ϊ1 ~ 100.

	while (1)//1Ϊ�棬��ʼѭ��.
	{
		printf("");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
		}
		else if (guess < ret)
		{
			printf("��С��\n");
		}
		else
		{
			printf("��ϲ�㣬�¶���\n");
			break;
		}
	}
	printf("%d\n", ret);
}
int main()
//��ʼ��Ʋ�������Ϸ
//1.����һ��1 ~ 100 �������
//2.��ʼ�˵�
//3.���밴����ʼ��Ϸ
//4.�����������ָ�����Ӧ��ʾ��
//5.�¶Խ�����Ϸ�����½���˵�ѡ��.
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do//�Ƚ��к�ѭ��.
	{
		meau();
		//�˵� -- ��Ʋ˵�
		printf(" �����룺");
		scanf_s("%d", &input);//3.�������ֿ�ʼ��Ϸ
		switch (input)
		{
		case 1:
			game();//��Ϸ����.
			break;//����switchѭ�����½���do whileѭ��.
		case 0:
			printf("�˳���Ϸ\n");
			break;//ͬ��
		default:
			printf("�޷�ʶ������������\n");
			break;//ͬ��
		}//3.�������ֿ�ʼ��Ϸ.
	} while (input);//input while�ж�����0Ϊ�� ����ѭ�������� 0 �˳���Ϸ��Ӧ.
	return 0;
}