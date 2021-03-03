#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
/** 栈的应用之一：括号匹配 **/
/* 
中心思想：传入一个包含一串待测验的括号的数组，检测其括号是否符合一一配对；
方法：遍历数组，若是左括号，则压栈，右括号，则将出栈的括号与之配对，若配对成功，则继续遍历，直到遍历结束；
配对失败的三种情况：a 左右括号不是同一种类型
                  b 遍历结束后，栈中还有单括号
                  c 遍历结束后，数组中还有单括号 
*/
typedef struct node
{
    int data;
    struct node * next;
} Node, *pNode;
typedef struct stack
{
    pNode pTop;
    pNode pBottom;
} Stack, *pStack;

void initStack(pStack pS);
void push(pStack pS, char val);
bool pop(pStack pS, char * val);
bool isEmpty(Stack pS);
bool bracketMatch(char str[], int len);

int main(void)
{
    char str[] = "{([()])}";
    bracketMatch(str, 8) ? printf("括号匹配正确！\n") : printf("括号匹配失败！\n");
    system("pause");
    return 0;
}
bool bracketMatch(char str[], int len)
{
    Stack S;    // 用一个栈来临时存储数组中的括号
    initStack(&S);
    int i;
    char ch;
    for (i=0; i<len; i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {  // 遍历到左括号时压栈
            push(&S, str[i]);
        } else {    // 遍历到右括号时出栈
            if (isEmpty(S)) return false;
            pop(&S, &ch);   // 出栈的必为左括号
            if (ch == '(' && str[i] != ')') return false;
            if (ch == '{' && str[i] != '}') return false;
            if (ch == '[' && str[i] != ']') return false;
        }
    }
    return isEmpty(S);  // 遍历完数组，栈中为空时，配对成功；
}
void initStack(pStack pS)
{
    pS->pTop = pS->pBottom = (Node*)malloc(sizeof(Node));
    pS->pTop = pS->pBottom = NULL;
}
void push(pStack pS, char val)
{
    Node * pNew = (Node*)malloc(sizeof(Node));
    pNew->data = val;
    pNew->next = pS->pTop;
    pS->pTop = pNew;
}
bool pop(pStack pS, char * val)
{
    if (isEmpty(*pS)) return false; // 空栈，出栈失败
    Node * p = pS->pTop;
    *val = p->data;
    pS->pTop = p->next;
    free(p);
    return true;
}
bool isEmpty(Stack pS)
{
    return pS.pTop == pS.pBottom;
}
