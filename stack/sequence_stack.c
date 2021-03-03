#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#define MaxSize 10
/** 顺序存储的栈的实现 **/
typedef struct sqStack
{
    int data[MaxSize];
    int top;
} SqStack, * pSqStack;

void initStack(pSqStack S);
bool isEmpty(SqStack S);
bool push(pSqStack pS, int val);
bool pop(pSqStack pS, int * val);
bool getTop(SqStack S, int * val);


int main(void)
{
    SqStack S;
    int val;
    initStack(&S);
    push(&S, 1);
    push(&S, 2);
    push(&S, 3);
    isEmpty(S) ? printf("空的栈\n") : printf("非空的栈\n");
    pop(&S, &val);
    printf("%d\n", val);
    pop(&S, &val);
    printf("%d\n", val);
    pop(&S, &val);
    printf("%d\n", val);
    isEmpty(S) ? printf("空的栈\n") : printf("非空的栈\n");
    system("pause");
    return 0;
}
void initStack(pSqStack pS)
{
    pS->top = -1;
}
bool isEmpty(SqStack S)
{
    if (S.top == -1) return true;
    return false;
}
bool push(pSqStack pS, int val)
{
    if (pS->top == MaxSize) return false;   // 栈满，入栈失败
    pS->top += 1;
    pS->data[pS->top] = val;
    return true;
}
bool pop(pSqStack pS, int * val)
{
    if (pS->top == -1) return false;    // 栈空，出栈失败
    *val = pS->data[pS->top];
    pS->top -= 1;
    return true;
}
bool getTop(SqStack S, int * val)
{
    if (S.top == -1) return false;
    *val = S.data[S.top];
    return true;
}