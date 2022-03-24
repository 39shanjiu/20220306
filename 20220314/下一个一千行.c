//#include <stdio.h>
//void test()
//{
//	printf("hehe");
//}
//int main()
//{
//	test(100);
//	return 0;
//}
//int main()
//{
//	int a = 20;
//	int b = -10;
//	char c = 'a';
//
//	return 0;
//}
//int main()
//{
//	char a = -128;
//	//100000000000000000000000100000000  原码
//	//111111111111111111111111011111111  反码
//	//111111111111111111111111100000000  补码
//	//100000000char类型只有8个比特位  存储的补码
//	printf("%u\n", a);
//	//%d 打印有符号的十进制整数。
//	//%u 打印无符号的十进制整数。
//	//补码 1000000000  
//	//整形提升  000000000000000000000001000000000
//	//反码      000000000000000000000000111111111
//	//原码      111111111111111111111111000000000
//	//所以打印的数字很大。
//	return 0;
//int main()
//{
//	char a = -1;//char会有整形提升和整形截断。
//	//一开始以int类型进行补码运算，最后存储是进行整形截断，即只存储最后8位。最高位仍视为符号位
//	signed char b = -1;//有符号char类型，同上，一般都是有符号类型，通常省略signed。
//	unsigned char c = -1;//无符号char类型，最高位不视为符号位。
//	printf("a = %d,b = %d,c = %d", a, b, c);
//	//此处打印的都是%d类型有符号十进制整数。
//	//在运算时会进行整形提升，即用32位算。
//	//用c举例。
//	//补码 11111111
//	//整形提升，由于为无符号数，前面加零，
//	//000000000000000000000111111111 整形提升后的补码
//	//由于最前面为0，时正数，原反补相同，说以为255.
//	return 0;
//}
//int main()
//{
//	unsigned int i = 0;
//	for(i = 9; i >= 0; i--)//死循环，还是那个⚪。无符号是0 到 2 ^32-1.
//	{
//		printf("%u\n", i);
//	}
//	return 0;
//}
//int main()
//{
//	char arr[1000];
//	int i = 1;
//	for (i = 0; i < 1000; i++)
//	{
//		arr[i] = -1 - i;
//	}
//	printf("%d", strlen(arr));//strlen不算0，在0前面停
//	//一开始是从-1开始算起，到-128，+1到127，再一直减到1，0遇到0停下，且不计算。
//	return 0;
//}
//int main()
//{
//	float f = 6.5;
//	//二进制  110.1(整数部分相同，小数部分，0.5为2的负一次方，所以为0.1
//	//类似0.125为2的负三次方，则为0.001）
//	//整数S = 0；
//	//1《= M 《2  M = 1.101；（M因为开头全为1，故1省略不储存）
//	//向后移了两位，E = 2（E有可能是负数）；
//	//为了不考虑正负，E在存储时，+127
//	// E = 2+127=129
//	// //存储的字节
//	//第一位为S
//	//再八位为E
//	//最后全为M
//	//0  10000001  10100000000000000000
//	//S    E +127    M 去开头1，小数向后补零
//	//0100 0000 1101 0000 0000 0000 0000 0000
//	//转换为16进制
//	//40 d0 00 00
//	//所以存储为0x00 00 d0 40
//	return 0;
//}
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("%d\n", n);//9
//	printf("%f\n", *pFloat);//0.0000000000000
//	//整形强行转换为浮点型，E的那八位很容易全为0，此时为 num * 2^-126 为很小的数，所以为0.0000000000
//
//	*pFloat = 9.0;
//	printf("%d", n);//9.0强行存储再整形中，E的部位通常1  0 都有，所以会是很大的数。
//	printf("%f", *pFloat);
//
//	return 0;
//}
//int main()
//{
//    char* p = 'a';
//	//printf("%c\n", *p);
//	//printf("%s\n", p);
//	printf("hello world\n");
//	return 0;
//}

