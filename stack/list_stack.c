#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
/** 链式存储的栈的实现 **/
typedef struct Node
{
    int data;
    struct Node * pNext;
}NODE, * PNODE;
typedef struct Stack
{
    PNODE pTop;
    PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK pS);           //初始化
void push(PSTACK pS, int val);  //压栈
void traverse(PSTACK pS);       //遍历
bool empty(PSTACK pS);          //判断栈是否为空
bool pop(PSTACK pS, int * val); //出栈
bool clear(PSTACK pS);          //清空栈

int main(void)
{
    STACK S;        //定义一个名为S的栈（分配内存）
    int val;
    init(&S);       //生成一个空栈（只有顶端和底端，且都指向一个空的节点）
    push(&S, 1);    //压栈（放入节点）
    push(&S, 2);
    push(&S, 3);
    push(&S, 4);
    push(&S, 5);
    push(&S, 6);
    traverse(&S);   //遍历，结果为：6 5 4 3 2 1（先进后出）
    if (pop(&S, &val)) {    //出栈（放出最顶部的一个节点）
        printf("出栈成功，出栈的是%d\n", val);
    } else {
        printf("出栈失败！\n");
    }
    traverse(&S);
    clear(&S);      //清空栈里的所有节点（除了顶部和底部）
    traverse(&S);
    system("pause");
    return 0;
}
void init(PSTACK pS)
{
    pS->pTop = (PNODE)malloc(sizeof(STACK));
    if( NULL==pS->pTop) {
        printf("分配内存失败！");
        exit(-1);
    } else {
        pS->pBottom = pS->pTop;
    }
    pS->pTop->pNext = NULL;
    return;
}

void push(PSTACK pS, int val)
{
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
    return;
}
void traverse(PSTACK pS)
{
    PNODE p = pS->pTop;
    while ( p!=pS->pBottom )
    {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}
bool empty(PSTACK pS)
{
    if( pS->pTop==pS->pBottom ) return true;
    else return false;
}
bool pop(PSTACK pS, int * val)
{
    if( empty(pS) ) {
        return false;
    } else {
        PNODE t = pS->pTop;
        *val = t->data;
        pS->pTop = t->pNext;
        free(t);
        t = NULL;
        return true;
    }
}
bool clear(PSTACK pS)
{
    while ( pS->pTop!=pS->pBottom ) {
        PNODE t = pS->pTop;
        pS->pTop = t->pNext;
        free(t);
        t = NULL;
    }
    return true;
}