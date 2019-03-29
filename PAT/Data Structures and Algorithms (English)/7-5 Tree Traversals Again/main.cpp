#include <iostream>
#include <vector>
#include <stack>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;
const int Maxsize=50;
int Preorder[Maxsize];
int Inorder[Maxsize];
int number=0;

typedef struct Tree_Node* TreeNode;
struct Tree_Node{
    int Data;
    TreeNode Left;
    TreeNode Right;
};

TreeNode CreateTree(int Pre_L, int Pre_R, int in_L, int in_R)
{
    if(Pre_L>Pre_R){
        return NULL;
    }
    TreeNode root=new Tree_Node;
    root->Data=Preorder[Pre_L];
    int k;
    for(k=in_L;k<in_R;k++){
        if(Preorder[Pre_L]==Inorder[k])
            break;
    }
    int Left_number=k-in_L;
    root->Left=CreateTree(Pre_L+1,Pre_L+Left_number,in_L,k-1);
    root->Right=CreateTree(Pre_L+Left_number+1,Pre_R,k+1,in_R);

    return root;
}
void Post_Traversals(TreeNode root)
{
    if(root==NULL){
        return ;
    }
    Post_Traversals(root->Left);
    Post_Traversals(root->Right);
    if(root->Data!=Preorder[0])
        cout<<root->Data<<" ";
    else
        cout<<root->Data;
}

int main()
{
    cin>>number;

    int Pre_number=0;
    int In_number=0;
    char s[5];
    stack<int> Tree_Stack;

    for(int i=0;i<2*number;i++){
        cin>>s;
        if(!strcmp(s,"Push")){
            int Push_number;
            cin>>Push_number;
            Preorder[Pre_number++]=Push_number;
            Tree_Stack.push(Push_number);
        }
        else{
            Inorder[In_number++]=Tree_Stack.top();
            Tree_Stack.pop();
        }
    }
    TreeNode root=CreateTree(0,number-1,0,number-1);
    Post_Traversals(root);

    return 0;
}
