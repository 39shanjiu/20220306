#define Max_Name 5
#define Max_Telep 5
#define Max_Sex 10
#define Max 1000
#define FALUAT_SZ 3

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS 1



struct PeoInfo
{
	char name[Max_Name];
	char sex[Max_Sex];
	char telep[Max_Telep];
	int age;
};

struct Contact
{
	struct PeoInfo* date;
	int size;// �����±�
	int capacity;//�ɽ��ɵ�Ԫ�ظ���
};

void Init_Contact(struct Contact* ps);

void Add_Contact(struct Contact*ps);

void Div_Contact(struct Contact* ps);

void Show_Contact(struct Contact* ps);

void Search_Contact(struct Contact* ps);

int FindPeoInfo(struct Contact* ps);

void Modify_Contact(struct Contact* ps);

void CheckCapcity(struct Contact*ps);


void Save_Contact(struct Contact* ps);

void Load_Contact(struct Contact* ps);
