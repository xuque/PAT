#include <iostream>
#include <queue>
#define Maxsize 31

using namespace std;

typedef struct TreeNode* Tree;
struct TreeNode{
    int data;
    Tree Left;
    Tree Right;
};

int postOrder[Maxsize];
int inOrder[Maxsize];

Tree CreateTree(int postL, int postR, int inL, int inR)
{
    if(postL>postR) return NULL;
    int k;
    for(k=inL;k<=inR;k++)    if(inOrder[k]==postOrder[postR]) break;//k 代表根在inOrder中的位置
    Tree NewNode=new TreeNode;
    NewNode->data=inOrder[k];
    int num=k-inL;
    NewNode->Left=CreateTree(postL,postL+num-1,inL,k-1);
    NewNode->Right=CreateTree(postL+num,postR-1,k+1,inR);
    return NewNode;
}

int main()
{
    int number,i;
    cin>>number;
    for(i=0;i<number;i++) cin>>postOrder[i];
    for(i=0;i<number;i++) cin>>inOrder[i];
    Tree root=CreateTree(0,number-1,0,number-1);

    queue<Tree>Level;
    Tree Node=root;
    Level.push(root);
    while(!Level.empty()){
        cout<<Node->data;
        number--;
        if(number) cout<<" ";
        if(Node->Left!=NULL) Level.push(Node->Left);
        if(Node->Right!=NULL) Level.push(Node->Right);
        Level.pop();
        Node=Level.front();
    }

    return 0;
}
