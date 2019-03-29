#include <iostream>
#include <stdio.h>

using namespace std;
const int maxsize=100001;
int flag;
int times=1;

typedef struct ListNode* List;
struct ListNode{
    int Data;
    int Address;
//    int NextAddress;
    List Next;
};
List LinkedList(int FirstAddree, int* data, int* next)
{
    List head=new ListNode;
    head->Next=NULL;
    List p=head;
    int NextAddress=FirstAddree;
    do{
        List Node=new ListNode;
        Node->Address=NextAddress; //Address
        Node->Data=data[Node->Address]; //Data
//        NextAddress=Node->NextAddress=next[Node->Data]; //NextAddress
        NextAddress=next[Node->Data]; //NextAddress
        Node->Next=NULL;
        p->Next=Node;
        p=p->Next;
    }while(NextAddress!=-1);

    return head;
}
int CountNode(List head)
{
    int number=0;
    while(head!=NULL){
        number++;
        head=head->Next;
    }
    return number;
}
List Reverse(List head, int ReverseNumber)
{
//    if(head==NULL) retur NULL;
//    if( ReverseNumber>CountNode(head) ) return head;  // the problem maybe here , it spend more time
    if(times>flag) return head;
    int time=1;
    List New,Old,Tmp;
    New=head;
    Old=New->Next;
    Tmp=Old->Next;
    while(time<ReverseNumber){
        Old->Next=New;
        New=Old;
        Old=Tmp;
        if(Tmp!=NULL) Tmp=Tmp->Next;
        time++;
    }
    times++;
    head->Next=Reverse(Old,ReverseNumber);

    return New;
}
void PrintLink(List head)
{
    if(head->Next==NULL) return ; //Empty Linked List
    head=head->Next;
    while(head!=NULL){
        printf("%05d %d ",head->Address,head->Data);
        if(head->Next!=NULL) printf("%05d\n",head->Next->Address);
        else printf("-1");
        head=head->Next;
    }
}

int main()
{
    int FirstAddree,number,ReverseNumber;
    scanf("%d %d %d",&FirstAddree,&number,&ReverseNumber);
    int index;
    int data[maxsize];  //[address] . data
    int next[maxsize];  //[data] . NextAddress
    for(int i=0;i<number;i++){
        scanf("%d",&index);
        scanf("%d",&data[index]);
        scanf("%d",&next[data[index]]);
    }
    List head=LinkedList(FirstAddree,data,next);
    if(ReverseNumber!=1){
        flag=CountNode(head->Next)/ReverseNumber;
        head->Next=Reverse(head->Next,ReverseNumber);
    }
    PrintLink(head);

    return 0;
}
///***the code from other person in blog , it has same ideas from the MOOC, but it's right***//
////#include<stdio.h>
////#define MAX_SIZE 100004
////
////typedef struct tagLNode{
////    int addr;      //节点位置Address
////    int data;      //Data值
////    int nextAddr;  //下个节点位置
////    struct tagLNode *next;  //指向下个节点的指针
////} LNode;
/////*
////    LNode *listReverse(LNode *head, int k);
////    反转单链表函数
////    参数1：单链表的头节点，
////    参数2：反转子链表的长度，
////    返回值：反转后的链表的第一个节点(不是头结点)
////
////*/
////LNode *listReverse(LNode *head, int k);
//////输出单链表 参数为单链表的头结点
////void printList(LNode *a);
////
////int main()
////{
////    int firstAddr;
////    int n = 0;            //节点数 N
////    int k = 0;            //反转子链表的长度K
////    int num = 0;          //链表建好之后的链表节点数
////    int data[MAX_SIZE];   //存data值 节点位置作为索引值
////    int next[MAX_SIZE];   //存next值 节点位置为索引
////    int tmp;              //临时变量，输入的时候用
////
////    scanf("%d %d %d", &firstAddr, &n, &k);
////    LNode a[n+1];                //能存n+1个几点的数组。
////    a[0].nextAddr = firstAddr;   //a[0] 作为头节点
////    //读输入的节点
////    int i = 1;
////    for (; i < n+1; i++){
////        scanf("%d", &tmp);
////        scanf("%d %d", &data[tmp], &next[tmp]);
////    }
////
////    //构建单链表
////    i = 1;
////    while (1){
////        if (a[i-1].nextAddr == -1){
////            a[i-1].next = NULL;
////            num = i-1;
////            break;
////        }
////        a[i].addr = a[i-1].nextAddr;
////        a[i].data = data[a[i].addr];
////        a[i].nextAddr = next[a[i].addr];
////        a[i-1].next = a+i;
////
////        i++;
////    }
////
////    LNode *p = a;                    //p指向链表头结点
////    LNode *rp = NULL;                //反转链表函数的返回值
////    if (k <= num ){
////
////        for (i = 0; i < (num/k); i++){
////            rp = listReverse(p, k);  //
////            p->next = rp;            // 第一次执行，a[0]->next 指向第一段子链表反转的第一个节点
////            p->nextAddr = rp->addr;  // 更改Next值，指向逆转后它的下一个节点的位置
////
////            int j = 0;
////            //使p指向下一段需要反转的子链表的头结点（第一个节点的前一个节点）
////            while (j < k){
////                p = p->next;
////                j++;
////            }
////
////        }
////    }
////
////    printList(a);
////}
////
////LNode *listReverse(LNode *head, int k)
////{
////    int count = 1;
////    LNode *new = head->next;
////    LNode *old = new->next;
////    LNode *tmp = NULL;
////
////    while (count < k){
////        tmp = old->next;
////        old->next = new;
////        old->nextAddr = new->addr;
////        new = old;   //new向后走一个节点
////        old = tmp;   //tmp向后走一个节点
////        count++;
////    }
////    //使反转后的最后一个节点指向下一段子链表的第一个节点
////    head->next->next = old;
////    if (old != NULL){
////        //修改Next值，使它指向下一个节点的位置
////        head->next->nextAddr = old->addr;
////    }else{
////        //如果old为NULL,即没有下一个子链表，那么反转后的最后一个节点即是真个链表的最后一个节点
////        head->next->nextAddr = -1;
////    }
////    return new;
////}
////
////void printList(LNode *a)
////{
////    LNode *p = a;
////
////    while (p->next != NULL){
////        p = p->next;
////        if (p->nextAddr != -1 ){
////            //格式输出，%.5意味着如果一个整数不足5位，输出时前面补0 如：22，输出：00022
////            printf("%.5d %d %.5d\n", p->addr, p->data, p->nextAddr);
////        }else{
////            //-1不需要以%.5格式输出
////            printf("%.5d %d %d\n", p->addr, p->data, p->nextAddr);
////        }
////    }
////
////}
//////////////////////////////////////////////////////////////////////////

