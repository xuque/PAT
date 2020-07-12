#include <iostream>
#include <vector>
#include <memory>
//#include <map>

//typedef std::map<TreeValue, TreeNode> Tree;
//typedef std::pair<TreeValue, TreeNode> ConstrNode;

template<class T>
void DeleteNode(T*& node)
{
	//if (node == nullptr)
	//{
	//	return;
	//}

	delete node;
	node = nullptr;
}

typedef int TreeValue;
struct TreeNode
{
	TreeNode() = default;
	TreeNode(TreeValue value, TreeNode* left_child = nullptr, TreeNode* right_child = nullptr) :
		_value(value),
		_left_child(left_child),
		_right_child(right_child)
	{
	}

	~TreeNode()
	{
		DeleteNode(_left_child);
		DeleteNode(_right_child);
	}
	
	TreeValue _value;
	TreeNode* _left_child;
	TreeNode* _right_child;
};

TreeNode* AllocNewNode(int value)
{
	return new TreeNode(value);
}

void InsertNode(TreeNode*& root, int value)
{
	if (root == nullptr)
	{
		root = AllocNewNode(value);
		return;
	}

	root->_value > value ? InsertNode(root->_left_child, value) : InsertNode(root->_right_child, value);
}

void ConstructTree(TreeNode*& root, int nums)
{
	TreeValue value;
	for (int i = 0; i < nums; ++i)
	{
		std::cin >> value;
		InsertNode(root, value);
	}
}

void PreOrder(const TreeNode* root, std::vector<int>& pre_order)
{
	if (root == nullptr)
	{
		return;
	}

	pre_order.push_back(root->_value);
	PreOrder(root->_left_child, pre_order);
	PreOrder(root->_right_child, pre_order);
}

void InOrder(const TreeNode* root, std::vector<TreeValue>& in_order)
{
	if (root == nullptr)
	{
		return;
	}

	PreOrder(root->_left_child, in_order);
	in_order.push_back(root->_value);
	PreOrder(root->_right_child, in_order);
}

bool JudgeSearchTree(TreeNode* tree, TreeNode* compare_tree)
{
	std::vector<TreeValue> tree_order;
	std::vector<TreeValue> compare_tree_order;
	
	PreOrder(tree, tree_order);
	PreOrder(compare_tree, compare_tree_order);
	if (tree_order != compare_tree_order)
	{
		return false;
	}

	tree_order.clear();
	compare_tree_order.clear();

	InOrder(tree, tree_order);
	InOrder(compare_tree, compare_tree_order);

	if (tree_order != compare_tree_order)
	{
		return false;
	}

	return true;
}

int main()
{
	int nums, compare_seq_len;
	while (true)
	{
		std::cin >> nums;
		if (nums == 0)
		{
			break;
		}

		std::cin >> compare_seq_len;
		TreeNode* root = nullptr;
		ConstructTree(root, nums);

		TreeNode* compare_root = nullptr;
		for (int i = 0; i < compare_seq_len; ++i)
		{
			ConstructTree(compare_root, nums);
			bool result = JudgeSearchTree(root, compare_root);
			if (result)
			{
				std::cout << "Yes" << std::endl;
			}
			else
			{
				std::cout << "No" << std::endl;
			}

			delete compare_root;
			compare_root = nullptr;
		}
		
		delete root;
		root = nullptr;
	}

	return 0;
}