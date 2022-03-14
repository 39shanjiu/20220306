#include <stdio.h>

#include "井字棋.h"
char ret = 'a';
void menu()
{
	printf("***********************\n");
	printf("* 1. play      0.exit *\n");
	printf("***********************\n");
}
void game()
{
	char arr[R][C] = { 0 };//用二维数组模拟棋盘，元素为0不打印。
	remakeqipan(arr, R, C);//初始化棋盘
	qipan(arr, R, C);//创建棋盘
	 //开始游玩
	while (1)
	{
		//一方移动后要打印相应的棋盘，再判断棋盘状态。
		playermove(arr,R,C);//玩家移动
		qipan(arr, R, C);//移动后再打印棋盘
		win(arr,R,C);//判断是否胜利
		ret = win(arr, R, C);
		if (ret != 'G')//G为棋盘没满，并且还没有胜方。
		{
			break;//如果不为G则为某方胜利或者和棋.结束循环
		}
		computermove(arr,R,C);//同上
		qipan(arr, R, C);//同上
		win(arr, R, C);//同上
		ret = win(arr, R, C);//同上
		if (ret != 'G')
		{
			break;//同上
		}
	}   
	//先循环结束再判断结束循环为何种情况.
	if (ret == 'Q')
	{
		printf("平局\n");
	
	}
	else if (ret == 'x')
	{
		printf("you win\n");
	
	}
	else if (ret == '#')
	{
		printf("you default\n");
	}
}
void test()
{
	int n = 0;
	do
	{
		menu();//游戏菜单
		srand((unsigned int)time(NULL));
		printf("请选择： ");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			printf("井字棋\n");
			game();//游戏主体
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} 
	while (n);//do while 循环 ；
}

int main()
{
	test();
	return 0;
}
//int main()
//{
//	int arr[] = { 1,2,3 };
//	printf("%p\n", arr);//取首地址
//	printf("%p\n", arr+1);//加一后是下个元素的地址
//	printf("%p\n", &arr[0]);//取首地址
//	printf("%p\n", &arr[0]+1);//同上
//	printf("%p\n", &arr);//取数组地址
//	printf("%p\n", &arr+1);//加一后直接跳到最后一个数的后面
//	return 0;
//}
//void judy(int arr[],int sz)
//{
//	//int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int k = 0;
//	int n = 0;
//	while (n < sz)
//	{
//		n++;
//		for (i = 0; i < sz -n; i++)
//		{
//			if (arr[i] > arr[i + 1])
//				k = arr[i + 1];
//				arr[i + 1] = arr[i];
//				arr[i] = k;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	judy(arr,sz);
//	int m = 0;
//	for (m = 0; m < sz; m++)
//	{
//		printf("%d ", arr[m]);
//	}
//	//传过去的是arr的首地址。
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//void move(char X, char Y)
//{
//	printf("%c->%c ", X, Y);
//}
//
//void HanoiTower(int n, char A, char B, char C)
//{
//	if (n == 1)//递归终止条件
//	{
//		move(A, C);
//		return;
//	}
//
//	else
//	{
//		HanoiTower(n - 1, A, C, B);//将n-1个环从A柱子放到B柱子上，C柱子作为中介
//		move(A, C);//将A柱子上的最后一个环移动到C柱子上
//		HanoiTower(n - 1, B, A, C);//将n-1个环从B柱子放到C柱子上，A柱子作为中介
//	}
//}
//int main()
//{
//	printf("请确认A柱子上一共有多少个环:\n");
//	int n = 0;
//	scanf_s("%d", &n);
//	HanoiTower(n, 'A', 'B', 'C');//将n个环从A柱子放到C柱子上，B柱子作为中介
//	return 0;
//}
//
//
//
//#include <stdio.h>
//void move(char A, char B)
//{
//	printf("%c->%c ", A, B);
//}
//void hnt(int n, char A, char B, char C)
//{
//	if (n == 1)
//	{
//		move(A, C);
//		return;
//	}
//	else 
//	{
//		hnt(n - 1, A, C, B);
//		move(A, C);
//		hnt(n - 1, B, A, C);
//	}
//}
//int main()
//{
//	printf("柱子上环的个数:");
//	int n = 0;
//	scanf_s("%d", &n) ;
//	hnt(n, 'A', 'B', 'C');
//	return 0;
//}
/*nt main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	int i = 0;
	for (i = 0; i <= 11; i++)
	{
		printf("%p ", &arr[i]);
	}*/
	//char arr[] = "abcdef";
	//printf("%d\n", sizeof(arr));//7
	////sizeof计算arr所占空间大小
	//printf("%d\n", strlen(arr));//6
	////strlen是求arr的长度，遇/0停止

