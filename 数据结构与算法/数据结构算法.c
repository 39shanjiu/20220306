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
//
// /*这是字符串中KMP算法中next值的实现
// next数下标+1表示当前字符处于比较的字符串数量
// 比如，next下标为2，则当前比较的是字符串数量是3.
// 那么next[2] 表示什么呢？表示当前数量的字符串相似程度。
// 这里见《大话数据结构》p116.*/
//
//void Get_Next(char* T, int next[], int sz)
//{
//	//这里next值的实现相当于子串中的相似程度。我知道不好理解，但我也解释不来啊😭
//	int i = 0, k = 0;//这里可以理解为快慢指针（嗯~ o(*￣▽￣*)o）
//	next[0] = 0;//next[0]一定为0
//	next[1] = 1;//
//	//这里算法要实现的重点是看表头与表尾的重合个数
//	//这里i是一直向前的不会后退，最多停留。
//	//具体对应规则详见P-117
//	//这里就三点
//	//第一点，next[i] 的数是相对应的数再加上一。
//	//的二点，无论next[i]有多大，如果i+1不对应，那么后面的数只可能为1和2
//	//i+1与0相同就是2；
//	//第三点（重点），k要同时担任表头的下标与next[i]的赋值。所以下面最主要的处理
//	//就是同时处理好k与两者的关系。
//	for(i = 2;i < sz;i++)//注意i不会后退，最多停留因此为O（n）；
//	{
//		//由于next[0]与next[1]是确定的所以i直接从二开始
//		//为什么是二，因为i要担任next下标，而比较时要比较的字符个数
//		// 等于i的值，所以字符串中最后一位会比较不到，一位i不能大过字符串的长度
//		// 为什么i不能大过字符串的长度？因为next的要与字符串的长度匹配；
//		// 具体为什么见P-116
//		//
//		if (T[i - 1] == T[k])//k = 0进来就直接为二或者不为0也时+1+1增加
//		{
//			//
//			k++;
//			next[i] = k + 1;
//		}
//		else if (k == 0 && T[i - 1] != T[k])//不同那就是1，不同i会在下一次循环停留一次
//		{
//			//给k = 0；好度过这一次的next[i];
//			k++;
//			next[i] = 1;
//		}
//		else
//		{
//			k = 0;
//			i--;
//		}
//		
//	}
//}
//
////这里为升级版的next具体原理，看图解还好
////换成了代码一脸懵。
//
//
//void Get_Nextval(char* T, int* nextval, int sz)
//{
//	int i = 1, k = 0;
//	nextval[0] = 0;
//	for(i = 1; i < sz; i++)
//	{
//		if (T[i] == T[nextval[i] - 1])
//		{
//			int ret = nextval[i] - 1;
//			nextval[i] = nextval[ret];
//		}
//	}
//}
//
//int Index_KMP(char* s, char* T, int pos)
//{
//	int i = pos;//用于表示主串s的下标。
//	int k = 0;//k用于表示子串T的下标。
//	int sz = strlen(T);
//	int next[10];	
//	Get_Next(T, next, sz);//获取next数组。
//	Get_Nextval(T, next, sz);
//	int len = strlen(s);
//	//开始在主串中查找字串。
//	for (i = pos; i < len && k < sz; i++)
//	{
//		if (k == 0 || s[i] == T[k])//注意KMP算法就是去除相似部分的算法时间
//			k++;//这里表示相同计数+1；
//		else//相同到一半又不相同了怎么办（😔摊手）
//			//这里是KMP算法的精妙之处。
//		{
//			k = next[k - 1];//next[k - 1]表示当前子串开始的位置，
//			//这里k与next[k - 1]表示的位子相同，数组从0开始嘛。
//			//这里从next[k - 1]得来的值k，是当前子串长度的表头与表尾的相似度。详见P115.
//			// 相同多少就跳过多少。
//			//P115
//			i--;
//
//		}
//	}
//	if (k == sz)
//		return i - sz;
//	else
//		return -1;
//}
//
//int main()
//{
//	char S[] = "nmjiyababaaabahjklknl";
//	char T[] = "ababaaaba";
//	
//	int ret = Index_KMP(S,T,0);
//	printf("在主串下标为 %d 的位子 ", ret);
//	
//	return 0;
//}

