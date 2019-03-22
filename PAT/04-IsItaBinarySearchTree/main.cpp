//#include <iostream>
//#include <stdio.h>
//#include <stack>
//#include <vector>
//using namespace std;
//
//typedef struct TreeNode* Tree;
//struct TreeNode{
//    int data;
//    Tree Left;
//    Tree Right;
//};
//void CreateTree(Tree &root,int number)
//{
//    if(root==NULL){
//        Tree NewNode=new TreeNode;
//        NewNode->data=number;
//        NewNode->Left=NULL;
//        NewNode->Right=NULL;
//        root=NewNode;
//        return ;
//    }
//    else{
//        if(number>=root->data) CreateTree(root->Right,number);
//        else CreateTree(root->Left,number);
//    }
//}
//
//int num=0;
//void postOrder(Tree root)
//{
//    if(root==NULL) return ;
//    else{
//        postOrder(root->Left);
//        postOrder(root->Right);
//        num--;
//        cout<<root->data;
//        if(num) cout<<" ";
//    }
//}
//
//int main()
//{
//    int number,i;
//    cin>>number;
//
//    int preOrder[number];
//    Tree root=NULL;
//    for(i=0;i<number;i++){
//        cin>>preOrder[i];
//        CreateTree(root,preOrder[i]);
//    }
//    bool flag=1;
//    if(flag){
//        printf("YES\n");
//        num=number;
//        postOrder(root);
//    }
//    else printf("NO");
//
//    return 0;
//}
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++; //Find the child->data > root->data
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}
