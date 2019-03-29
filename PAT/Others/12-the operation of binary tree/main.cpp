#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
//    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
//    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

BinTree Insert( BinTree BST, ElementType X )
{
    if(BST==NULL){
        BinTree NewNode=(BinTree)malloc(sizeof(struct TNode));
        NewNode->Data=X;
        NewNode->Left=NewNode->Right=NULL;
        BST=NewNode;
        return BST;
    }
    else{
        BinTree root=BST;
        while(1){
            if(X>root->Data&&root->Right!=NULL) root=root->Right;
            else if(X<root->Data&&root->Left!=NULL) root=root->Left;
            else if(X==root->Data) return BST;
            else{
                BinTree NewNode=(BinTree)malloc(sizeof(struct TNode));
                NewNode->Data=X;
                NewNode->Left=NewNode->Right=NULL;
                if(X>root->Data) root->Right=NewNode;
                else root->Left=NewNode;
                return BST;
            }
        }
    }
}
BinTree Delete( BinTree BST, ElementType X )
{
    if(BST==NULL||!BST){
        printf("Not Found\n");
        return BST;
    }
    if(X==BST->Data){
        if(BST->Left!=NULL&&BST->Right!=NULL){
            BinTree Node=BST->Right;
            if(Node->Left==NULL){
                BST->Data=Node->Data;
                BST->Right=Node->Right;
                free (Node);
                return BST;
            }
            else{
                BinTree Min=Node->Left;
                while(Min->Left!=NULL) Min=Min->Left;
                BST->Data=Min->Data;
                Node->Left=Min->Right;
                free (Min);
                return BST;
            }
        }
        else if(BST->Left!=NULL||BST->Right!=NULL){
            BinTree Node=BST;
            if(BST->Left!=NULL) BST=BST->Left;
            else                BST=BST->Right;
            free (Node);
            return BST;
        }
        else return NULL;
    }
    BinTree Tag=BST;
    BinTree A=Tag;
    int flag; //0 is left , 1 is right
    while(1){
        if(X>Tag->Data&&Tag->Right!=NULL){
            A=Tag;
            Tag=Tag->Right;
            flag=1;
        }
        else if(X<Tag->Data&&Tag->Left!=NULL){
            A=Tag;
            Tag=Tag->Left;
            flag=0;
        }
        else if(X==Tag->Data){   // Find the node , device three choose
            if(Tag->Left!=NULL&&Tag->Right!=NULL){ //two children
                BinTree Node=Tag->Right;
                if(Node->Left==NULL){
                    Tag->Data=Node->Data;
                    Tag->Right=Node->Right;
                    free (Node);
                    return BST;
                }
                else{
                    BinTree Min=Node->Left;
                    while(Min->Left!=NULL) Min=Min->Left;
                    Tag->Data=Min->Data;
                    Node->Left=Min->Right;
                    free (Min);
                    return BST;
                }
            }
            else if(Tag->Left==NULL||Tag->Right==NULL){ //only one child
                if(flag) A->Right=(Tag->Left!=NULL? Tag->Left:Tag->Right);
                else     A->Left=(Tag->Left!=NULL? Tag->Left:Tag->Right);
                free (Tag);
                return BST;
            }
            else{  //none child
                if(A->Data>Tag->Data){
                    A->Left=NULL;
                    free (Tag);
                    return BST;
                }
                else{
                    A->Right=NULL;
                    free (Tag);
                    return BST;
                }
            }
        }
        else{
            printf("Not Found\n");
            return BST;
        }
    }
}
Position Find( BinTree BST, ElementType X )
{
    BinTree Tag=BST;
    while(1){
        if(Tag==NULL) return NULL;
        else if(X>Tag->Data) Tag=Tag->Right;
        else if(X<Tag->Data) Tag=Tag->Left;
        else return Tag;
    }
}
Position FindMin( BinTree BST )
{
    BinTree Tag=BST;
    if(!BST) return NULL;
    while(1){
        if(Tag->Left==NULL) return Tag;
        else Tag=Tag->Left;
    }
}
Position FindMax( BinTree BST )
{
    BinTree Tag=BST;
    if(!BST) return NULL;
    while(1){
        if(Tag->Right==NULL) return Tag;
        else Tag=Tag->Right;
    }
}