//int main()
//{
//	int arra[3] = { 3, 2, 1 };
//	int arrb[3] = { 0 };
//	int arrc[3] = { 0 };
//
//	return 0;
//}
//int a = 1;
//int b = 1;
//int c = 0;
//int judy(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//	{
//		int i = 0;
//		for (i = 3; i <= n; i++)
//		{
//			c = a + b;
//			a = b;
//			b = c;
//		}
//	}
//	return c;
//}
//{
//	if (n <= 2)
//		return 1;
//	else
//	{
//		return n = judy(n - 2) + judy(n - 1);
//	}
//}
//int main()
//{
//	int num = 0;
//	scanf_s("%d", &num);
//	printf("%d", judy(num));
//	return 0;
//}
//int judy(int m)
//{
//	if (m <= 1)
//		return 1;
//	else
//		return m * judy(m - 1);
//	/*if (m != 1)
//	{
//		m--;
//		m = (m + 1) * judy(m);
//	}
//	return m;*/
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	printf("%d", judy(n));
//	return 0;
//}
/*int my_strlen(char* str)
{
	if (*str != '\0')
		return 1 + my_strlen(str + 1);
	else
		return 0;
}*/
/*
	int i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return i;
}*/
/*int main()
{
	char arr[] = "zhe";
	int len = my_strlen(arr);
	printf("len = %d", len);
	return 0;
}
 /*void judy(int n)
{
	 if (n > 9)
	 {
		 judy(n / 10);
	 }
	 printf("%d ", n % 10);
}
int main()
{
	unsigned int num = 0; 
	scanf_s("%d", &num);
	judy(num);
	return 0;
}*/
//int main()
//{
//	int i = 1234;
//	if(judy(i) == 1)
//
//	return 0;
//}
///*nt main()
//{
	/*printf("hehe\n");
	main();
	return 0;
}*/

