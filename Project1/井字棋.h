//宏定义 R 和 C 后面不要加  ；
#define R 3
#define C 3
#include <stdlib.h>
#include <time.h>

void qipan(char arr[R][C], int r, int c);
void remakeqipan(char arr[R][C], int r, int c);
void playermove(char arr[R][C], int r, int c);
void computermove(char arr[R][C], int r, int c);
//棋盘有四种状态
//1.玩家赢
//2.电脑赢
//3.和棋
//4.继续
char win(char arr[R][C], int r, int c);