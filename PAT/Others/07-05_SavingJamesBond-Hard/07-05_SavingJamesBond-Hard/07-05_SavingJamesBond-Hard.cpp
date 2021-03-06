// 07-05_SavingJamesBond-Hard.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stack>
#define MaxPath 99999
#define Max 102
#define Edge 50
using namespace std;
struct CoorNode {
	int x;
	int y;
};
CoorNode Coor[Max];

void ShortPath(int num, int jump)
{
	int i, x, y, V;
	int flag;
	int Path[Max];
	double Dist[Max];
	bool Collected[Max];
	for (i = 0;i <= num;i++) {
		Path[i] = -1;
		Dist[i] = MaxPath;
		Collected[i] = false;
	}
	Dist[0] = 0;
	bool success = false;
	double length;
	while (1) {
		double min = MaxPath;
		if (Collected[0] == false) {
			V = 0;
			min -= 1;
		}
		else {
			for (i = 1;i <= num;i++) {
				if (!Collected[i] && Dist[i] < min) {
					V = i;
					min = Dist[i];
				}
			}
		}
		if (min == MaxPath) 
			break;		//fail
		Collected[V] = true;
		for (i = 1;i <= num;i++) { //find adjacency node
			if (i != V && Collected[i] == false) {
				x = Coor[i].x - Coor[V].x;
				y = Coor[i].y - Coor[V].y;
				length = sqrt(x*x + y*y);
				if (V == 0) length -= 7.5;
				if (length <= jump && Dist[V] + length < Dist[i]) {
					Dist[i] = Dist[V] + length;
					Path[i] = V;
					if (abs(Coor[i].x - Edge) <= jump || abs(Coor[i].y - Edge) <= jump) { //jump successful
						success = true;
						flag = i;
					}
				}
			}
		}
	}
	if (!success)	printf("0");
	else{
		i = Path[flag];
		stack<int>S;
		while (i) {
			S.push(i);
			i = Path[i];
		}
		while (!S.empty()) {
			i = S.top();
			S.pop();
			printf("%d %d", Coor[i].x, Coor[i].y);
			if (!S.empty()) printf("\n");
		}
	}
}
int main()
{
	int i, number, jump;
	scanf_s("%d %d", &number, &jump);
	Coor[0].x = Coor[0].y = 0;
	for (i = 1;i <= number;i++) {
		scanf_s("%d %d", &Coor[i].x, &Coor[i].y);
	}
	ShortPath(number,jump);

	return 0;
}