//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	char* p1 = "abcdef";
//	char* p2 = "abcdef";
//	//打印haha，两个arr的首地址不同。
//	if (arr1 == arr2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	//打印hehe，两个指针存的内容相同，为了省内存用同一个内存。
//	if (p1 == p2)
//	{
//		printf("hehe\n");
//	}
//	else
//	{
//		printf("haha\n");
//	}
//	/*char* p = "abcdef";
//	printf("%c\n", *p);
//	printf("%s\n", p);
//	return 0;*/
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	int  k = 0;
//	for (i = 0; i < 3; i++)
//	{
//		for (k = 0; k < 5; k++)
//		{
//			printf("%d  ", *(parr[i]+k));
//		}
//		printf("\n");
//	}
//	return 0;
////}
//int main()
//{
//	char* arr1[10] = { 0 };//指针数组，存放指针的数组，是数组。
//	char*(* pa1)[10] = &arr1;//数组的地址
//	//取地址指针数组，（*pa1）相当于创建一个数组指针变量
//	// 这个指针指向10个地址，char*告诉这个数组指针指向的类型
//	//char*与指向的数组类型相同。
//	int arr2[10] = { 0 };
//	int (*pa2)[10] = &arr2;
//	//int类型是与指向的数组相同类型
//	return 0;
//}
//void print1(int arr[3][5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int k = 0;
//		for (k = 0; k < y; k++)
//		{
//			printf("%d ", *(*(arr + i) + k));//
//			//arr+i arr指的是第一行的数组地址
//			// arr[3][5]这里相当于有3个数组元素，每个元素是有5个元素的数组
//			// 所以首元素的地址是第一行的数组元素
//			// *（arr+i）解引用，得到第一行的数组元素的地址（该元素是数组，所以该元素的地址是元素的首元素地址）
//			// 所以解引用后得到的是第一行第一列元素的地址
//			//*(*(arr+i)+k)所以加上k后还需要解引用得到元素
//		}
//		printf("\n");
//	}
//}
//void print2(int (*p)[5], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int k = 0;
//		for (k = 0; k < y; k++)
//		{
//			//*p == arr
//			//以下四种效果相同
//			printf("%d ", *(*(p + i) + k));
//			//同上
//			printf("%d ", (*(p + i))[k]);//
//			//为防止*（p+i）与[k]结合，所以要在前面加上括号
//
//			printf("%d ", *(p[i]+k));
//			//p[i]相当与*（p+i）
//			printf("%d ", p[i] [k]);
//		    
//			//对于一维数组来说p[i] == arr[i] == *(p+i) == *(arr+i)
//			
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
//	print1(arr, 3, 5);
//	print2(arr, 3, 5);
//	return 0;
//}
//int main()
//{
//	int arr[5];
//	//普通数组，有五个元素，每个元素类型是int --- 数组
//	int* parr1[10];
//	//是个指针数组，有10个元素，每个元素类型是int* -- 数组
//	int (*parr2)[10];
//	//数组指针，该指针指向一个数组，该数组有10个元素，元素类型为int ---指针
//	int(*parr3[10])[5];
//	//parr3先与[10]结合，成为数组，再以*结合变成数组指针类似与*arr
//	//数组指针指向一个有5个元素的数组。
//	//有一个数组有10个元素，每个元素是个指针，每个指针都指向有5个元素的数组
//	//数组存指针，指针指向数组。
//	return 0;
//}
//int main()
//{
//	int arr1[5] = { 0 };
//	int *arr2[10] = {0}:
//	return 0;
//}
//int Add(int x, int y)
//{
//	int z = x + y;
//	return z;
//}
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int arr[10] = { 0 };
//	Add(a, b);
//	//取地址函数名与直接函数名效果一样。
//	printf("%p\n", Add);
//	printf("%p\n", &Add);
//	//函数指针，要加括号，与数组相似。
//	//存放函数地址的指针。
//	int (*p)(int, int) = Add;
//	printf("%d\n", (*p)(2, 3));
//	return 0;
//}
//int main()
//{
//	(*(void (*)())0);
//	//不要怕，很简单。
//	//首先从0下手，一个常数前面有括号，说明前面括号内的作用为强制类型转换0的类型。
//	// 0前面的括号为（void （*）（））大括号里面的内容即为函数指针，
//	// 说明0被强制转换为函数指针，该指针地址指向0；
//	// 大括号前面+*-》解引用，表示调用0地址处的函数。
//	void (*signal(int, void(*)(int)))(int);
//	//一个函数指针
//	//中间的函数名用了一个函数表示。
//	//该函数有两个参数，一个是int，另一个是函数指针。
//	return 0;52222222222221656541
//}232333333333333222222222222316465
//typedef unsigned int uint;
//
//int main()
//{
//	char* My_strcpy(char* dest, const char* src);
//	char* (*pr)(char*, const char*);
//	char* (*pfarr[4])(char*, const char*);
//	int k = 0;
//	int i;
//	return 0;
//}
//void meau()
//{
//	    printf("#######################\n");
//		printf("##1.Add         2.Sub##\n");
//		printf("##3.Div         3.Mul##\n");
//		printf("##      0. exit      ##\n");
//		printf("#######################\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	//pfarr 函数指针数组  也被称为转移表。
//	int (*pfarr[])(int, int) = {0,Add,Sub,Div,Mul};
//	do
//	{
//		meau();
//		printf("请选择：");
//		scanf_s("%d", &input);
//		if (input > 0 && input < 5)
//		{
//			printf("请输入两个操作数：");
//			scanf_s("%d%d", &x, &y);
//			int ret = pfarr[input]( x, y);
//			printf("%d\n", pfarr[input](x, y));
//			//break;
//		}
//		else if (input == 0)
//		{
//			printf("退出\n");
//		}
//		else
//		{
//			printf("输入错误\n");
//		} 
//	} while (input);
//
//	return 0;
//}
//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;//数组指针
//	int (*pfArr[4])(int, int);//函数指针数组
//	int (*(*ppfArr)[4])(int, int) = &pfArr;//
//	//ppfArr先于*结合，所以是指针该指针再与[4]结合
//	//成为一个数组指针，剩下的int (*)(int, int)是个函数指针类型
//	//所以ppfArr是一个数组指针，有四个元素，每个元素是一个函数指针。
//	return 0;
//}
//void qsort(float arr[], int sz)
//{
//
//}
//int main()
//{
//	float arr[] = {0,1.3,2.7,3,6,5.2,-4.6,7};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr,sz);
//	for()
//	return 0;
//}#include <math.h>
//#include <stdlib.h>
//void* p = &a;
////void*类型可以接受任意类型的地址
////但是不能解引用，还有++--；
//float cmp_float(const void* e1,const void* e2)
//{
//	return (float*)e1 - (float*)e2;
//}
//int main()
//{
//	float arr[] = { 20.3,2.5,6.5,8.69,3.68,7.36,8.21 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, arr[0], cmp_float);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%f ", arr[i]);
//	}
//	return 0;
//}
/*#include <stdio.h>
#include <string.h>
struct stu
{
	char name[20];
	int age;
};
void swap(char* s1, char* s2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int ret = *s1;
		*s1 = *s2;
		*s2 = ret;		
	}
}
void My_qsort(void* ss,int sz,int width,int (*cmp)(void*, void*))
{
	int i = 0;
	int k = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (k = 0; k < sz - i - 1; k++)
		{
			if (cmp((char*)ss + k * width, (char*)ss + (k + 1) * width) > 0)
			{
				swap((char*)ss + k * width, (char*)ss + (k + 1) * width,width);
			}
		}
	}
}
int cmp_str_name(const void* e1,const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

int main()
{
	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int sz = sizeof(s) / sizeof(s[0]);
	My_qsort(s, sz, sizeof(s[0]), cmp_str_name);
	return 0;
}*/
//#include <stdio.h>
//#include <string.h>//strcmp
//void Swap(char* s1, char* s2,int width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		int tmp = *s1;
//		*s1 = *s2;
//		*s2 = tmp;
//		*s1++;
//		*s2++;
//	}
//}
////开始实现升序
////此处用冒泡排序
//void My_qsort(void* base, int sz, int width, int (*cmp)(void*, void*))
//{
//	//传的是不同的函数名，但是接收的都是cmp，所以函数名都是cmp。
//	//函数传过来的是地址，所以可以用函数指针接收
//	//可不可以直接用一个函数接收？就像数组一样？
//	int k = 0;
//	int i = 0;
//	//趟数
//	for (i = 0; i < sz - 1; i++)//sz个元素，只需要sz-1趟
//	{
//		//每趟要比较的次数
//		//每趟除去自身，所以-1
//		//每过一趟，最后一个元素就以确定（-i）
//		for (k = 0; k < sz - 1 - i; k++)
//		{
//			//开始比较两个元素,此处用cmp函数实现
//			//用宽度来实现第一个元素与下一个元素
//			//char* 的类型字节长度为一
//			//将元素地址强制转换为char*类型
//			//元素是几个字节还是几个字节
//			//用元素地址改变元素
//			if (cmp((char*)base + k * width, (char*)base + (k + 1) * width) > 0)
//			{
//				//如果为真，交换这两个元素,
//				//由于数组类型不确定，所以还是要依靠宽度来实现交换
//				Swap((char*)base + k * width, (char*)base + (k + 1) * width, width);
//			}
//
//		}
//	}
//}
//struct stu
//{
//	char name[10];
//	int age;
//};
////比较两个数据的大小，前者大输出大于0的数
////相等输出0，小于输出小于0的数
//// 对于字符串，有一个专门的函数来比较大小。
//int cmp_stu_name(const void* e1,const void* e2)
//{
//	//强行转换为构造体指针类型,构造体名要用括号，再用->指向构造体的元素。
//	//strcmp与cmp一样，输出方式相同。
//	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
//}
//int cmp_stu_age(const void* e1, const void* e2)
//{
//	return (((struct stu*)e1)->age - ((struct stu*)e2)->age);
//}
//int cmp_char_arr(const void* e1, const void* e2)
//{
//	return strcmp( e1,  e2);//这里为什么可以实现啊
//}
//int cmp_int_arr(const void* e1, const void* e2)
//{
//	return (*(int *)e1 - *(int *)e2);
//}
//float cmp_float_arr(const void* e1, const void* e2)
//{
//	return *(float*)e1 - *(float*)e2;
//}
//void test1()
//{
//	//实现任意类型数组升序包括构造体
//	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	//My_qsort(void*，int，int，cmp）
//	//该函数实现升序功能
//	//最后一个参数为实现比较功能的函数
//	//第一个参数为想要升序的数组，第二个为数组长度
//	//第三个为数组宽度（每个元素所占字节长度）
//	//由于要实现不同类型的数组升序，各个类型的数组一个元素所占字节的长度不一样
//	//所以要依靠宽度来完成两个元素的交换。
//	My_qsort(s, sz, sizeof(s[0]), cmp_stu_name);
//} 
//void test2()
//{
//	struct stu s[3] = { {"zhangsan",20},{"lisi",30},{"wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	My_qsort(s, sz, sizeof(s[0]), cmp_stu_age);
//}
//void test3()
//{
//	char arr[] = "acbfehg";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	My_qsort(arr, sz, sizeof(arr[0]), cmp_char_arr);
//}
//void test4()
//{
//	int arr[] = {2,5,69,8,78,3,1,5,4,8};
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	My_qsort(arr, sz, sizeof(arr[0]), cmp_int_arr);
//}
////根据浮点数的在内存中的存储与整数不同
////还无法实现
//void test5()
//{
//	float arr[] = { 2.0,6.9,5.8,5.2,99.6,7.6,8.5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	My_qsort(arr, sz, sizeof(arr[0]), cmp_float_arr);
//}
////先实现一个特定数组的升序，再完善回调函数。 
//int main()
//{
//	//test1();//实现构造体name的升序函数
//	//test2();//实现构造体age的升序函数
//	//test3();//实现char类型数组升序函数
//	test4();//实现int类型数组升序
//	//test5();//实现float类型数组升序
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	//
//	char* c[] = { "ENTER", "NEW","POINT","FIRST" };//
//	//c是数组，存放char*类型的指针。
//	char** cp[] = { c + 3 ,c + 2,c + 1 ,c };
//	//cp是数组存放c数组里面指针的二级数组。
//	char*** cpp = cp;
//	//cpp是指针，三级指针。
//	printf("%s\n", **++cpp);//++自增影响后面cpp的值。
//	//++优先级高
//	//cpp存放的是cp的首元素地址，++就是第二个元素的地址
//	//**解引用，第一个是解出c+2，变成*（c+2）
//    //c+2表示c中第三个元素，即“POINT”；
//	//解引用后即是这个。
//	printf("%s\n", *--*++cpp + 3);//
//	//+3最后运算，先自增，解引用，c + 1
//	//c+1再自减，自减的是cp不是cpp，c，再解引用，“ENTER”，+3，向后移动三位
//	//即“ER”
//    printf("%s\n", *cpp[-2] + 3);
//	//先-2解引用，cpp前面有两次自增，解引用后对应的是c+3
//	//cp有自减不影响cpp解引用，再解引用，“FIRST”，+3后为“ST”；
//	printf("%s\n", cpp[-1][-1] + 1);
//	//-1解引用c+2，再-1为c+1，解引用后为“NEW”+1，为“EW”，不打印
//	/*char *a[] = { "work","at","alibaba" };
//	char**pa = a;
//	pa++;
//	printf("%s\n", *pa);*/
//	retur# 0;
//}
//#include <stdio.h>
//void Char_N(char* arr)
//{
//	char* left = arr;
//	int sz = strlen(arr);
//	char* right = arr + sz - 1;
//	while (left < right)
//	{
//		int ret = *left;
//		*left = *right;
//		*right = ret;
//		left++;
//		right--;
//	}	
//
//}
//int main()
//{
//	char arr[256] = {0};
//	//scanf_s("%s", arr,256);
//	gets(arr);
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	Char_N(arr);
//	printf("%s\n", arr);
//	return 0;
//
//}
//int main()
//{
//	int n = 0, a,x;
//	scanf_s("%d%d", &a,&x);
//	int i;
//	int k = a;
//	for (i = 0; i < x; i++)
//	{
//		n += a;
//		int j = a * 10;
//		a = j + k;
//	}
//	printf("%d", n);
//
//	return 0;
//}
#include <math.h>
//int My_pow(int x, int y)
//{
//	int i = 0;
//	int num = 1;
//	for (i = 0; i < y; i++)
//	{
//		num *= x;
//	}
//	return num;
//}
//
//int main()
//{
//
//	int i = 0;
//	//int arr[6] = { 0 };
//	for (i = 0; i <= 100000; i++)
//	{
//		int count = 0;
//		int j = i;
//		while (j)
//		{
//			
//			j /= 10;
//			count++;
//		}
//		int k = 0;
//		int ret = 0;
//		int ii = i;
//		for (k = 0; k < count; k++)
//		{
//			ret +=  pow((ii % 10),count);
//			ii /= 10;
//			/*if (ret > i)
//				continue;*/
//		}
//		/*int ret = 0;
//		for (k = 0; k < count; k++)
//		{
//			ret += arr[k] * count;
//			
//		}*/
//		if (ret == i)
//			printf("%d ", ret);
//	}
//	return 0;
//}
//2222222222222222222222222
//int main()
//{
//	int w, h;
//	scanf_s("%d%d", &w, &h);
//	
//	
//		/*if (l % 2 == 0 || w % 2 == 0)
//		{
//			printf("请输入奇数");
//		}*/
//		int numw = w;
//		int numl = h;
//		int s2 = h / 2 + 1;
//		int s1 = w / 2 + 1;
//		for (int k = 0; k < w; k++)
//		{
//			for (int i = s2,j = s2; i > 0,j < w; i--,j++)
//			{
//				if (i > s1 - k && j < s1 + k)
//					printf("*");
//				else
//					printf(" ");
//			}
//			printf("\n");
//		}
//		//break;
//	//}
//	return 0;
//}




