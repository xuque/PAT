#include <iostream>
#include <string>
#include <vector>
#include <stack>

struct TreeNode
{
	TreeNode() = default;
	TreeNode(int value, int left_child, int right_child) :
		_value(value),
		_left_child(left_child),
		_right_child(right_child)
	{
	}
	~TreeNode() = default;
	int _value;
	int _left_child;
	int _right_child;
};

int ConstructTree(std::vector<TreeNode>& tree, 
	const std::vector<int>& pre_order, 
	const std::vector<int>& in_order)		//flag means in_order tag 
{
	if (pre_order.size() == 0 || in_order.size() == 0)
	{
		return -1;
	}

	int index = 0;
	for (; index < pre_order.size(); ++index)
	{
		if (pre_order[index] == in_order[0])
		{
			break;
		}
	}

	int root_value = pre_order[index];
	int left_child = -1;
	int right_child = -1;

	std::vector<int> left_tree_pre, right_tree_pre;
	std::vector<int> left_tree_in, right_tree_in;

	//left tree
	if (index > 0)
	{
		left_tree_pre.resize(index);
		left_tree_in.resize(index);
		std::copy(pre_order.begin(), pre_order.begin() + index, left_tree_pre.begin());
		std::copy(in_order.begin() + 1, in_order.begin() + index + 1, left_tree_in.begin());
	}

	//right tree
	if ((pre_order.size() - index - 1) > 0)
	{
		right_tree_pre.resize(pre_order.size() - index - 1);
		right_tree_in.resize(pre_order.size() - index - 1);
		std::copy(pre_order.begin() + index + 1, pre_order.begin() + pre_order.size(), right_tree_pre.begin());
		std::copy(in_order.begin() + index + 1, in_order.begin() + in_order.size(), right_tree_in.begin());
	}

	left_child = ConstructTree(tree, left_tree_pre, left_tree_in);
	right_child = ConstructTree(tree, right_tree_pre, right_tree_in);

	TreeNode node(root_value, left_child, right_child);
	tree[root_value] = node;

	return root_value;
}

void PostOrder(const std::vector<TreeNode>& tree, std::vector<int>& post_order, int root)
{
	if (root == -1)
	{
		return;
	}

	PostOrder(tree, post_order, tree[root]._left_child);
	PostOrder(tree, post_order, tree[root]._right_child);
	post_order.push_back(tree[root]._value);
}

int main()
{
	int node_nums;
	std::cin >> node_nums;
	std::vector<int> pre_order;
	std::vector<int> in_order;

	int root = -1;
	std::stack<int> tree_stack;
	for (int i = 0; i < node_nums;)
	{
		std::string op;
		std::cin >> op;
		if (op == "Push")
		{
			int value;
			std::cin >> value;
			tree_stack.push(value);
			if (root == -1)
			{
				root = value;
			}
			in_order.push_back(value);
		}
		else
		{
			int value = tree_stack.top();
			pre_order.push_back(value);
			tree_stack.pop();
			++i;
		}
	}

	std::vector<TreeNode> tree;
	tree.resize(node_nums + 1); //index start at 0
	ConstructTree(tree, pre_order, in_order);

	std::vector<int> post_order;
	PostOrder(tree, post_order, root);
	for (int i = 0; i < post_order.size(); ++i)
	{
		std::cout << post_order[i];
		if (i != post_order.size() - 1)
		{
			std::cout << " ";
		}
	}

	return 0;
}