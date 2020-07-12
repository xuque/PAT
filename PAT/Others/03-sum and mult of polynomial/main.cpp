#include <iostream>
#include <list>

struct Node 
{
	Node(int index, int coeff) : _index(index),
								 _coeff(coeff)
	{

	}

	~Node() = default;

	int	_index;
	int _coeff;
};

void Merge(const std::list<Node>& list_1, const std::list<Node>& list_2, std::list<Node>& result)
{
	result.clear();

	std::list<Node>::const_iterator iter_1 = list_1.begin();
	std::list<Node>::const_iterator iter_2 = list_2.begin();
	while (iter_1 != list_1.end() && iter_2 != list_2.end())
	{
		if (iter_1->_coeff == iter_2->_coeff)
		{
			int index = iter_1->_index + iter_2->_index;
			if (index != 0)
			{
				Node tmp(index, iter_1->_coeff);
				result.push_back(tmp);
			}
			++iter_1;
			++iter_2;
		}
		else if (iter_1->_coeff > iter_2->_coeff)
		{
			Node tmp = *iter_1;
			result.push_back(tmp);
			++iter_1;
		}
		else
		{
			Node tmp = *iter_2;
			result.push_back(tmp);
			++iter_2;
		}
	}
	
	while (iter_1 != list_1.end())
	{
		Node tmp = *iter_1;
		result.push_back(tmp);
		++iter_1;
	}

	while (iter_2 != list_2.end())
	{
		Node tmp = *iter_2;
		result.push_back(tmp);
		++iter_2;
	}
}

void Mult(const std::list<Node>& list_1, const std::list<Node>& list_2, std::list<Node>& result)
{
	std::list<Node> tmp_result;
	std::list<Node>::const_iterator iter_1 = list_1.begin();

	while (iter_1 != list_1.end())
	{
		tmp_result = result;
		std::list<Node> tmp_list;
		std::list<Node>::const_iterator iter_2 = list_2.begin();
		while (iter_2 != list_2.end())
		{
			int index = iter_1->_index * iter_2->_index;
			int coeff = iter_1->_coeff + iter_2->_coeff;
			if (index != 0)
			{
				Node tmp(index, coeff);
				tmp_list.push_back(tmp);
			}
			++iter_2;
		}
		Merge(tmp_list, tmp_result, result);
		++iter_1;
	}
}

int main()
{
	int num1, num2;
	std::list<Node> my_list_1;
	std::list<Node> my_list_2;

	std::cin >> num1;
	for (int i = 0; i < num1; ++i)
	{
		int coeff, index;
		std::cin >> index >> coeff;
		Node node(index, coeff);
		my_list_1.push_back(node);
	}

	std::cin >> num2;
	for (int i = 0; i < num2; ++i)
	{
		int coeff, index;
		std::cin >> index >> coeff;
		Node node(index, coeff);
		my_list_2.push_back(node);
	}

	std::list<Node> mult_result;
	Mult(my_list_1, my_list_2, mult_result);

	if (mult_result.size() == 0)
	{
		std::cout << (int)0 << " " << (int)0;
	}
	for (auto itr = mult_result.begin(); itr != mult_result.end();)
	{
		std::cout << itr->_index << " " << itr->_coeff;
		++itr;
		if (itr != mult_result.end())
		{
			std::cout << " ";
		}
	}
	
	std::cout << std::endl;
	std::list<Node> add_result;
	Merge(my_list_1, my_list_2, add_result);

	if (add_result.size() == 0)
	{
		std::cout << (int)0 << " " << (int)0;
	}
	for (auto itr = add_result.begin(); itr != add_result.end();)
	{
		std::cout << itr->_index << " " << itr->_coeff;
		++itr;
		if (itr != add_result.end())
		{
			std::cout << " ";
		}
	}

	return 0;
}