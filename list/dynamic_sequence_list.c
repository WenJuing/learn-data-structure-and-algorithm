#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define MAX_LEN 10
/** 动态顺序表的基本使用 */
typedef struct seqlist
{
    int * pBase;    // 数组地址（即第一个元素的地址）
    int length;     // 最大长度
    int cnt;        // 有效长度
} SeqList;
void initList(SeqList * pL);
void traverseList(SeqList * pL);
void increaseSize(SeqList * pL, int len);

int main(void)
{
    SeqList L;
    initList(&L);
    traverseList(&L);
    increaseSize(&L, 5);
    printf("\n");
    traverseList(&L);
    system("pause");
    return 0;
}
void initList(SeqList * pL)
{
    pL->pBase = (int*)malloc(sizeof(int)*MAX_LEN);
    pL->length = MAX_LEN;
    pL->cnt = 0;
    for (int i=0; i<pL->length; i++) {
        pL->pBase[i] = 0;
    }
}
void increaseSize(SeqList * pL, int len)
{
    int * r = pL->pBase;
    pL->pBase = (int*)malloc(sizeof(int)*(pL->length+len));    // 重新申请空间：最大长度 + 扩展长度
    for (int i=0; i<pL->length; i++) {      // 把旧空间的数组移到新空间
        pL->pBase[i] = r[i];
    }
    for (int i=pL->length; i<pL->length+len; i++) {     // 扩展空间的成员初始化为0
        pL->pBase[i] = 0;
    }
    pL->length += len;
    free(r);    // 释放旧空间
}
void traverseList(SeqList * pL)
{
    for (int i = 0; i<pL->length; i++) {
        printf("data[%d] = %d\n", i, pL->pBase[i]);
    }
}