#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

typedef struct Node
{
    int date;               //数据域
    struct Node * pNext;    //指针域
}NODE, *PNODE;              //NODE等价于struct Node，PNODE等价于struct Node *
PNODE create_list();                //创建链表
void traverse_list(PNODE pHead);    //遍历链表
int length_list(PNODE pHead);       //获取链表长度
bool is_empty(PNODE pHead);         //判断是否为空
void sort_list(PNODE pHead);        //按从小到大排序
bool insert_list(PNODE pHead, int pos, int val);    //插入一个子节点
bool delete_list(PNODE pHead, int pos, int * val);   //清除一个子节点

int main(void)
{
    PNODE pHead;
    pHead = create_list();
    traverse_list(pHead);
    int val;
    if (delete_list(pHead, 2, &val)) {
        printf("清除成功，清除的是%d\n", val);
    } else {
        printf("清除失败！\n");
    }
    printf("该链表长度为%d\n", length_list(pHead));
    if( is_empty(pHead) ) printf("链表为空！\n");
    else printf("链表不空！\n");
    sort_list(pHead);
    traverse_list(pHead);
    system("pause");
     return 0;
}
PNODE create_list()
{
    int val;
    int len;
    int i;
    PNODE pHead = (PNODE)malloc(sizeof(NODE));  //生成一个头结点
    if ( NULL==pHead ) {
        printf("分配失败，程序中止！\n");
        exit(-1);
    }
    PNODE pTail = pHead;    //生成一个尾节点，此时由于整个链表只有一个头结点，故尾节点就是头结点
    pTail->pNext = NULL;    //尾节点的后一个为空（没有子节点）
    printf("请输入你要生成链表的个数：");
    scanf("%d", &len);
    for ( i=0; i<len; i++ ) {
        printf("请输入第%d个节点的值：\n", i+1);
        scanf("%d", &val);
        PNODE pNew = (PNODE)malloc(sizeof(NODE));   //新生成的子节点
        if ( NULL==pNew ) {
        printf("分配失败，程序中止！\n");
        exit(-1);
        }
        pNew->date = val;       //给新子节点赋值
        pTail->pNext = pNew;    //新子节点接在尾节点后面（尾节点--新子节点）
        pNew->pNext = NULL;     //（尾节点--新子节点--空）
        pTail = pNew;           //新的子节点变成了尾节点
    }
    return pHead;
}
void traverse_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    printf("该链表的全部子节点的值为：");
    while ( NULL!=p ) {
        printf("%d ", p->date);
        p = p->pNext;
    }
    printf("\n");
}
bool is_empty(PNODE pHead)
{
    if( NULL==pHead->pNext ) return true;
    else return false;
}
int length_list(PNODE pHead)
{
    PNODE p = pHead->pNext;
    int len = 0;
    while( NULL!=p ) {
        len++;
        p = p->pNext;
    }
    return len;
}
void sort_list(PNODE pHead)
{
    int i, j, t;
    int len = length_list(pHead);
    PNODE p, q;
    for( i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext ) {  //i、j限定周期次数，p、q具体执行
        for( j=i+1, q=p->pNext; j<len; j++, q=q->pNext) {
            if( q->date<p->date) {
                t = p->date;
                p->date = q->date;
                q->date = t;
            }
        }
    }
}
bool insert_list(PNODE pHead, int pos, int val)     //pos从1开始（当pos=3，在第三个节点前插入）
{
    PNODE p = pHead;
    int i = 0;
    while ( p!=NULL && i<pos-1)
    {
        p = p->pNext;   //令p刚好指向pos的前一个子节点（i=0，i<2，循环2次，i=2，p刚好指向第二个子节点）
        i++;
    }
    if( NULL==p || i>pos-1 ) return false;  //当pos=3，至少要第二个节点不为空，即有效-空-空
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->date = val;
    PNODE t = p->pNext;
    p->pNext = pNew;
    pNew->pNext = t;
}
bool delete_list(PNODE pHead, int pos, int * val)   //当Pos=3，即清除第三个，则定位到第二个子节点
{
    PNODE p = pHead;
    int i = 0;
    while ( NULL!=p->pNext && i<pos-1 )     //循环两次，此时p指向第二个子节点
    {
        p = p->pNext;
        ++i;
    }
    if( i>pos-1 || NULL==p->pNext ) return false;   //下一个要清除的子节点不能为空，且Pos要最小为1
    PNODE q = p->pNext;     //q指向第三个子节点
    *val = q->date;
    p->pNext = p->pNext->pNext;     //第二个子节点的下一个为第四个子节点，即第三被剔除
    free(q);    //释放q的内存
    q = NULL;   //赋值q为空
    return true;
}