//待优化，只能打印H，W 相同且是奇数的棱形。
//int main()
//{
//	int H, W;
//	scanf_s("%d%d", &H ,&W);
//	int i, k;//i--H;k--W
//	int s1 = H / 2 + 1;
//	int s2 = W / 2 + 1;
//	for (i = 0; i < s1; i++)
//	{
//		for (k = 0; k < W; k++)
//		{
//			if (k >= s2 - i - 1 && k <= s2 + i - 1)
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	for (i = s1 - 1; i > 0; i--)
//	{
//		for (k = W; k > 0; k--)//3
//		{
//			if (k >= s2 - i + 1 && k <= s2 + i - 1)//k >= 2-1+1,k <= 2+1+1
//				printf("*");
//			else
//				printf(" ");
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int k, n;
//	scanf_s("%d%d", &k, &n);
//	int x;
//	if (n == 0)
//		x = 0;
//	else
//	 x = (k * n - 1) / (k - 1);
//	printf("%d", x);
//	return 0;
//}
//void Move(int* arr, int sz)
//{
//	int* l = arr;
//	//int* r = arr[sz-1];
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < sz; i++)
//	{
//		if ((*(l + i)) % 2 == 1)
//		{
//			int ret = *(l + i);
//			*(l + i) = arr[num];
//			arr[num] = ret;
//		
//			num++;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,6,5,4,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Move(arr, sz);
//	return 0;
//}
//int main()
//{
//	unsigned int a = 0x1234;
//	unsigned char b = *(unsigned char*)&a;
//	/*unsigned char a = 200;
//	unsigned char b = 100;
//	unsigned char c = 0;
//	c = a + b;*/
//	printf("%d", b);//小段为52，大段为0
//
//	return 0;
//}
//#include <string.h>
//int main()
//{
//	char a[1000] = { 0 };
//	int i = 0;
//	for (i = 0; i < 1000; i++)
//	{
//		a[i] = -1 - i;
//	}
//	printf("%zd", strlen(a));
//	return 0;
//}
//int main()
//{
//	int n ;
//	scanf_s("%d", &n);
//	int i = 0;
//	int arr[10][10] = { 0 };
//	arr[0][0] = 1;
//	printf("%d\n",arr[0][0]);
//	for (i = 1; i < n; i++)
//	{
//		int k = 0;
//		for (k = 0; k <= i; k++)
//		{
//			if (k == 0 || k == i)
//			{
//				arr[i][k] = 1;
//				printf("%d ", arr[i][k]);
//			}
//			else
//			{
//				arr[i][k] = arr[i - 1][k - 1] + arr[i - 1][k];
//				printf("%d ", arr[i][k]);
//
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
	//int a = 0,b = 0,c = 0,d = 0;
	//int arr[4] = { a,b,c,d };
	////while (a + b + c + d)
	////{

	////}
	//int A, B, C, D;
	//if (a = 1)
	//{
	//	A = 0;
	//	B = 0;
	//	C = 0;
	//	D = 1;
	//	if (A + B + C + D == 3)
	//		printf("a");
	//}
	/*int k = 0;
	for (k = 'a'; k <= 'd'; k++)
	{
		if ((k != 'a') + (k == 'c') + (k == 'd') + (k != 'd') == 3)
		{ 
			printf("%c\n", k);

		}
	}
	return 0;
}*/
//void judy(int x, int n, int w,int* count)
//{
//	int i = 0;
//	if (x > w)
//	{
//		while (x > w)
//		{
//			(*count)++;
//			i++;
//			x -= n;
//		}
//		x = w * i + x;
//		judy(x, n, w, count);
//	}
//}
//int main()
//{
//	int x = 36;
//	int n = 6;
//	int w = 3;
//	int i = 0;
//	int count = 0;
//	judy(x, n, w,&count);
//	/*while (x)
//	{
//		count++;
//		x -= 6;
//	}*/
//	printf("%d", count);
//	//printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//	for (a = 1; a < 6; a++)
//	{
//		for (b = 1; b < 6; b++)
//		{
//			for (c = 1; c < 6; c++)
//			{
//				for (d = 1; d < 6; d++)
//				{
//					for (e = 1; e < 6; e++)
//					{
//						if ((b == 2) + (a == 3) == 1 &&
//							(b == 2) + (e == 4) == 1 &&
//							(c == 1) + (d == 2) == 1 &&
//							(c == 5) + (d == 3) == 1 &&
//							(e == 4) + (a == 1) == 1)
//						{
//							if (a * b * c * d * e == 120)
//							{
//								printf("%d %d %d %d %d\n", a, b, c, d, e);
//							}
//						}
//					}
//				}
//			}
//		}
//	}	
//	return 0;
//}8888888888888888
//int main()
//{
//	int(*(*arr)[10])(int*);
//	int (*(*F)(int, int))(int);
//	int* p = "hello wrold";
//	printf("%c", *p);
//	return 0;
//}888888888888888
//void turnleft(char* arr, int n,int sz)
//{
//	if (n != 0)
//	{
//		int ret = arr[0];
//		int i = 0;
//		for (i = 1; i < sz; i++)
//		{
//			arr[i - 1] = arr[i];
//		}
//		arr[sz - 1] = ret;
//		n--;
//		turnleft(arr, n, sz);
//	}
//}
//int main()
//{
//	char arr[] = "abcdefd";
//	int n = 3;
//	int sz = strlen(arr);
//	scanf_s("%d", &n);
//	turnleft(arr, n,sz);
//	int i = 0;
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%c ", arr[i]);
//	}*/
//	printf("%s", arr);
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	int n = 3;
//	int sz = strlen(arr);
//	int i = 0;
//	char ret = *arr;
//	/*for (i = 0; i < n - 1; i++)
//	{
//		*(arr + i) = *(arr + i + 1);
//	}*/
//	for (i = 0; i < n - 1; i++) 
//	{
//		*(arr + i) = *(arr + i + 1);
//	}
//	*(arr + n - 1) = ret;
//	ret = *(arr + n);
//	for (i = n ; i < sz - 1; i++)
//	{
//		*(arr + i) = *(arr + i + 1);
//	}
//	*(arr + sz - 1) = ret;
//
//	//ret = *arr;
//	/*for (i = 0; i < sz - 1; i++)
//	{
//		*(arr + i) = *(arr + i + 1);
//	}*/
//	//*(arr + sz - 1) = ret;
//	printf("%s", arr);
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdefgh";
//	int sz = strlen(arr);
//	int n = 3;
//	int s = n;
//	int r = sz;
//	while (s <= n/2)
//	{
//		char ret = *(arr + (n-s));
//		*(arr + (n - s)) = *(arr + s - 1);
//		*(arr + s - 1) = ret;
//		s--;
//	}
//	while (r <= (sz-n)/2)
//	{
//		char ret = *(arr + n);
//		*(arr +  n ) = *(arr + r - 1);
//		*(arr + r - 1) = ret;
//		r--;
//	}
//	int num = sz;
//	while (num <= sz / 2)
//	{
//		char ret = *(arr + sz - num);
//		*(arr + sz - num) = *(arr + num - 1);
//		*(arr + num - 1) = ret;
//	}
//	printf("%s", arr);
//	return 0;
//}
//void turnleft(char* arr, int n, int sz)
//{
//	if (n != 0)
//	{
//		int ret = arr[0];
//		int i = 0;
//		for (i = 1; i < sz; i++)
//		{
//			arr[i - 1] = arr[i];
//		}
//		arr[sz - 1] = ret;
//		n--;
//		turnleft(arr, n, sz);
//	}
//}
//int main()
//{
//
//	return 0;
//int main()
//{int judy(char* arr1, char* arr2)
//{
//	int sz = strlen(arr2);
//	int num = sz;	
//	int i = 0,k;
//	for (k = 0; k < sz; k++)
//	{
//		int count = 0;
//		for (i = sz - num; i < sz; i++)
//		{
//			
//			{
//				count++;
//				if (count == num)
//					return 1;
//			}
//
//		}
//		sz++;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "cdefab";
//	int ret = judy(arr1, arr2);
//	if (ret == 1)
//		printf("Yes");
//	else
//		printf("No");
//	return 0;
//
//}
//#include <stdio.h>
//int judy(char* arr1, char* arr2)
//{
//	int sz = strlen(arr2);
//	int num = sz;
//	int i = 0, k;
//	for (k = 0; k < sz; k++)
//	{
//		int count = 0;
//		for (i = sz - num; i < sz; i++)
//		{
//			if (arr1[i] == arr2[i - sz + num])
//			{
//				count++;
//				if (count == num)
//					return 1;
//			}
//
//		}
//		sz++;
//	}
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "defabc";
//	int ret = judy(arr1, arr2);
//	if (ret == 1)
//		printf("Yes");
//	else
//		printf("No");
//	return 0;
//
//}
//	char arr1[] = "abcdefabcdef";
//	char arr2[] = "cdefab";
//	int ret = judy(arr1, arr2);
//	if (ret == 1)
//		printf("Yes");
//	else
//		printf("No");
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//int judy(char* arr1, char* arr2)
//{
//	int len = strlen(arr1);
//	strncat(arr1, arr1, len);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[50] = "abcdef";
//	char arr2[] = "defabc";
//	int ret = judy(arr1, arr2);
//	if (ret == 0)
//		printf("No");
//	else
//		printf("Yes");
//	return 0;
//}
#include <stdio.h>
int main()
{
	int arr[9][9] = { 0 };
	return 0;
}