#include <iostream>

template<class T>
void DeleteNode(T*& ptr)
{
    delete ptr;
    ptr = nullptr;
}

typedef struct Tree_Node* TreeNode;
struct Tree_Node
{
    ~Tree_Node()
    {
        DeleteNode(_left);
        DeleteNode(_right);
    }
    int _data;
    int _height;
    TreeNode _left;
    TreeNode _right;
};

int MAX(int a,int b)
{
    return ((a > b) ? a : b);
}

int TreeHeight(TreeNode root)
{
    if (root == NULL) return 0;
    else if (root->_left == NULL && root->_right == NULL) return 1;
    else if (root->_left == NULL) return (TreeHeight(root->_right) + 1);
    else if (root->_right == NULL) return (TreeHeight(root->_left) + 1);
    else return ( MAX(TreeHeight(root->_left), TreeHeight(root->_right)) + 1 );
}
int UpdateHeight(TreeNode root)
{
    return ( MAX(TreeHeight(root->_left),TreeHeight(root->_right))+1 );
}
TreeNode LL(TreeNode &root)
{
    TreeNode left_child = root->_left;
    root->_left = left_child->_right;
    left_child->_right = root;
    root->_height = UpdateHeight(root);
    left_child->_height = UpdateHeight(left_child);
    return left_child;
}
TreeNode RR(TreeNode &root)
{
    TreeNode right_child = root->_right;
    root->_right = right_child->_left;
    right_child->_left = root;
    root->_height = UpdateHeight(root);
    right_child->_height = UpdateHeight(right_child);
    return right_child;
}
TreeNode LR(TreeNode &root)
{
    TreeNode left_child = root->_left;
    TreeNode lr_node = left_child->_right;
    left_child->_right = lr_node->_left;
    root->_left = lr_node->_right;
    lr_node->_left = left_child;
    lr_node->_right = root;
    root->_height = UpdateHeight(root);
    left_child->_height = UpdateHeight(left_child);
    lr_node->_height = UpdateHeight(lr_node);
    return lr_node;
}
TreeNode RL(TreeNode &root)
{
    TreeNode right_child = root->_right;
    TreeNode rl_node = right_child->_left;
    right_child->_left = rl_node->_right;
    root->_right = rl_node->_left;
    rl_node->_left = root;
    rl_node->_right = right_child;
    root->_height = UpdateHeight(root);
    right_child->_height = UpdateHeight(right_child);
    rl_node->_height = UpdateHeight(rl_node);
    return rl_node;
}
int Balance(TreeNode root)
{
    return (TreeHeight(root->_left) - TreeHeight(root->_right));
}
void Insert(TreeNode &root, int number)
{
    if(root==NULL)
    {
        TreeNode node = new Tree_Node;
        node->_data=number;
        node->_height=1;
        node->_left=node->_right=NULL;
        root=node;
        return ;
    }
    else
    {
        if (number > root->_data) Insert(root->_right, number);
        if (number < root->_data) Insert(root->_left, number);
        root->_height=UpdateHeight(root);   //Up date the Height
        //* Rotate *//
        int NodeBalance = Balance(root); //Left Tree Height - Right Tree Height
        if (NodeBalance == 2)
        {    //L
            int NodeBalanceLeft = Balance(root->_left);
            if (NodeBalanceLeft == 1) //LL
            {  
                root = LL(root);
                return;
            }
            else if (NodeBalanceLeft == -1) //LR
            {  
                root = LR(root);
                return;
            }
        }
        else if (NodeBalance == -2)   //R
        {
            int NodeBalanceRight = Balance(root->_right);
            if (NodeBalanceRight == 1)   //RL
            {
                root = RL(root);
                return;
            }
            else if (NodeBalanceRight == -1)   //RR
            {
                root = RR(root);
                return;
            }
        }
        else return ;
    }
}
int main()
{
    int number;
    std::cin>>number;

    TreeNode root = NULL;
    for (int i = 0; i < number; i++)
    {
        int value;
        std::cin >> value;
        Insert(root, value);
    }

    std::cout << root->_data;
    return 0;
}
