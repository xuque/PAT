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



