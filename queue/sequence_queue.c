#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
/** 顺序结构的队列的实现 **/
typedef struct Queue
{
    int * pBase;
    int front;
    int rear;
    int len;        //队列长度
} QUEUE;

void init_queue(QUEUE * pQ);            //队列初始化（头部尾部均为0）
bool en_queue(QUEUE * pQ, int val);     //入队（从尾部新增成员）
bool out_queue(QUEUE * pQ, int * val);  //出队（从头部剔除成员）
void traverse_queue(QUEUE * pQ);        //遍历队列
bool full_queue(QUEUE * pQ);            //判断队列是否已满
bool empty_queue(QUEUE * pQ);           //判断队列是否为空

int main()
{
    QUEUE Q;
    int val;    //出队时返回的出队成员的值

    init_queue(&Q);
    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);
    en_queue(&Q, 5);
    en_queue(&Q, 6);
    en_queue(&Q, 7);
    traverse_queue(&Q);
    if (out_queue(&Q, &val)) {
        printf("出队成功，出队的是%d\n", val);
    } else {
        printf("出队失败！该队列没有成员。\n");
    }
    traverse_queue(&Q);

    system("pause");
    return 0;
}

void init_queue(QUEUE * pQ)     //初始化
{
    int len;
    printf("Please input the length of queue:");
    scanf("%d", &len);
    pQ->len = len;
    pQ->pBase = (int*)malloc(sizeof(int)*(pQ->len));    //分配长度，可用长度为len-1
    pQ->front = 0;
    pQ->rear = 0;
}
bool en_queue(QUEUE * pQ, int val)          //enter queue
{
    if ( full_queue(pQ) ) return false;     //若队列已满，则入队失败
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % (pQ->len);
    return true;
}
bool out_queue(QUEUE * pQ, int * val)       //out queue
{
    if ( empty_queue(pQ) ) return false;    //若队列为空，则出队失败
    *val = pQ->pBase[pQ->front];            //获取出队的值
    pQ->front = (pQ->front + 1) % pQ->len;
    return true;
}
void traverse_queue(QUEUE * pQ)
{
    int i = pQ->front;
    while ( i!=pQ->rear )
    {
        printf("%d ", pQ->pBase[i]);
        i = (i + 1) % pQ->len;
    }
    printf("\n");
    
}
bool full_queue(QUEUE * pQ)
{
    if ( (pQ->rear+1)%pQ->len == pQ->front ) return true;
    else return false;
}
bool empty_queue(QUEUE * pQ)
{
    if( pQ->front==pQ->rear ) return true;
    else return false;
}