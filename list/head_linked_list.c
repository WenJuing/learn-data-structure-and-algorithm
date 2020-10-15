#include<stdio.h>
#include<windows.h>
#include<stdbool.h>
/** 带头结点链表的基本使用 */
typedef struct LNode {
    int data;
    struct LNode * next;
} LNode, *LinkList;

bool initList(LinkList L);                          // 初始化
bool listInsert(LinkList L, int pos, int val);      // 插入节点
bool insertNextNode(LNode * p, int val);            // 指定节点的后插操作：在 p节点后插入新节点
bool insertPriorNode(LNode * p, int val);           // 指定节点的前插操作：在 p节点前插入新节点
bool listDelete(LinkList * L, int pos, int * val);  // 删除节点
bool deleteNode(LNode * p);     // 删除指定节点

int main(void)
{
    LinkList L;
    initList(L);
    system("pause");
    return 0;
}
bool initList(LinkList L)
{
    L = (LNode*)malloc(sizeof(LNode));  // 分配头结点
    if (L == NULL) return false;    // 内存不足，分配失败
    L->next = NULL;
    return true;
}
bool listInsert(LinkList L, int pos, int val)
{
    if (pos < 1) return false;
    LNode * p = L;
    int i = 0;      // 表示 p指向第几个节点
    while (p != NULL && i<pos-1) {    // 定位到 pos的前一个节点
        p = p->next;
        i++;
    }
    if (p == NULL) return false;    // 保证插入位置的前一个节点是有效的
    LNode * New = (LNode*)malloc(sizeof(LNode));
    New->data = val;
    New->next = p->next;
    p->next = New;
    return true;
}
// 指定节点的后插操作：在 p节点后插入新节点
bool insertNextNode(LNode * p, int val)
{
    if (p == NULL) return false;
    LNode * New = (LNode*)malloc(sizeof(LNode));
    New->data = val;
    New->next = p->next;
    p->next = New;
    return true;
}
// 指定节点的前插操作：在 p节点前插入新节点
bool insertPriorNode(LNode * p, int val)
{
    if (p == NULL) return false;
    LNode * New = (LNode*)malloc(sizeof(LNode));
    New->data = p->data;    // 让新节点代替 p 指向下一个节点
    New->next = p->next;    // p 代替新节点（把 p当作New，把 New当作 p）
    p->data = val;
    p->next = New;
    return true;
}
bool listDelete(LinkList * L, int pos, int * val)
{
    int i = 0;  // 指向第几个节点
    LNode * p = L;

    if (pos < 1) return false;
    while (p != NULL && i < pos-1) {    // 定位到被删节点的前一个节点
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) return false;     // 保证被删节点不为空
    LNode * r = p->next;
    *val = r->data;     // 得到被删节点的值
    p = p->next->next;
    free(r);
    r = NULL;
    return true;
}
bool deleteNode(LNode * p)
{
    if (p == NULL) return false;    // 当 p指向最后一个节点时，这段是代码有bug的
    LNode * q = p->next;    // 让 p代表下一个节点，即 p本身已被抹去
    p->data = q->data;
    p->next = q->next;
    free(q);
    q = NULL;
    return true;
}