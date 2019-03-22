#include <iostream>
#include <string>

using namespace std;

const int MaxNumber = 10;
struct Node {
	int left;
	int right;
	//null == -1;
};
int main()
{
	int number;
	char left;
	char right;
	Node Tree[MaxNumber];
	cin >> number; //input number
	for (int i = 0;i < number;i++) {
		//left 
		cin >> left;
		if (left != '-') Tree[i].left = left - '0';
		else Tree[i].left = -1;
		//right
		cin >> right;
		if (right != '-') Tree[i].right = right - '0';
		else Tree[i].right = -1;
	}

	return 0;
}