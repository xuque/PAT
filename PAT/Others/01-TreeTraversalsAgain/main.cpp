#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

struct TreeNode{
    int number;
    bool flag;
};
stack<TreeNode*> Tree;

void PopTree()
{
    TreeNode* Node=Tree.top();
    while(Node->flag){
        cout<<Node->number<<" ";
        Tree.pop();
        delete Node;
        Node=Tree.top();
    }
    Node->flag=true;
}
int main()
{
    int number;
    char s[5];

    cin>>number;
    for(int i=0;i<2*number;i++){
        cin>>s;
        if(!strcmp(s,"Push")){
            TreeNode* NewNode=new TreeNode;
            NewNode->flag=false;
            cin>>NewNode->number;
            Tree.push(NewNode);
        }
        else{
            PopTree();
        }
    }
    TreeNode* Node=Tree.top();
    while(!Tree.empty()){
        cout<<Node->number;
        Tree.pop();
        delete Node;
        if(!Tree.empty()){
            Node=Tree.top();
            cout<<" ";
        }
    }

    return 0;
}
