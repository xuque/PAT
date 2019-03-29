#include <iostream>
#include <queue>
#include <stack>

using namespace std;

queue<int>Q1;
queue<int>Q2;

typedef struct TreeNode* Tree;
struct TreeNode{
    int Data;
    Tree Left;
    Tree Right;
};
void Insert(Tree &root,int number)
{
    if(root==NULL){
        Tree NewNode=new TreeNode;
        NewNode->Data=number;
        NewNode->Left=NewNode->Right=NULL;
        root=NewNode;
        return ;
    }
    else{
        if(number>root->Data) Insert(root->Right,number);
        else if(number<root->Data) Insert(root->Left,number);
        else return ;
    }
}
Tree BuildTree(int number)
{
    Tree T=NULL;
    for(int j=0;j<number;j++){
        int getData;
        cin>>getData;
        Insert(T,getData);
    }
    return T;
}
void InOrder(Tree T, queue<int>&Q)
{
    if(T!=NULL){
         Q.push(T->Data);
         InOrder(T->Left,Q);
         InOrder(T->Right,Q);
    }
    else return ;
}
void Judge(Tree T1, Tree T2, int number)
{
    while(!Q1.empty()) Q1.pop();
    while(!Q2.empty()) Q2.pop();
    InOrder(T1,Q1);
    InOrder(T2,Q2);
    bool flag=1;
    if(Q1.empty()||Q2.empty()) flag=0;
    while(!Q1.empty()&&!Q2.empty()){
        if(Q1.front()!=Q2.front()){
            flag=0;
            break;
        }
        else{
            Q1.pop();
            Q2.pop();
        }
    }
    if(flag==1) cout<<"Yes"<<endl;
    else        cout<<"No"<<endl;
}

int main()
{
    while(1){
        int number,length;
        cin>>number;
        if(number==0) break;

        cin>>length;
        Tree T;
        for(int i=0;i<=length;i++){
            Tree T1;
            if(i==0) T=BuildTree(number);
            else    T1=BuildTree(number);

            if(i>0) Judge(T,T1,number);
        }
    }

    return 0;
}

