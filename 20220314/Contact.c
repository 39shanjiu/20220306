#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void Init_Contact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;
}
void Add_Contact(struct Contact* ps)
{
	if (ps->size == Max)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->date[ps->size].name);
		printf("�������Ա�");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰��");
		scanf("%s", ps->date[ps->size].telep);
		printf("���������䣺");
		scanf("%d", &(ps->date[ps->size].age));
		
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void Div_Contact(struct Contact* ps)
{
	printf("����������Ҫɾ�����û�������:");
	char name[Max_Name];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name , name))
		{
			break;
		}
	}
	if (i == ps->size)
	{
		printf("���û�������\n");
	}
	else
	{
		ps->date[i] = ps->date[ps->size];
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
	
}
void Show_Contact(const struct Contact* ps)
{
	int i = 0;
	printf("%-5s\t%-5s\t%-12s\t%-s\t\n", "����", "�Ա�", "�绰", "����");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-5s\t%-5s\t%-12s\t%-d\t\n", ps->date[i].name,
			ps->date[i].sex,
			ps->date[i].telep,
			ps->date[i].age);
	}
}