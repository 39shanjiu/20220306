#include <stdio.h>

//void Min_Squret(int* m, int* n)
//{
//	if (*m % *n != 0 && *n % *m != 0)
//	{
//		if (*m > *n)
//		{
//			while (*m > *n)
//			{
//				*m -= *n;
//			}xxxxxxxxxxxxxxxx
//			Min_Squret(&(*n), &(*m));
//		}
//	}
//	//return n;
//}
//
//int main()
//{
//	int m = 1680, n = 640;
//	Min_Squret(&m, &n);
//	printf("%d", n);
//	return 0;
//}

#include <string.h>

#include <stdlib.h>
//
//void Get_Next(char* T, int* next,int sz)
//{
//	int i = 1, k = 0;
//	next[0] = 1;
//	while (i < sz)
//	{
//		if (k == 0 || T[i] == T[k])
//		{
//			i++;
//			k++;
//			next[i - 1] = k;
//		}
//		else
//			k = next[k];
//	}
//}
//
//int main()
//{
//	char T = "abcdex";
//    int sz = strlen(T);
//	int* next = (int*)malloc(sizeof(int) * sz);
//	Get_Next(T, next,sz);
//	return 0;
//}
//void Get_Next(char* T, int* next, int sz)
//{
//	int i = 1, k = 1;
//	next[0] = 0;
//	while (i < sz)
//	{
//		if (k == 1 || T[i] == T[k - 1])
//		{
//			i++;
//			k++;
//			next[i - 1] = k;
//		}
//		else
//		{
//			k = next[k - 1] + 1;
//		}
//	}
//}
//
//int main()
//{
//	char T[] = "abcdex";
//	int sz = strlen(T);
//	int* next = (int*)malloc(sizeof(int) * (sz + 1));
//	Get_Next(T, next, sz);
//	return 0;
//}
//



//
// 这是字符串中KMP算法中next值的实现
// next数下标+1表示当前字符处于比较的字符串数量
// 比如，next下标为2，则当前比较的是字符串数量是3.
// 那么next[2] 表示什么呢？表示当前数量的字符串相似程度。
// 这里见《大话数据结构》p116.
//
void Get_Next(char* T, int* next, int sz)
{
	//这里next值的实现相当于子串中的相似程度。（我知道不好理解，但我也解释不来啊😭
	int i = 0, k = 0;//这里可以理解为快慢指针（嗯~ o(*￣▽￣*)o）
	next[0] = 0;//next[0]一定为0
	for(i = 1;i < sz;i++)//注意i不会后退，最多停留因此为O（n）；
	{
	    if (k == 0 || T[i] == T[k])//???这不就绕出来了嘛
			//这里k==0是重置后重新开始比较后面的字符串，
			//那后面的呢？当然是相同计数+1啊.
		{
			k++;
			next[i] = k;
		}
		else
		{
			k = 0;//不同，看重新赋值
			i--;//i要保留原地。
		}
	}
}

int Index_KMP(char* s, char* T, int pos)
{
	int i = pos;//i用于表示主串s的下标。
	int k = 0;//k用于表示子串T的下标。
	int sz = strlen(T);
	int next[255];
	Get_Next(T, next, sz);//获取next数组。
	int len = strlen(s);
	//开始在主串中查找字串。
	for (i = pos; i < len && k < sz; i++)
	{
		if (k == 0 || s[i] == T[k])//注意KMP算法就是去除相似部分的算法时间
			k++;//这里表示相同计数+1；
		else//相同到一半又不相同了怎么办（😔摊手）
			//这里是KMP算法的精妙之处。
		{
			k = next[k - 1];//next[k - 1]表示当前子串
			//这里k与next[k - 1]表示的位子相同，数组从0开始嘛。
			//这里从next[k - 1]得来的值k，是当前子串长度的表头与表尾的相似度。详见P115.
			// 相同多少就跳过多少。
			//P115
			i--;

		}
	}
	if (k == sz)
		return i - sz;
	else
		return 0;
}

int main()
{
	char S[] = "nmjiyiaabcdexhjklknl";
	char T[] = "abcdex";
	
	int ret = Index_KMP(S,T,0);
	printf("%d ", ret);
	
	return 0;
}

