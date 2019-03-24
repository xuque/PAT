#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxTree 10
#define MaxSize 11
#define ElementType char
#define Tree int
#define null -1

struct QNode{
    int *Data;
    int Rear;
    int Front;
};
typedef struct QNode *Queue;
Queue CreateQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Data = (int *)malloc(MaxSize * sizeof(int));
    Q->Front = Q->Rear = 0;
//    Q->Size = Size_number;
    return Q;
}
bool IsFull( Queue Q )
{
    return ((Q->Rear+1)%MaxSize == Q->Front);// full->return 1
}
void AddQ( Queue Q, int X )
{
    if ( IsFull(Q) ) {
        return ;
    }
    else {
        Q->Rear = (Q->Rear+1)%MaxSize;
        Q->Data[Q->Rear] = X;
    }
}
bool IsEmpty( Queue Q )
{
    return (Q->Front == Q->Rear);
}
int DeleteQ( Queue Q )
{
    if ( IsEmpty(Q) ) {
        return null;
    }
    else  {
        Q->Front =(Q->Front+1)%MaxSize;
        return  Q->Data[Q->Front];
    }
}
/////////////*******Part of Tree
struct TreeNode{
//    ElementType Element;
    Tree Left;
    Tree Right;
}T[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    int number;
    int Root=null;
    int check[MaxTree];
    scanf("%d\n",&number);
    if(number){
        int i;
        ElementType cl,cr;
        for(i=0;i<number;i++) check[i]=0;
        for(i=0;i<number;i++){
            scanf("%c %c\n",&cl,&cr);
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else T[i].Left=null;
            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else T[i].Right=null;
        }
        for(i=0;i<number;i++){
            if(!check[i]) {
                Root=i;
                break;
            }
        }
    }
    return Root;
}
void Sequence(Tree Root,struct TreeNode T[])
{
    Queue Q=CreateQueue();
    int a[MaxSize];
    for(int i=0;i<MaxSize;i++) a[i]=0;
    if(Root==null){
        return;
    }
    else{
        AddQ(Q,Root);
    }
    int temp;
    int i=0;
    while(!IsEmpty(Q)){
        temp=DeleteQ(Q);
        if(temp!=null){
            if(T[temp].Left!=null) AddQ(Q,T[temp].Left);
            if(T[temp].Right!=null) AddQ(Q,T[temp].Right);
            if(T[temp].Left==null&&T[temp].Right==null){
                a[i]=temp;
                i++;
            };
        }
        else{
            printf("Error");
            return;
        }
    }
    for(int j=0;j<i;j++){
        printf("%d",a[j]);
        if(j<i-1) printf(" ");
    }
}
/////////////////////////////////////////////***************************************
int main(int argc ,char *argv[])
{
    Tree root=BuildTree(T);
    Sequence(root,T);

    return 0;
}
