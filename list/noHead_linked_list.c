#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
/** 不带头结点链表的基本使用 */
typedef struct LNode {
    int data;
    struct LNode * next;
} LNode, *LinkList;
bool initList(LinkList L);
int main(void)
{
    LinkList L;
    initList(L);
}
bool initList(LinkList L)
{
    L = NULL;       // 空表，暂时没有任何节点（故不用申请任何空间）
    return true;
}
bool listInsert(LinkList L, int pos, int val)
{
    if (pos == 1) {     // pos为 1时特殊处理
        LNode * New = (LNode*)malloc(sizeof(LNode));
        New->data = val;
        New->next = L;
        L = New;
        return true;
    }
    LNode * p = L;
    if (pos < 1) return false;
    int i = 1;      // 表示指向第几个节点
    while (p != NULL && i < pos-1) {
        p = p->next;
        i++;
    }
    if (p == NULL) return false;    // p != NULL只能保证 pos的前前个节点有效
    LNode * New = (LNode*)malloc(sizeof(LNode));
    New->data = val;
    New->next = p->next;
    p->next = New;
    return true;
}
