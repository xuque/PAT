#include <iostream>
#include <stdio.h>
#include <algorithm>

const int number=1001;

using namespace std;

int in[number], store[number], n,index=0;
void inorder(int root)
{
    if(root>n) return ;
    inorder(2*root);
    in[root]=store[index++];
    inorder(2*root+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&store[i]);
    }
    sort(store,store+n); // min to max , also means the tree in-order
    inorder(1);
    for(int i=1;i<=n;i++){
        printf("%d",in[i]);
        if(i<n) printf(" ");
    }

    return 0;
}
