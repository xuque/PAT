#include <iostream>
#include <stdio.h>

using namespace std;
const int Maxsize=10001;
////***///
// e.g connect: 1-3-5 2-4-6 7 8
// ||||  array_index 0  1  2  3  4  5  6  7
// ||||  data        1  2  3  4  5  6  7  8
// ||||  fatherNode  2  3  4  5  -1 -1 -1 -1  the data is his father's index in the array
// ||||  in function "find()" the array_index = data - 1;
////***///
typedef int SetType[Maxsize];

int Find(SetType S, int x)
{
////// First
//    for(;S[x]>=0;x=S[x]) ;
//    return x;

/////  Second
    if(S[x]<0) return x;
    else       return S[x]=Find(S,S[x]);
}
void Union(SetType S, int Root1, int Root2)
{
/////// First
//    S[Root2]=Root1;  // Root2->Root1

////// Second  S[Root] = -HEIGHT
//    if(S[Root1]<S[Root2])  S[Root2]=Root1; // H->Root1 > H->Root2
//    else{
//        if(S[Root1]==S[Root2]) S[Root2]--; // Height --
//        S[Root1]=Root2;
//    }

////// Third  S[Root] = -NUMBER
    if(S[Root1]>S[Root2]){
        S[Root2] +=S[Root1];
        S[Root1] = Root2;
    }
    else{
        S[Root1] +=S[Root2];
        S[Root2] = Root1;
    }
}
void Initialization(SetType S,int n)
{
    for(int i=0;i<n;i++)
        S[i]=-1;
}
void Input_connection(SetType S)
{
    int u,v;
    int Root1,Root2;
    cin>>u>>v;
    Root1=Find(S,u-1);
    Root2=Find(S,v-1);
    if(Root1!=Root2)
        Union(S,Root1,Root2);
}
void Check_connection(SetType S)
{
    int u, v;
    int Root1, Root2;
    scanf("%d %d\n", &u, &v);
    Root1 = Find(S, u-1);
    Root2 = Find(S, v-1);
    if ( Root1 == Root2 )  printf("yes\n");
    else                   printf("no\n");
}
void Check_network(SetType S, int n)
{
    int i, counter = 0;
    for (i=0; i<n; i++){
        if (S[i] < 0)   counter++;
    }
    if(counter == 1)    printf("The network is connected.\n");
    else                printf("There are %d components.\n", counter);
}

int main()
{
    SetType S;
    int n;
    char in;
    cin>>n;
    Initialization(S,n);
    do{
        cin>>in;
        switch(in){
        case 'I':Input_connection(S);break;
        case 'C':Check_connection(S);break;
        case 'S':Check_network(S,n);break;
        default:break;
        }
    }while(in!='S');

    return 0;
}
