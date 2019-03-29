#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

List ReadInput()
{
    int num,temp;
    scanf("%d",&num);
    List L = (List)malloc(sizeof(struct LNode));
    *L->Data= (ElementType)malloc(sizeof(ElementType)*MAXSIZE);
    L->Last=num;
    for(int i=1;i<=num;i++){
        scanf("%d",&temp);
        L->Data[i]=temp;
    }
    return L;
}

Position BinarySearch(List L, ElementType X)
{
    int Left=1,Right=L->Last;
    int index;
    while(Left!=Right){
        index=(Left+Right)/2;
        if(X==L->Data[index]) break;
        else if(X>L->Data[index]) Left=index+1;
        else    Right=index-1;
    }
    if(Left == Right){
        if(X==L->Data[Left]) index=Left;
        else index=NotFound;
    }
    return index;
}
