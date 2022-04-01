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
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->date[ps->size].name);
		printf("请输入性别：");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[ps->size].telep);
		printf("请输入年龄：");
		scanf("%d", &(ps->date[ps->size].age));
		
		ps->size++;
		printf("添加成功\n");
	}
}
int FindPeoInfo(const struct Contact* ps)
{
	char name[Max_Name];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->date[i].name, name))
		{
			break;
		}
	}
	return i;
}

void Div_Contact(struct Contact* ps)
{
	printf("请输入你需要删除的用户的姓名:");
	int i = FindPeoInfo(ps);
	if (i == ps->size)
	{
		printf("该用户不存在\n");
	}
	else
	{
		ps->date[i] = ps->date[ps->size - 1];
		ps->size--;
		printf("删除成功\n");
	}
	
}
void Show_Contact(const struct Contact* ps)
{
	int i = 0;
	printf("%-5s\t%-5s\t%-12s\t%-s\t\n", "姓名", "性别", "电话", "年龄");
	for (i = 0; i < ps->size; i++)
	{
		printf("%-5s\t%-5s\t%-12s\t%-d\t\n", ps->date[i].name,
			ps->date[i].sex,
			ps->date[i].telep,
			ps->date[i].age);
	}
}
void Search_Contact(const struct Contact* ps)
{
	int i = FindPeoInfo(ps);	
	if(i == ps->size)
	{
		printf("该用户不存在\n");
	}
	else
	{
		printf("%-5s\t%-5s\t%-12s\t%-s\t\n", "姓名", "性别", "电话", "年龄");
		printf("%-5s\t%-5s\t%-12s\t%-d\t\n", ps->date[i].name,
			ps->date[i].sex,
			ps->date[i].telep,
			ps->date[i].age);
	}
}
void Modify_Contact(struct Contact* ps)
{	
	int i = FindPeoInfo(ps);
	if (i == ps->size)
	{
		printf("该用户不存在\n");
	}
	else
	{
		printf("请输入姓名：");
		scanf("%s", ps->date[i].name);
		printf("请输入性别：");
		scanf("%s", ps->date[i].sex);
		printf("请输入电话：");
		scanf("%s", ps->date[i].telep);
		printf("请输入年龄：");
		scanf("%d", &(ps->date[i].age));
	}
	printf("需改成功\n");
}
