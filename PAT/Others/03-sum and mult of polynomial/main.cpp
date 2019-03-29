#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef int coefficient;
typedef int index;
typedef struct Node *Pro_Node;
struct Node{
    coefficient coeff_num;//xishu
    index index_num;//zhishu
    Pro_Node Next;
};
typedef Pro_Node List;

List Read();
void Print(List L);
List Add(List L1, List L2);
List Multi(List L1, List L2);

int main()
{
    List L,Q;
    List L1,L2;
    L1=Read();
    L2=Read();
    Print(L1);
    Print(L2);
    Q=Add(L1,L2);
    Print(Q);
    L=Multi(L1,L2);
    Print(L);

    return 0;
}

List Read()
{
    int n;
    cout<<"请输入项数：";
    cin>>n;

    List L=(List)malloc(sizeof(struct Node));
    List T=L;
    int i=0;
    while(n--){
        i++;
        List M=(List)malloc(sizeof(struct Node));
        cin>>M->coeff_num;
        cin>>M->index_num;

        T->Next=M;
        T=T->Next;
    }
    T->Next=NULL;

    return L;
}

void Print(List L)
{
    List A;
    List B;
    int num=0;
    A=L->Next;
    B=L->Next;

    if(A==NULL){
        cout<<"0"<<" "<<"0";
        return;
    }
    else{
        while(B){
            if(B->coeff_num>0){
               num++;
            }
            B=B->Next;
        }
        int zheng=0;
        while(A){
            if(A->coeff_num!=0){
                if(num>0&&A->coeff_num>0&&zheng>0){
                        printf("+");
                        num--;
                }
                zheng=1;
                if(A->coeff_num!=1){ //>0;<0;=-1
                    if(A->index_num!=0&&A->index_num!=1&&A->coeff_num!=-1){
                        printf("%dx%d",A->coeff_num,A->index_num);
                    }
                    else if(A->index_num==1&&A->coeff_num!=-1){
                        printf("%dx",A->coeff_num);
                    }
                    else if(A->index_num==0&&A->coeff_num!=-1){
                        printf("%d",A->coeff_num);
                    }
                    else if(A->coeff_num==-1){
                        if(A->index_num==1){
                            printf("-x");
                        }
                        else if(A->index_num==0){
                            printf("%d",A->coeff_num);
                        }
                        else printf("-x%d",A->index_num);
                    }
                }
                else if(A->coeff_num==1){
                    if(A->index_num!=1&&A->index_num!=0){
                        printf("x%d",A->index_num);
                    }
                    else if(A->index_num==0){
                        printf("1");
                    }
                    else{
                        printf("x");
                    }
                }
            }

            A=A->Next;
        }
    }
}


List Add(List L1, List L2)
{
    List a,b;
    List L3=(List)malloc(sizeof(struct Node));

    a=L1->Next;
    b=L2->Next;
    List L=L3;

    //先比较index，后加上coeff
    while(a&&b){
        if(a->index_num==b->index_num){
            int number;
            number=a->coeff_num + b->coeff_num;
            if(number==0){
                a=a->Next;
                b=b->Next;
            }
            else{
                List N=(List)malloc(sizeof(struct Node));
                N->index_num=a->index_num;
                N->coeff_num=number;

                L->Next=N;
                L=L->Next;

                a=a->Next;
                b=b->Next;
            }
        }
        else if(a->index_num>b->index_num){
            L->Next=a;
            L=L->Next;

            a=a->Next;
        }
        else{
            L->Next=b;
            L=L->Next;

            b=b->Next;
        }
    }
    while(a){
        L->Next=a;
        L=L->Next;

        a=a->Next;
    }
    while(b){
        L->Next=b;
        L=L->Next;

        b=b->Next;
    }
    L->Next=NULL;
    L1->Next=NULL;
    L2->Next=NULL;

    return L3;
}

List Multi(List L1, List L2)
{
    List a,b;
    a=L1->Next;
    b=L2->Next;

    List T;

    List T2=(List)malloc(sizeof(struct Node));
    List Y2=T2;

    int flag=0;

    while(a){
        List T1=(List)malloc(sizeof(struct Node));
        List Y1=T1;

        while(b){
            List M=(List)malloc(sizeof(struct Node));
            M->Next=NULL;

            M->coeff_num=a->coeff_num * b->coeff_num;
            M->index_num=a->index_num + b->index_num;

            Y1->Next=M;
            Y1=Y1->Next;

            b=b->Next;
        }
        b=L2->Next;
        Y1->Next=NULL;

        if(flag==1){
            T=Add(T1,T2);////////error
            flag++;
        }
        else if(flag>1){
            T=Add(T1,T);
        }
        else if(flag==0){
            flag=1;
            List t1=T1->Next;
            while(t1){
             List N=(List)malloc(sizeof(struct Node));
             N->coeff_num=t1->coeff_num;
             N->index_num=t1->index_num;

             Y2->Next=N;
             Y2=Y2->Next;

             List p,q;
             p=t1;
             q=t1->Next;
             free(p);
             t1=q;
            }
            Y2->Next=NULL;
        }

        a=a->Next;
    }
    return T;
}
