#include <iostream>
#include <queue>
#include <cstring>
struct TreeNode
{
	TreeNode() = default;
	~TreeNode() = default;

	TreeNode(int index, int left_child, int right_child) :
		_index(index),
		_left_child(left_child),
		_right_child(right_child)
	{

	}

	int _index;
	int _left_child;
	int _right_child;
};

void Trans(char c, int& num)
{
	if (c == '-')
	{
		num = -1;
	}
	else
	{
		num = c - '0';
	}
}

void ConstructTree(std::vector<TreeNode>& tree, int node_nums, int& root)
{
	if (node_nums == 0)
	{
		return;
	}

	std::vector<int> find_root;
	find_root.resize(node_nums);
	::memset(&find_root[0], 0, node_nums * sizeof(int));
	tree.resize(node_nums);
	for (int i = 0; i < node_nums; ++i)
	{
		char c_left_child, c_right_child;
		int left_child, right_child;
		std::cin >> c_left_child >> c_right_child;
		Trans(c_left_child, left_child);
		Trans(c_right_child, right_child);

		TreeNode node(i, left_child, right_child);
		tree[i] = node;

		if (left_child != -1)
		{
			find_root[left_child] = -1;
		}
		if (right_child != -1)
		{
			find_root[right_child] = -1;
		}
	}

	for (int i = 0; i < node_nums; ++i)
	{
		if (find_root[i] == 0)
		{
			root = i;
		}
	}
}

int main()
{
	int num;
	std::cin >> num;
	
	std::vector<TreeNode> tree;
	tree.resize(num);
	
	int root = -1;
	ConstructTree(tree, num, root);

	std::queue<int> result_seq;
	std::queue<TreeNode> node_seq;
	node_seq.push(tree[root]);
	while (!node_seq.empty())
	{
		TreeNode node = node_seq.front();
		node_seq.pop();

		if (node._left_child != -1)
		{
			node_seq.push(tree[node._left_child]);
		}
		
		if (node._right_child != -1)
		{
			node_seq.push(tree[node._right_child]);
		}

		if (node._left_child == -1 && node._right_child == -1)
		{
			result_seq.push(node._index);
		}
	}

	while (!result_seq.empty())
	{
		int leave_value = result_seq.front();
		result_seq.pop();

		std::cout << leave_value;
		if (!result_seq.empty())
		{
			std::cout << " ";
		}
	}

	return 0;
}