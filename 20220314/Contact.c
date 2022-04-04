#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void Init_Contact(struct Contact* ps)
{
	ps->date = malloc(sizeof(struct PeoInfo)*FALUAT_SZ);
	ps->size = 0;
	ps->capacity = FALUAT_SZ;
	Load_Contact(ps);
}
void CheckCapcity(struct Contact* ps);


void Load_Contact(struct Contact* ps)
{
	struct PeoInfo tmp = { 0 };
	FILE* f = fopen("contact.dat", "rb");
	if (f == NULL)
	{
		printf("Load_Contact:%s\n", strerror(errno));
		return;
	}
	while (fread(&tmp, sizeof(struct PeoInfo), 1, f))
	{
		CheckCapcity(ps);
		ps->date[ps->size] = tmp;
		ps->size++;
	}
	fclose(f);
	f = NULL;
}
void CheckCapcity(struct Contact* ps)
{
	if (ps->size == ps->capacity)
	{
		struct PeoInfo* ptr = realloc(ps->date, (ps->capacity + 2) * sizeof(struct PeoInfo));
		if (ptr != NULL)
		{
			ps->capacity += 2;
			ps->date = ptr;
			printf("next\n");
		}

	}
}
void Add_Contact(struct Contact* ps)
{
	CheckCapcity(ps);
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
	printf("����������Ҫɾ�����û�������:");
	int i = FindPeoInfo(ps);
	if (i == ps->size)
	{
		printf("���û�������\n");
	}
	else
	{
		ps->date[i] = ps->date[ps->size - 1];
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
void Search_Contact(const struct Contact* ps)
{
	int i = FindPeoInfo(ps);	
	if(i == ps->size)
	{
		printf("���û�������\n");
	}
	else
	{
		printf("%-5s\t%-5s\t%-12s\t%-s\t\n", "����", "�Ա�", "�绰", "����");
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
		printf("���û�������\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->date[i].name);
		printf("�������Ա�");
		scanf("%s", ps->date[i].sex);
		printf("������绰��");
		scanf("%s", ps->date[i].telep);
		printf("���������䣺");
		scanf("%d", &(ps->date[i].age));
	}
	printf("��ĳɹ�\n");
}

void Save_Contact(struct Contact* ps)
{
	FILE* f = fopen("contact.dat", "wb");
	if (f == NULL)
	{
		printf("Save_Contact:%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i <ps->size; i++)
	{
		fwrite(&(ps->date[i]), sizeof(struct PeoInfo), 1, f);
	}
	fclose(f);
	f = NULL;

}