#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
/** 链式存储的队列的实现 **/

typedef struct linkNode
{
    int data;
    struct linkNode * next;
} LinkNode;
typedef struct linkQueue
{
    LinkNode *front, *rear;
} LinkQueue;

void initHQueue(LinkQueue * L); // 队列的初始化（带头节点）
bool isHEmpty(LinkQueue L); // 判断队列是否为空（带头节点）
void enHQueue(LinkQueue * L, int val);  // 入队（带头节点）
bool deHQueue(LinkQueue * L, int * val);    // 出队（带头节点）

void initQueue(LinkQueue * L);  // 队列的初始化（不带头节点）
bool isEmpty(LinkQueue L);  // 判断队列是否为空（不带头节点）
void enQueue(LinkQueue * L, int val);   // 入队（不带头节点）
bool deQueue(LinkQueue * L, int * val);    // 出队（不带头节点）

int main(void)
{
    LinkQueue L;
    int val;
    initQueue(&L);
    enQueue(&L, 1);
    enQueue(&L, 2);
    enQueue(&L, 3);
    isEmpty(L) ? printf("队列为空\n") : printf("队列不空\n");
    deQueue(&L, &val);
    printf("%d\n", val);
    deQueue(&L, &val);
    printf("%d\n", val);
    deQueue(&L, &val);
    printf("%d\n", val);
    isEmpty(L) ? printf("队列为空\n") : printf("队列不空\n");
    system("pause");
    return 0;
}

void initHQueue(LinkQueue * L)
{
    L->front = L->rear = (LinkNode*)malloc(sizeof(LinkNode));
    L->front->next = NULL;
}
void initQueue(LinkQueue * L)
{
    L->front = L->rear = (LinkNode*)malloc(sizeof(LinkNode));
    L->front = L->rear = NULL;
}
bool isHEmpty(LinkQueue L)
{
    if (L.front == L.rear) return true;
    return false;
}
bool isEmpty(LinkQueue L)
{
    if (L.front == NULL) return true;
    return false;
}
void enHQueue(LinkQueue * L, int val)
{
    LinkNode * pNew = (LinkNode*)malloc(sizeof(LinkNode));
    pNew->data = val;
    pNew->next = NULL;
    L->rear->next = pNew;
    L->rear = pNew;
}
void enQueue(LinkQueue * L, int val)
{
    LinkNode * pNew = (LinkNode*)malloc(sizeof(LinkNode));
    pNew->data = val;
    pNew->next = NULL;
    if (isEmpty(*L)) L->front = L->rear = pNew; // 若空队，第一个元素既是队友又是队尾
    L->rear->next = pNew;
    L->rear = pNew;
}
bool deHQueue(LinkQueue * L, int * val)
{
    if (L->front == L->rear) return false;  // 空队，出队失败
    LinkNode * p = L->front->next;
    *val = p->data;
    L->front->next = p->next;
    if (L->rear == p) L->front = L->rear = NULL;    // 若是只剩一个元素，则回到空队状态
    free(p);
    return true;
}
bool deQueue(LinkQueue * L, int * val)
{
    if (isEmpty(*L)) return false;  // 空队，出队失败
    LinkNode * p = L->front;
    *val = p->data;
    L->front = p->next;
    if (p->next == NULL) L->front = L->rear = NULL; // 若是只剩一个元素，则回到空队状态
    free(p);
    return true;
}