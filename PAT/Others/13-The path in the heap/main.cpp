#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int MIN_Number=-10001;

typedef struct HeapNode* Heap;
struct HeapNode{
    int Size;
    int *Data;
    int Capacity;
};
Heap CreateHeap(int Size)
{
    Heap H=new HeapNode;
    H->Data=(int*)malloc(sizeof(int)*(Size+1));
    H->Size=0; //the size in the heap now
    H->Data[0]=MIN_Number; //sentry
    H->Capacity=Size;
    return H;
}
bool IsFull(Heap H)
{
    return (H->Size==H->Capacity);
}
void InsertHeap(Heap H, int number)
{
    if(IsFull(H)) return ;
    H->Data[++H->Size]=number;
    int i=H->Size;
    for(;number<H->Data[i/2];i/=2)
        H->Data[i]=H->Data[i/2];
    H->Data[i]=number;
    return ;
}
void PathHeap(Heap H, int root)
{
    int i=root;
    for(;i>0;i/=2){
        printf("%d",H->Data[i]);
        if(i>1) printf(" ");
    }
    printf("\n");
    return ;
}

int main()
{
    int Size,Path;
    scanf("%d %d",&Size,&Path);
    Heap H=CreateHeap(Size);
    for(int i=0;i<Size;i++){
        int data;
        scanf("%d",&data);
        InsertHeap(H,data);
    }

    for(int i=0;i<Path;i++){
        int p;
        scanf("%d",&p);
        PathHeap(H,p);
    }

    return 0;
}