//int judy(int n, int m)
//{	
//	int left = 0;
//	int right = m;
//	int mid = (left + right) / 2;
//	while (1)
//	{
//		if (n < mid + 1)
//		{
//			right = mid;
//			mid = (left + right) / 2;
//		}
//	    if (n > mid + 1)
//	    {
//		left = mid;
//		mid = (left + right) / 2;
//	    }
//	    if (n = mid + 1)
//		break;
//    }
//	return 1;
//}
//int main()
//{
//	char arr[] = { 1,2,3,4,5,6,7,8,9,10 };	
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 10;	
//	if (judy(i , sz) == 1)
//		printf("%d ", i);
//	return 0;
//}
//int jud(int n)
//{
//	if ((n % 100 == 0 && n % 400 != 0) || (n % 4 == 0))
//		return 1;
//	else 
//		return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i = i + 4)
//	{
//		if (jud(i) == 1)
//			printf("%d ", i);
//	}
//		return 0;
//}
//int is_prime(int n)
//{
//	int m = 0;
//	for (m = 2; m <= 15; m++)
//	{
//		if (n % m == 0)
//			return 2;		
//	}	
//	return 1;
//}
//int main()
//{
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//			printf("%d ", i);
//	}
//	return 0;
//}
//sqr(int* pa)
//{
//	int k = 0;
//	int i = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		for (k = 2; k <= i / 2; k++);
//		{
//			if (i % k == 0)
//				break;
//			else if (k == i / 2)
//				return i;
//		}
//	}
//}
//int main()
//{
//	int a = 0;
//
//	return 0;
//}
/*int main()
{
	char arr[] = "hello wrold";
	memset(arr, '!', 5);
	printf("%s\n", arr);
	return 0;
}*/
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void meau()
{
	printf("----------------\n");
	printf("1.play   0.exit \n");
	printf("----------------\n");
}
void game()
{
	int guess = 0;
	printf("猜数字\n");
	int ret = 0;
	ret = rand() % 100 + 1;
	
	while (1)
	{
		printf("");
		scanf_s("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
	printf("%d\n", ret);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		meau();
		printf(" 请输入：");
		scanf_s("%d", &input);
		switch(input)
		{
		case 1:
				game();
				break;
		case 0:
				printf("退出游戏\n");
				break;
		default:
			printf("无法识别，请重新输入\n");
				break;
		}
	} while (input);
	return 0;
}*/
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 100; i <= 200 ; i++)
//	{		
//		for (k = 2; k <= 100; k++)			 
//			if (i % k == 0)			
//				break;
//			else if (k == 100)
//				printf("%d ", i);										
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (i % 400 == 0)
//		{
//			printf("%d ", i);
//			//continue;
//		}
//		//if (i % 100 == 0)
//		/*{
//			continue;
//		}*/
//		if (i % 4 == 0 && i % 100 != 0)
//			printf("%d ", i);
//	}
//	return 0;
//
//}
////{
//	int a = 0;
//	int b = 0;
//	int r = 0;
//	scanf_s("%d%d", &a, &b);
//	while (a % b != 0)
//	{
//		r = a % b;
//		a = b;
//		b = r;
//	}
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//		if (0 == i % 3)
//			printf("%d ", i);
//	return 0;
//}
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	//int arr[] = { 2, 8, 6 };
//	
//		
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int k = 0;
//	int sum = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		k = 1;
//		for (k = 1;k < i;k++)
//		{
//			sum = k * i;
//			printf("%d*%d=%-2d  ", k, i, i*k);
//		}
//		if (k = i)
//		{
//			sum = k * i;
//			printf("%d*%d=%-2d\n", k, i, i*k);
//			k++;
//	}
//	return 0;
//}
//{ 
//	int i = 0;
//	int arr[] = { -1,-2,-3,-4,-5,-6,-7,-8,-9,-10 };
//	int max = arr[0];
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 1; i <= sz; i++)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d",max);
//	return 0;
//}
////{
	/*int i = 0;
	double sum1 = 0.0;
	int flag = 1;
	double sum2 = 0.0;
	for (i = 1; i <= 100; i = i +2)
	{

		sum1 += 1.0 / i;
		flag = -flag;
	}
	for (i = 2; i <= 100; i = i + 2)
	{
		sum2 += 1.0 / i;
	}
	double sum3 = 0.0;
	sum3 = sum1 - sum2;
	printf("%lf ", sum3);*/
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i < 100; i++)
//	{
//		if (i / 10 == 9)
//		
//			count++;
//			//printf("%d ", i);
//		
//		 if (i % 10 == 9)
//			count++;
//	}
//			printf("%d ", count);
//	
//	return 0;
//}
//{
//	int l = 0;
//	char arr1[] =  "Hello World" ;
//	char arr2[] =  "###########" ;
//	int r = strlen(arr2) - 1;
//	while (l <= r)
//	{
//		arr2[r] = arr1[r];
//		arr2[l] = arr1[l];
//		r--;
//		l++;
//		printf("%s\n", arr2);
//	}
//
//	return 0;
//}
//int main()
//{
//	int k = 7;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int r = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int l = sz - 1;
//	while (r <= l)
//	{
//		int m = (r + l) / 2;
//		if (k > arr[m])
//		{
//			r = m + 1;
//		}
//		else if (k < arr[m])
//		{
//			l = m - 1;
//
//		}
//		else
//		{
//			printf("%d\n", m);
//			break;
//		}
//	}
//	if (r > l)
//	{
//		printf("404not found");
//	}
//	return 0;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//
//	for (i = 0; i <= sz; i++)
//	{
//		if (k ==arr[ i])
//		{
//			printf("找到了%d", i);
//				break;
//		}
//	}
//	if (i == sz)
//		printf("找不到");
//	return 0;
//}
////int main()
//{
//	int i = 0;
//	int ret = 1;
//	int sum = 0;
//	for (i = 1; i <= 4; i++)
//	{
//		ret = ret * i;
//		sum = sum + ret;
//
//	}
//	printf("%d", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//	//int n = 0;
//	for (n = 1; n <= 10; n++)
//	{
//		ret = 1;
//		for (i = 1; i <= n; i++)
//		{
//			
//			ret = ret * i;
//		}
//		sum = sum + ret;
//		//第一次 ret = 1
//	}
	/*printf("%d", sum);
	return 0;
}*/
/*{
	int i = 0;
	int n = 0;
	int ret = 1;
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		ret = ret * i;
		
	}
	printf("%d", ret);
	return 0;
}*///n的阶乘
	/*int n = 0;
	for (n = 0; n < 10; n++)
	{
		printf("%d")
	}
	return 0;
}*/
//int main()
//{
//	int n = 0;
//	for(n = 10; n == 1; n--)
//	{
//		if(n != 0)
//		printf("%d ", n);
//	}
//	return 0;
//}
//int main()
//{
//	int i = 1;
//	do
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);
//		i++;
//	}
//	while (i < 11);
//	return 0;
//}

