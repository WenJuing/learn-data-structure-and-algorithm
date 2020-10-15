#include<stdio.h>
#include<windows.h>
#include<stdbool.h>

/** 静态顺序表的基本使用  */
#define MAX_LEN 10

typedef struct seqlist
{
    int data[MAX_LEN];      // 最大长度
    int cnt;                // 有效长度
} SeqList;

void initList(SeqList * pL);        // 初始化
void traverseList(SeqList * pL);    // 遍历数组
bool listInsert(SeqList * pL, int pos, int val);     // 插入
bool listDelete(SeqList * pL, int pos, int * val);   // 删除
int getElem(SeqList * pL, int pos);      // 按位查找
int locateElem(SeqList * pL, int val);   // 按值查找
int main(void)
{
    SeqList L;          // 定义数组，分配内存空间
    int val;
    initList(&L);
    listInsert(&L, 1, 1);
    listInsert(&L, 2, 2);
    listInsert(&L, 3, 3);
    listInsert(&L, 4, 4);
    listInsert(&L, 5, 5);
    printf("值为4的下标为%d\n", locateElem(&L, 4));
    system("pause");
    return 0;
}
void initList(SeqList * pL)
{
    for (int i = 0; i< MAX_LEN; i++) {      // 数组成员初始化
        pL->data[i] = 0;
    }
    pL->cnt = 0;
}
void traverseList(SeqList * pL)
{
    for (int i = 0; i<MAX_LEN; i++) {
        printf("data[%d] = %d\n", i, pL->data[i]);
    }
}
bool listInsert(SeqList * pL, int pos, int val)     // pos插入位置，起始值为1
{
    if (pL->cnt >= MAX_LEN) return false;       // 若元素为满，插入失败
    if (pos<1 || pos>pL->cnt+1) return false;   // 若插入位置不在范围内，插入失败
    for (int i=pL->cnt+1; i>=pos; i--) {
        pL->data[i] = pL->data[i-1];    // 从最后一个成员开始，依次往右挪一位
    }
    pL->data[pos-1] = val;
    pL->cnt++;
    return true;
}
bool listDelete(SeqList * pL, int pos, int * val)   // val为删除元素的地址，可知道是删除了哪个元素
{
    if (pL->cnt == 0) return false;     // 若数组为空，则删除失败
    if (pos<1 || pos>pL->cnt) return false;   // 若删除位置不在范围，则删除失败
    *val = pL->data[pos-1];
    for (int i=pos-1; i<=pL->cnt-1; i++) {
        pL->data[i] = pL->data[i+1];    // 从被删位置开始，成员依次左移
    }
    pL->cnt--;
    return true;
}
int getElem(SeqList * pL, int pos)  // 按位查找，根据下标查找值
{
    return pL->data[pos-1];
}
int locateElem(SeqList * pL, int val)   // 按值查找，根据值查找下标
{
    for (int i=0; i<pL->cnt; i++)
    {
        if (pL->data[i] == val) return i;
    }
}
