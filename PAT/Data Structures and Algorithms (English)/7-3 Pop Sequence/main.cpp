#include <iostream>
#include <stack>
#include <vector>

void PrintfResult(bool result)
{
	if (result)
	{
		std::cout << "YES";
	}
	else
	{
		std::cout << "NO";
	}
}

int main()
{
	int stack_cap, seq_len, check_num;
	std::cin >> stack_cap >> seq_len >> check_num;

	for (int i = 0; i < check_num; ++i)
	{
		std::stack<int> my_stack;
		std::vector<int> seq;
		seq.resize(seq_len);
		for (int j = 0; j < seq_len; ++j)
		{
			std::cin >> seq[j];
		}

		int limit = 0;
		bool result = true;
		for (int j = 0; j < seq_len; ++j)
		{
			int seq_num = seq[j];
			if (my_stack.empty() || limit < seq_num)
			{
				while (limit < seq_num)
				{
					++limit;
					my_stack.push(limit);
				}
				if (my_stack.size() > stack_cap)
				{
					result = false;
					break;
				}
			}

			if (my_stack.top() == seq_num)
			{
				my_stack.pop();
			}
			else
			{
				result = false;
				break;
			}
		}

		PrintfResult(result);
		if (i < check_num - 1)
		{
			std::cout << std::endl;
		}
	}

	return 0;
}