#include <stdio.h>
#include <windows.h>

void hannuota(int n, char begin_pan, char aide_pan, char end_pan);

int main(void)
{
    char A = 'A';
    char B = 'B';
    char C = 'C';
    int n;
    printf("请输入要移动圆盘的个数：");
    scanf("%d", &n);
    hannuota(n, A, B, C);
    system("pause");
    return 0;
}
void hannuota(int n, char begin_pan, char aide_pan, char end_pan)
{
/*
    【中心思想】
    如果是1个盘子
        直接将A柱子上的盘子从A移动到C
    否则
        先将A柱子上的n-1个盘子借助C移动到B
        直接将Ad柱子上的盘子从A移动到C
        最后将B柱子上的n-1个盘子借助A移动到C
*/
    int static cnt = 0;
    if( n==1 ) {    //若起始盘只剩一个，则直接移到目标盘
        cnt++;
        printf("将第%d小的盘从%c移动到%c，移动了%d次\n", n, begin_pan, end_pan, cnt);
    } else {
        hannuota(n-1, begin_pan, end_pan, aide_pan);
        cnt++;
        printf("将第%d小的盘从%c移动到%c，移动了%d次\n", n, begin_pan, end_pan, cnt);
        hannuota(n-1, aide_pan, begin_pan, end_pan);
    }
}