//
//int main()
//{
//	char T[] = "abcabx";
//	int sz = 6;
//	int next[6];
//	int i = 0, k = 0, count = 1;//这里可以理解为快慢指针（嗯~ o(*￣▽￣*)o）
//	next[0] = 0;//next[0]一定为0
//	next[1] = 1;
//	for (i = 2; i < sz; i++)//注意i不会后退，最多停留因此为O（n）；
//	{
//		if (T[i - 1] == T[k])
//		{
//			k++;
//			next[i] = k + 1;
//		}
//		else if (k == 0 && T[i - 1] != T[k])
//		{
//			k++;
//			next[i] = 1;
//		}
//		else
//		{
//			k = 0;
//			i--;
//		}
//
//	}
//	return 0;
//}

//
//int main()
//{
//	int a, b, c, i;
//
//	return 0;
//}

//int main()
//{
//	int count = 0;
//	int x = 1;
//	while (x < 1000000000)
//	{
//		x += (x + 1);
//		count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//
//typedef struct BT
//{
//	int valx;
//    int valy;
//	struct BT* left;
//	struct BT* right;
//}BT;
//void Great_BT(int sx, int sy, const int tx, const int ty, BT* t, int* count)
//{
//    if (sx > tx || sy > ty)
//    {
//        t = NULL;
//        return;
//    }
//    else
//    {
//        BT* node = (BT*)malloc(sizeof(BT));
//        t = node;
//        t->valx = sx;
//        t->valy = sy;
//    }
//    if (sx == tx && sy == ty)
//    {
//        *count = 1;
//        return;
//    }
//    Great_BT(sx + sx, sy, tx, ty, t->left, count);
//    Great_BT(sx, sy + sy, tx, ty, t->right, count);
//}
//
//int main()
//{
//    int sx = 1, sy = 1, tx = 3, ty = 5;
//    BT* root = (BT*)malloc(sizeof(BT)), * t = root;
//    int count = 0;
//    if (sx > tx || sy > ty)
//        return 0;
//    Great_BT(sx, sy, tx, ty, t, &count);
//    
//    printf("%d ",count);
//	return 0;
//}
//
//
//struct TreeNode
//{
//    int val;
//    struct TreeNode* left;
//    struct TreeNode* right;
//};
//
//
//int* postorderTraversal(struct TreeNode* root, int* returnSize) {
//    int* arr = (int*)malloc(sizeof(int) * 101);
//    *returnSize = 0;
//    struct TreeNode* stk[101], * node = root, * prve = NULL;
//    int sum = 0;
//    while (sum > 0 || node)
//    {
//        while (node)
//        {
//            stk[sum++] = node;
//            node = node->left;
//        }
//        node = stk[--sum];
//        if (node->right == NULL || node->right == prve)
//        {
//            arr[(*returnSize)++] = node->val;
//            prve = node;
//            node = NULL;
//        }
//        else
//        {
//            stk[sum++] = node;
//            node = node->right;
//        }
//    }
//    return arr;
//}
//
//
//int main()
//{
//    int returnSize = 0;
//    struct TreeNode* root, * t = root;
//    root->val = 1;
//    root->left = NULL;
//    t = t->right;
//    t->val = 2;
//    t->right = NULL;
//    t = t->left;
//    t->val = 3;
//    t->right = NULL;
//    t->left = NULL;
//    postorderTraversal(root, &returnSize);
//    return 0;
//}

