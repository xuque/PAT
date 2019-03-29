#include <iostream>

using namespace std;

typedef struct Tree_Node* TreeNode;
struct Tree_Node{
    int Data;
    int Height;
    TreeNode Left;
    TreeNode Right;
};
int MAX(int a,int b)
{
    return ( (a>b)?a:b );
}
int TreeHeight(TreeNode root)
{
    if(root==NULL) return 0;
    else if(root->Left==NULL&&root->Right==NULL) return 1;
    else if(root->Left==NULL) return ( TreeHeight(root->Right)+1 );
    else if(root->Right==NULL) return ( TreeHeight(root->Left)+1 );
    else return ( MAX( TreeHeight(root->Left), TreeHeight(root->Right) )+1 );
}
int UpDateHeight(TreeNode root)
{
    return ( MAX(TreeHeight(root->Left),TreeHeight(root->Right))+1 );
}
TreeNode LL(TreeNode &root)
{
    TreeNode LChild=root->Left;
    root->Left=LChild->Right;
    LChild->Right=root;
    root->Height=UpDateHeight(root);
    LChild->Height=UpDateHeight(LChild);
    return LChild;
}
TreeNode RR(TreeNode &root)
{
    TreeNode RChild=root->Right;
    root->Right=RChild->Left;
    RChild->Left=root;
    root->Height=UpDateHeight(root);
    RChild->Height=UpDateHeight(RChild);
    return RChild;
}
TreeNode LR(TreeNode &root)
{
    TreeNode LChild=root->Left;
    TreeNode LR_Node=LChild->Right;
    LChild->Right=LR_Node->Left;
    root->Left=LR_Node->Right;
    LR_Node->Left=LChild;
    LR_Node->Right=root;
    root->Height=UpDateHeight(root);
    LChild->Height=UpDateHeight(LChild);
    LR_Node->Height=UpDateHeight(LR_Node);
    return LR_Node;
}
TreeNode RL(TreeNode &root)
{
    TreeNode RChild=root->Right;
    TreeNode RL_Node=RChild->Left;
    RChild->Left=RL_Node->Right;
    root->Right=RL_Node->Left;
    RL_Node->Left=root;
    RL_Node->Right=RChild;
    root->Height=UpDateHeight(root);
    RChild->Height=UpDateHeight(RChild);
    RL_Node->Height=UpDateHeight(RL_Node);
    return RL_Node;
}
int Balance(TreeNode root)
{
    return (TreeHeight(root->Left)-TreeHeight(root->Right));
}
void Insert(TreeNode &root, int number)
{
    if(root==NULL){
        TreeNode NewTreeNode=new Tree_Node;
        NewTreeNode->Data=number;
        NewTreeNode->Height=1;
        NewTreeNode->Left=NewTreeNode->Right=NULL;
        root=NewTreeNode;
        return ;
    }
    else{
        if(number>root->Data) Insert(root->Right,number);
        if(number<root->Data) Insert(root->Left,number);
        root->Height=UpDateHeight(root);   //Up date the Height
        //* Rotate *//
        int NodeBalance=Balance(root); //Left Tree Height - Right Tree Height
        if(NodeBalance==2){    //L
            int NodeBalanceLeft=Balance(root->Left);
            if(NodeBalanceLeft==1){  //LL
                root=LL(root);
                return ;
            }
            else if(NodeBalanceLeft==-1){  //LR
                root=LR(root);
                return ;
            }
        }
        else if(NodeBalance==-2){    //R
            int NodeBalanceRight=Balance(root->Right);
            if(NodeBalanceRight==1){   //RL
                root=RL(root);
                return ;
            }
            else if(NodeBalanceRight==-1){  //RR
                root=RR(root);
                return ;
            }
        }
        else return ;
    }
}
int main()
{
    int number;
    cin>>number;
    TreeNode root=NULL;
    for(int i=0;i<number;i++){
        int getData;
        cin>>getData;
        Insert(root,getData);
    }
    cout<<root->Data;
    return 0;
}
