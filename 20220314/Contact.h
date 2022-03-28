#define Max_Name 5
#define Max_Telep 5
#define Max_Sex 10
#define Max 1000
#include <stdio.h>
#include <string.h>

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
	struct PeoInfo date[Max];
	int size;

};
void Init_Contact(struct Contact* ps);
void Add_Contact(struct Contact*ps);
void Div_Contact(struct Contact* ps);
void Show_Contact(struct Contact* ps);