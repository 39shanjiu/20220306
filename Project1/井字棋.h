//�궨�� R �� C ���治Ҫ��  ��
#define R 3
#define C 3
#include <stdlib.h>
#include <time.h>

void qipan(char arr[R][C], int r, int c);
void remakeqipan(char arr[R][C], int r, int c);
void playermove(char arr[R][C], int r, int c);
void computermove(char arr[R][C], int r, int c);
//����������״̬
//1.���Ӯ
//2.����Ӯ
//3.����
//4.����
char win(char arr[R][C], int r, int c);