/////////*****below is the old code, but it also used more time, can't pass the pta****//

//////////#include <iostream>
//////////#include <stdlib.h>
//////////
//////////using namespace std;
//////////
//////////typedef int ElementType;
//////////typedef struct Node *PtrToNode;
//////////#define Array_Number 5
//////////struct Node {
//////////    ElementType Address;
//////////    ElementType Next_Address;
//////////    ElementType Data;
//////////    PtrToNode   Next;
//////////};
//////////typedef PtrToNode List;
//////////
//////////List Create(int Length_number);
//////////void Print(List L);
//////////void Print_Address(int Address);
//////////List Find_First_Address(List L, int Address);
//////////////List Find_Next_Address(List L, int Next_Address);
//////////List Orderly(List L, int First_Address, int Length_number);
//////////List Reversing(List L, int Length_number, int Reversing_number);
//////////List Reversing_for(List L, int i);
//////////List Transform_Next_Address(List L, int Length_number);
//////////
//////////static int Delete_number=0;
//////////int main()
//////////{
//////////    int First_Address=0;
//////////    int Length_number=0;
//////////    int Reversing_number=0;
//////////
//////////    cin>>First_Address;
//////////    cin>>Length_number;
//////////    cin>>Reversing_number;
//////////
//////////    List L1=Create(Length_number);
//////////    List L2=Orderly(L1, First_Address, Length_number);
////////////    cout<<endl;Print(L2);cout<<endl;
//////////    List L3=Reversing(L2, Length_number, Reversing_number);
//////////    List L4=Transform_Next_Address(L3,Length_number);
//////////
//////////    Print(L4);
//////////
//////////    return 0;
//////////}
//////////
//////////List Create(int Length_number)
//////////{
//////////    List L=(List)malloc(sizeof(struct Node));
//////////    List L1=L;
//////////    int i=0;
//////////    for(i=0;i<Length_number;i++){
//////////        List M=(List)malloc(sizeof(struct Node));
//////////        cin>>M->Address;
//////////        cin>>M->Data;
//////////        cin>>M->Next_Address;
//////////        L1->Next=M;
//////////        L1=L1->Next;
//////////    }
//////////    L1->Next=NULL;
//////////
//////////    return L;
//////////}
//////////void Print(List L)
//////////{
//////////    if(L->Next==NULL) {
//////////        cout<<"NULL\n";
//////////        return;
//////////    }
//////////    else{
//////////        List A;
//////////        A=L->Next;
//////////        while(A){
//////////            Print_Address(A->Address);
//////////            cout<<" "<<A->Data<<" ";
//////////            Print_Address(A->Next_Address);
//////////            A=A->Next;
//////////            if(A)cout<<endl;
//////////        }
//////////        return;
//////////    }
//////////}
//////////void Print_Address(int Address)
//////////{
//////////    int i=0;
//////////    if(Address==-1){
//////////        cout<<-1;
//////////        return;
//////////    }
//////////    else if(Address<10000&&Address>999){
//////////        for(i=0;i<1;i++){
//////////            cout<<0;
//////////        }
//////////        cout<<Address;
//////////        return;
//////////    }
//////////    else if(Address<1000&&Address>99){
//////////        for(i=0;i<2;i++){
//////////            cout<<0;
//////////        }
//////////        cout<<Address;
//////////        return;
//////////    }
//////////    else if(Address<100&&Address>9){
//////////        for(i=0;i<3;i++){
//////////            cout<<0;
//////////        }
//////////        cout<<Address;
//////////        return;
//////////    }
//////////    else if(Address<9){
//////////        for(i=0;i<4;i++){
//////////            cout<<0;
//////////        }
//////////        cout<<Address;
//////////        return;
//////////    }
//////////    else cout<<Address;
//////////}
//////////List Find_First_Address(List L, int Address)
//////////{
//////////    List F=L->Next;
//////////
//////////    if(F!=NULL){
//////////        while(F){
//////////                if(F->Address==Address) break;
//////////                else F=F->Next;
//////////        }
//////////    }
//////////    else return NULL;
//////////
//////////    return F;
//////////
//////////}
//////////////List Find_Next_Address(List L, int Next_Address)
//////////////{
//////////////    List F=L->Next;
//////////////
//////////////    if(F!=NULL){
//////////////            while(F){
//////////////                if(F->Next_Address==Next_Address) break;
//////////////                else F=F->Next;
//////////////            }
//////////////    }
//////////////    else return NULL;
//////////////
//////////////    return F;
//////////////}
//////////List Orderly(List L, int First_Address, int Length_number)
//////////{
//////////    List T=(List)malloc(sizeof(struct Node));
//////////    List T1=T;
//////////    int First_Address_=First_Address;
//////////
//////////    for(int i=0;i<Length_number;i++){
//////////        List M=(List)malloc(sizeof(struct Node));
//////////        List L1=Find_First_Address(L,First_Address_);
//////////            if(L1==NULL){
//////////                Delete_number++;
//////////            }
//////////            else{
//////////                M->Address=L1->Address;
//////////                M->Data=L1->Data;
//////////                M->Next_Address=L1->Next_Address;
//////////                First_Address_=L1->Next_Address;
//////////                T1->Next=M;
//////////                T1=T1->Next;
//////////            }
//////////    }
//////////    T1->Next=NULL;
//////////
//////////    return T;
//////////}
//////////List Reversing(List L, int Length_number, int Reversing_number)
//////////{
//////////    int number=(Length_number-Delete_number)/Reversing_number;
//////////    int yu=(Length_number-Delete_number)%Reversing_number;
//////////    List T=(List)malloc(sizeof(struct Node));
//////////    List T1=T;
//////////    if(number==0||Reversing_number==1){
//////////        return L;
//////////    }
//////////    else{
//////////        List L1=L;
//////////        if(yu!=0){
//////////                for(int j=0;j<number;j++){
//////////                    for(int i=Reversing_number;i>0;i--){
//////////                        List flag=(List)malloc(sizeof(struct Node));
//////////                        List x;
//////////                        x=Reversing_for(L1,i);
//////////
//////////                        flag->Address=x->Address;//////error
//////////                        flag->Data=x->Data;
//////////                        flag->Next_Address=x->Next_Address;
//////////                        T1->Next=flag;
//////////                        T1=T1->Next;
//////////                    }
//////////                    for(int k=0;k<Reversing_number;k++){
//////////                        L1=L1->Next;
//////////                    }
//////////                    L1=L1->Next;
//////////                }
//////////                while(L1){
//////////                    List M=(List)malloc(sizeof(struct Node));
//////////                    M->Address=L1->Address;
//////////                    M->Data=L1->Data;
//////////                    M->Next_Address=L1->Next_Address;
//////////                    T1->Next=M;
//////////                    T1=T1->Next;
//////////                    L1=L1->Next;
//////////                }
//////////                T1->Next=NULL;
//////////                return T;
//////////        }
//////////        else{
//////////            L1=L1->Next;
//////////            for(int i=0;i<number;i++){
//////////                for(int j=Reversing_number;j>0;j--){
//////////                    List flag=(List)malloc(sizeof(struct Node));
//////////                    List x;
//////////                    x=Reversing_for(L1,j-1);
//////////
//////////                    flag->Address=x->Address;
//////////                    flag->Data=x->Data;
//////////                    flag->Next_Address=x->Next_Address;
//////////                    T1->Next=flag;
//////////                    T1=T1->Next;
//////////                }
//////////                for(int k=0;k<Reversing_number;k++){
//////////                        L1=L1->Next;
//////////                    }
//////////            }
//////////            T1->Next=NULL;
//////////            return T;
//////////        }
//////////    }
//////////}
//////////List Reversing_for(List L, int i)
//////////{
//////////    List M=L;
//////////    for(;i>0;i--){
//////////        M=M->Next;
//////////    }
//////////    return M;
//////////}
//////////List Transform_Next_Address(List L, int Length_number)
//////////{
//////////    List L1=L->Next;
//////////    int a=Length_number-Delete_number;
//////////    if(a==0) return NULL;
//////////    if(a==1) return L;
//////////    else{
//////////            while(L1){
//////////                L1->Next_Address=(L1->Next)->Address;
//////////                a--;
//////////                if(a!=1)
//////////                    L1=L1->Next;
//////////                else {
//////////                    L1=L1->Next;
//////////                    L1->Next_Address=-1;
//////////                    break;
//////////                }
//////////            }
//////////            return L;
//////////    }
//////////}
