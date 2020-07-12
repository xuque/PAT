#include <iostream>
#include <vector>

struct Result
{
	Result() = default;
	Result(int left, int right, int sum):
		_left(left),
		_right(right),
		_sum(sum){}

	~Result() = default;

	int _left;
	int _right;
	int _sum;
};

int main()
{
	std::vector<Result> my_result;

	int num;
	std::cin >> num;

	int sum = 0, tmp_sum = 0;
	int left_value, right_value;
	left_value = right_value = -1;

	int seq_left = 0, seq_right = 0;
	for (int i = 0; i < num; ++i)
	{
		int value;
		std::cin >> value;

		if (value >= 0 || sum > 0)
		{
			if (left_value == -1)
			{
				left_value = value;
				right_value = value;
			}

			tmp_sum += value;
			if (tmp_sum >= sum)
			{
				sum = tmp_sum;
				right_value = value;

				Result result(left_value, right_value, sum);
				my_result.push_back(result);
			}
			else if(tmp_sum < 0)
			{
				sum = tmp_sum = 0;
				left_value = right_value = -1;
			}
		}
		
		if (i == 0)
		{
			seq_left = value;
		}
		else if (i == num - 1)
		{
			seq_right = value;
		}
	}

	int max = -1;
	for (int i = 0; i < my_result.size(); ++i)
	{
		if (max < my_result[i]._sum)
		{
			left_value = my_result[i]._left;
			right_value = my_result[i]._right;
			max = sum = my_result[i]._sum;
		}
	}

	if (my_result.size() == 0 || sum < 0)
	{
		sum = 0;
		left_value = seq_left;
		right_value = seq_right;
	}

	std::cout << sum << " " << left_value << " " << right_value;
	return 0;
}