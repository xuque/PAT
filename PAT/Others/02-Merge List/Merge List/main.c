#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data; /* 存储结点数据 */
    PtrToNode   Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    int n;
    scanf("%d",&n);

    List T;
    T=(List)malloc(sizeof(struct Node));
    T->Next=NULL;

    List T1;
    T1=T;
    while(n--){
        List x;
        x=(List)malloc(sizeof(struct Node));
        x->Next=NULL;
        scanf("%d",&x->Data);
        T1->Next=x;//首节点为空
        T1=T1->Next;
    }
    return T;
}
void Print(List L)
{
    if(L->Next==NULL) {
        printf("NULL\n");
        return;
    }
    else{
        List A;
        A=L->Next;
        while(A){
            printf("%d ",A->Data);
            A=A->Next;
        }
        printf("\n");
        return;
    }
}
List Merge(List L1,List L2)
{
    List L=(List)malloc(sizeof(struct Node));

    List L3=L;
    List a,b;
    a=L1->Next;
    b=L2->Next;

    while(a&&b){
        if(a->Data<b->Data){
            L3->Next=a;
            a=a->Next;
        }
        else{
            L3->Next=b;
            b=b->Next;
        }
        L3=L3->Next;
    }
    while(a){
        L3->Next=a;
        a=a->Next;
        L3=L3->Next;
    }
    while(b){
        L3->Next=b;
        b=b->Next;
        L3=L3->Next;
    }
    L3->Next=NULL;

    L1->Next=NULL;
    L2->Next=NULL;

    return L;
}

////////////////List Read( List L )
////////////////{
////////////////    int n,i;
////////////////    scanf("%d",&n);
////////////////
////////////////    List P;
////////////////    P=(List)malloc(sizeof(struct Node));
////////////////    P=NULL;
////////////////
////////////////    List M;
//////////////////    M=(List)malloc(sizeof(struct Node));
//////////////////    M->Data=0;
//////////////////    M->Next=NULL;
////////////////
////////////////    List N;
////////////////    N=(List)malloc(sizeof(struct Node));
//////////////////    N->Data=0;
//////////////////    N->Next=NULL;
////////////////
////////////////    int a[n];
////////////////    for(i=0;i<n;i++){
////////////////        scanf("%d",&a[i]);
////////////////    }
////////////////
////////////////    for(i=0;i<n;i++){
////////////////        M=(List)malloc(sizeof(struct Node));
////////////////        M->Data=a[i];
//////////////////        printf("M[Data]的地址%p,a[%d]的地址%p\n",M->Data,i,a[i]);
//////////////////        printf("M的地址：%p\n",M);
////////////////
////////////////        if(P==NULL)
////////////////            P=M;//P指向M首地址
////////////////        else
////////////////            N->Next=M;
////////////////        N=M;
//////////////////        printf("M的地址：%p\nN的地址：%p\n",M,N);
//////////////////        printf("P的地址：%p\n",P);
////////////////    }
////////////////    N->Next=NULL;
//////////////////    printf("OK\n");
//////////////////    Print(P);
//////////////////    printf("\n");
////////////////    return P;
////////////////}
////////////////
////////////////void Print( List L)
////////////////{
////////////////
////////////////    if(L->Next==NULL) printf("NULL\n");
////////////////
////////////////    else{
////////////////    List T;
////////////////    T=(List)malloc(sizeof(struct Node));
////////////////    T=L;
////////////////
////////////////
////////////////    while(T){
////////////////        printf("%d\t",T->Data);
////////////////        T=T->Next;
////////////////    }
////////////////
////////////////    free(T);
////////////////    }
////////////////}
////////////////
////////////////List Merge( List L1, List L2 )
////////////////{
////////////////    List P;
////////////////    P=(List)malloc(sizeof(struct Node));
////////////////
////////////////    List L3;
////////////////    L3=P;
////////////////
////////////////    List a,b;
////////////////    a=L1->Next;
////////////////    b=L2->Next;
////////////////    while(a&&b){
////////////////        if(L1->Data<L2->Data){
////////////////            M=(List)malloc(sizeof(struct Node));
////////////////            M->Data=L1->Data;
////////////////            if(P==NULL)
////////////////                P=M;
////////////////            else
////////////////                N->Next=M;
////////////////            N=M;
////////////////            L1=L1->Next;
////////////////        }
////////////////        else{
////////////////            M=(List)malloc(sizeof(struct Node));
////////////////            M->Data=L2->Data;
////////////////            if(P==NULL)
////////////////                P=M;
////////////////            else
////////////////                N->Next=M;
////////////////            N=M;
////////////////            L2=L2->Next;
////////////////        }
////////////////    }
////////////////    while(L1){
////////////////        M=(List)malloc(sizeof(struct Node));
////////////////        M->Data=L1->Data;
////////////////        N->Next=M;
////////////////        N=M;
////////////////        L1=L1->Next;
////////////////    }
////////////////    while(L2){
////////////////        M=(List)malloc(sizeof(struct Node));
////////////////        M->Data=L2->Data;
////////////////        N->Next=M;
////////////////        N=M;
////////////////        L2=L2->Next;
////////////////    }
////////////////        N->Next=NULL;
////////////////        L1->Next=NULL;
////////////////        L2->Next=NULL;
////////////////
////////////////        List* T;
////////////////
////////////////
////////////////        return P;
////////////////}

//
//List Read(){
//    int n;
//    scanf("%d",&n);
//    List L=(struct Node *)malloc(sizeof(struct Node));
//    L->Next=NULL;
//    List ans=L;
//    while (n--){
//        if (L->Next==NULL){
//            List temp=(struct Node *)malloc(sizeof(struct Node));
//            temp->Next=NULL;
//            scanf("%d",&temp->Data);
//            L->Next=temp;
//            L=L->Next;
//        }
//    }
//    return ans;
//}
//void Print( List L ){
//    if (L->Next==NULL){
//        printf("NULL\n");
//        return;
//    }
//    List temp=L->Next;
//    while (temp){
//        printf("%d ",temp->Data);
//        temp=temp->Next;
//    }
//    printf("\n");
//}
//List Merge( List L1, List L2 ){
//    List L3=(struct Node *)malloc(sizeof(struct Node));
//    List L=L3;
//    List p=L1->Next;
//    List q=L2->Next;
//    while (p && q){
//        if (p->Data < q->Data){
//            L->Next=p;
//            p=p->Next;
//        }
//        else{
//            L->Next=q;
//            q=q->Next;
//        }
//        L=L->Next;
//    }
//    L->Next=NULL;
//    if (p) L->Next=p;
//    if (q) L->Next=q;
//    L1->Next=NULL;
//    L2->Next=NULL;
//    return L3;
//}

