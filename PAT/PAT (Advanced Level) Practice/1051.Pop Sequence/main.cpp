#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stack>

using namespace std;

struct Stack_Node{
    int Maxsize;
    int *Stack_number;
    int top;
};
typedef Stack_Node *Stack;

Stack CreateStack(int Maxsize)
{
    Stack S=(Stack)malloc(sizeof(struct Stack_Node));
    S->Maxsize=Maxsize;
    S->Stack_number=(int* )malloc(sizeof(int)*Maxsize);
    S->top=-1;
    return S;
}
bool IsFull(Stack S)
{
    return (S->Maxsize==S->top+1);
}
bool Push(int number,Stack S)
{
    if(IsFull(S)){
        return 0;
    }
    else{
        S->Stack_number[++S->top]=number;
        return 1;
    }
}
void Pop(Stack S)
{
    S->top--;
    return ;
}
void Result(bool number)
{
    if(number)
        printf("YES\n");
    else
        printf("NO\n");
}
void Injudge(int *number,int Stack_maxsize,int Push_Length)
{
    int high=1;
    bool flag=1;
    Stack S=CreateStack(Stack_maxsize);
    for(int i=0;i<Push_Length&&flag;i++){
        if(number[i]>=high){
            int time=number[i]-high+1;
            while(flag&&(time--)){
                flag=Push(high++,S);
                if(!flag) break;
            }
            Pop(S);
        }
        else{
            if(number[i]==S->Stack_number[S->top])
                Pop(S);
            else{
                flag=0;
                break;
            }
        }
    }
    Result(flag);
}
int main()
{
    int Stack_maxsize, Push_Length, Check_number;
    scanf("%d %d %d ",&Stack_maxsize,&Push_Length,&Check_number);
    int number[Push_Length];
    for(int i=0;i<Check_number;i++){
        for(int j=0;j<Push_Length;j++){
            scanf("%d",&number[j]);
        }
        Injudge(number,Stack_maxsize,Push_Length);
    }
}
