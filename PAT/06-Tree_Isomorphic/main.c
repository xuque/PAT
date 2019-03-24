#include <stdio.h>
#include <stdlib.h>

#define MaxTree 10
#define Tree int
#define ElementType char
#define null -1
struct TreeNode{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuildTree(struct TreeNode T[]);
Tree Isomorphic(Tree R1, Tree R2);

int main()
{
    Tree R1,R2;
    R1=BuildTree(T1);
    R2=BuildTree(T2);
    if(Isomorphic(R1,R2)) printf("Yes");
    else printf("No");

    return 0;
}
Tree BuildTree(struct TreeNode T[])
{
    Tree number;
    Tree Root;
    scanf("%d\n",&number);
    int check[MaxTree];
    if(number){
        int i=0;
        for(i=0;i<number;i++)   check[i]=0;
        for(i=0;i<number;i++){
            ElementType cl,cr;
            scanf("%c %c %c\n",&T[i].Element,&cl,&cr);
            if(cl!='-'){
                T[i].Left=cl-'0';
                check[T[i].Left]=1;
            }
            else T[i].Left=null;
            if(cr!='-'){
                T[i].Right=cr-'0';
                check[T[i].Right]=1;
            }
            else T[i].Right=null;
        }
        for(i=0;i<number;i++){
            if(!check[i]) break;
        }
        Root=i;
    }
    else Root=null;

    return Root;
}
int Isomorphic(Tree R1, Tree R2)
{
    if( (R1==null)&&(R2==null) )
        return 1; //both empty

    if( ((R1!=null)&&(R2==null))||((R1==null)&&(R2!=null)) )
        return 0; //one of them is empty

    if( T1[R1].Element!=T2[R2].Element )
        return 0; //Root is different

    if( (T1[R1].Left==null)&&(T2[R1].Left==null) )
        return Isomorphic(T1[R1].Right, T2[R2].Right);//Both left is empty

    if( ((T1[R1].Left!=null)&&(T2[R2].Left!=null))&&((T1[T1[R1].Left].Element)==(T2[T2[R2].Left].Element)) )
        return ( Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right,T2[R2].Right) );
    else
        return ( Isomorphic(T1[R1].Left,T2[R2].Right) && Isomorphic(T1[R1].Right,T2[R2].Left) );
}