//
//int main()
//{
//	int* a = NULL;
//	int* b = NULL;
//	if (a == b)
//		printf("haha");
//	else
//		printf("hehe");
//	return 0;
//}
//
//void BT(struct TreeNode* stk, struct TreeNode* t, int val, struct TreeNode* prev)
//{
//    if (!t)
//        return;
//    if (val > t->val)
//    {
//        prev = t;
//        t = t->left;
//        if (t->val > val)
//        {
//            struct TreeNode* m = t->right;
//            while (m && m->val > val)
//            {
//                m = m->val;
//            }
//        }
//    }
//    else
//    {
//        prev = t;
//
//    }
//
//
//}
//
//struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
//    struct TreeNode* stk = (struct TreeNode*)malloc(sizeof(struct TreeNode)), * t = root, * prev;
//    stk->val = val;
//    stk->right = NULL;
//    stk->left = NULL;
//    BT(stk, t, val, prev);
//    if (stk->right && stk->left)
//    {
//        if (val > prev->val)
//        {
//            prev->right = stk;
//        }
//        else
//            prev->left = stk;
//    }
//    return root;
//}

//
//struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//    int count = 0;
//    struct ListNode* t = (struct ListNode*)malloc(sizeof(struct ListNode)), * prev;
//    t = l2;
//    while (l1 && l2)
//    {
//        int a = l1->val;
//        int b = l2->val;
//        int c = a + b + count;
//        if (c >= 10)
//        {
//            l2->val = c - 10;
//            count = 1;
//        }
//        else
//        {
//            l2->val = c;
//            count = 0;
//        }
//        prev = l2;
//        l2 = l2->next;
//        l1 = l1->next;
//    }
//    if (l2 == NULL && l1 != NULL)
//    {
//        prev->next = l1;
//        while (l1 && count == 1)
//        {
//            int a = l1->val + count;
//            if (a >= 10)
//            {
//                l1->val = a - 10;
//                count = 1;
//            }
//            else
//            {
//                l1->val = a;
//                count = 0;
//            }
//            prev = l1;
//            l1 = l1->next;
//        }
//    }
//    else if (l1 == NULL && l2 != NULL && count == 1)
//    {
//        while (l2 && count == 1)
//        {
//            int a = l2->val + count;
//            if (a >= 10)
//            {
//                l2->val = a - 10;
//                count = 1;
//            }
//            else
//            {
//                l2->val = a;
//                count = 0;
//            }
//            prev = l2;
//            l2 = l2->next;
//        }
//    }
//    if (!l2 && !l1 && count == 1)
//    {
//        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//        node->val = 1;
//        prev->next = node;
//        node->next = NULL;
//    }
//    return t;
//}

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;//returnSize表示的是返回数组的行
    if (!root)
        return NULL;
    int** rslt = (int**)malloc(sizeof(int*) * 2000);//这是要返回的数组，一共有两千个结点。
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);//那么columnsize当然就是列了。
    int front = 0, rear = 0, prev;//三个数分别代表队前，队尾，二叉树的每层。
    int i = 0;//相当于returnSize
    int j = 0;//每一行的[i][j];
    struct TreeNode* qnueu[2001];//队列
    struct TreeNode* pNode;
    qnueu[rear++] = root;
    while (front < rear)//队列不为空，继续循环
    {
        prev = rear;//此时prev表示当前层数的最后一个数。
        rslt[i] = (int*)malloc(sizeof(int) * (prev - front));//为每一行的rslt开辟空间，空间大小就是当前层数的数 - 上一层的数
        (*returnColumnSizes)[i] = (prev - front);//同时，要求返回的数组也要赋值相同大小的空间。一个*表示一级解引用，一个表示行，两个表示列。
        while (front < prev)
        {
            pNode = qnueu[front++];
            rslt[i][j++] = pNode->val;
            if (pNode->left)
                qnueu[rear++] = pNode->left;
            if (pNode->right)
                qnueu[rear++] = pNode->right;
        }
        i++;
        (*returnSize)++;
        j = 0;
    }
    return rslt;
}

int main()
{
    struct TreeNode* root;
    int* s = NULL;
    int** v = NULL;
    levelOrder(root,s,v);
}