#include <stdio.h>
#include <stdlib.h>
//引用头文件（rand和srand函数）
//rand--产生一个随机数（0到0x7fffff（十六进制))但是产生的数有固定排序，无法到达真正的随机；
//此时要用srand函数--可以指定rand产生指定次数的随机数。但是srand的指定次数也要一个随机数才能让sand
//到达接近随机，所以还要引进一个函数time。
//srand((unsigned int)time(NULL));引用time函数
#include <time.h>
//引用头文件（time）时间戳
//time函数可以根据时间产生一个数（现在的时间减去1970年1月1日再转换成一个数）所用单位为毫秒和秒，所以可以
//用时间来达到随机；
//2.菜单
void meau()
{
	printf("----------------\n");
	printf("1.play   0.exit \n");
	printf("----------------\n");
}
//游戏主体.
void game()
{
	int guess = 0;
	printf("猜数字\n");
	int ret = 0;
	ret = rand() % 100 + 1;//rand的随机数范围过大，用 % 把范围改为1 ~ 100.

	while (1)//1为真，开始循环.
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
//开始设计猜数字游戏
//1.产生一个1 ~ 100 的随机数
//2.开始菜单
//3.输入按键开始游戏
//4.输入所猜数字给予相应提示。
//5.猜对结束游戏。重新进入菜单选择.
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do//先进行后循环.
	{
		meau();
		//菜单 -- 设计菜单
		printf(" 请输入：");
		scanf_s("%d", &input);//3.输入数字开始游戏
		switch (input)
		{
		case 1:
			game();//游戏主题.
			break;//结束switch循环重新进入do while循环.
		case 0:
			printf("退出游戏\n");
			break;//同上
		default:
			printf("无法识别，请重新输入\n");
			break;//同上
		}//3.输入数字开始游戏.
	} while (input);//input while判断条件0为假 结束循环与上面 0 退出游戏对应.
	return 0;
}