//	int i = 0;
//	int k = 0;do
//	for (i = 0, k = 0; k = 0; i++, k++)
//		k++;
//	printf("%d ", k);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 10; i++)
//	{
//		printf("%d ", i);
//	}
//int
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		//printf("%d ", i);
//		if (i == 5)
//			//break;
//			continue;
//		printf("%d ", i);
//
//		//printf("%d ", i);
//	}
//	//putchar();
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}
//int main()
//{
//	int ret = 0;
//	int ch = 0;
//	char password[20] = { 0 };
//	printf("请输入密码：");
//	scanf_s("%d", password);
//	printf("请确认:（Y/N)");
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("输入成功");
//	}
//	else
//	{
//			printf("请重新输入");
//	}
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		putchar(ch);
//	}
//	return 0;
// }
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		i++;
//		if (i == 5)
//			continue;
//		printf("%d\n", i);
//		
//	}
//	return 0;
//}
//int main()
//{
//	int n = 1;
//	int m = 2;
//	switch (n)
//	{
//	case 1:
//		m++;
//	case 2:
//		n++;
//	case 3:
//		switch (n)
//		{
//		case 1:
//			n++;
//		case 2:
//			m++;
//			n++;
//			break;
//		}
//	case 4:
//		m++;
//	default:
//		break;
//	}
//	printf("%d %d\n", n, m);
//
//	return 0;
//}
////int main()
////{
////	int i = 1;
////	while (i < 100)
////	{
////		if (0 != i % 2)
////			printf("%d\n", i);
////		i++;
////	}
////	return 0;
////}

//int main()
//{
//	int a = 4;
//		if (5 == a)
//		{
//			printf("hehe\n");
//		}
//	return 0;
//
//}
	/*int a = 0;
	int b = 2;
	if (a == 0)
	    if (b == 1)
	       printf("hehe\n");
	    else
		   printf("haha\n");

	return 0;
}*/
//{
//	int age = 20;
//	if (18 <= age && age<28);
//	printf(" 青年\n");
//
//	return 0;
//}
//struct book
//{
//	char name[10];
//
//	short price;
//};
//int main()
//{
//	struct book a1 = { "人生海海", 40};
//	struct book* pb = &a1;
//	printf("%s\n", pb->name);
//	printf("%d\n", pb->price);
//if
//printf("价格=%d\n", a1.price);*/

	//return 0;
//}
	/*{*/
	//double b = 3.14;
	//double* pb = &b;
	////pb = 5.5;
	//printf("%d\n", sizeof(pb));




	//	return 0;
	//}

//int Anshu(int x, int y)
//{
//	if (x > y)
//		return x;
//	else
//		return y;
//}
//int zh(int x, int y, int z)
//{

//}
//int main()
//{
//	int a = 10;
//	int b = ++a;
	//printf(" %d  %d\n", b, a);
	//int a = 10;
	//int b = 100;
	//int max = 0;
	// max = Anshu(a, b);
	////if (a > b)
	//	printf("%d\n",max);
	//else
		//printf("%d\n",b);
	//printf("%d\n", sizeof(char)/);
	//printf("%d\n", sizeof(short));
	//printf("%d\n", sizeof(int));
	//printf("%d\n", sizeof(long ));
	//printf("%d\n", sizeof(long long));
	//printf("%d\n", sizeof(float ));

	//printf("%d\n", sizeof(double));
	/*int input = 0;
	printf("你要好好学习吗？（1/0）>:");

	scanf_s(" %d", &input);
	if (input == 1)
		printf("give you a good offer\n");
	else
		printf("getout\n");*/
	/*int line = 0;
	while (line < 20000)
	{
		printf("hhxuexi\n");
		line++;
	}
	if (line>=20000)
	printf("good offer\n");
		return  0;*/
	/*int sum = 0;
	int a = 200;

	int b = 100;
	sum = add(a, b);
	printf("sum = %d\n", sum);
	return 0;*/
//	return 0;
//