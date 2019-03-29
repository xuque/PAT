#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define Max 101
#define Edge 50
using namespace std;

struct vertex{
    int x;
    int y;
};
int number,jump;
vertex Graph[Max];
bool Survive = false;
bool visited[Max]={false};

void DFS(int i)
{
    if(abs(Graph[i].x)+jump>=Edge||abs(Graph[i].y)+jump>=Edge){
        Survive = true ;
        return ;
    }
    else{
        visited[i] = true;
        double length;
        double x,y;
        for(int j=1;j<=number&&!Survive;j++){
             x = Graph[i].x-Graph[j].x;
             y = Graph[i].y-Graph[j].y;
            length = sqrt(x*x+y*y);
            if(!i) length -=7.5;
            if(!visited[j]&& length<=jump)
                DFS(j);
        }
    }
}

int main()
{
    int i;
    scanf("%d %d",&number,&jump);
    Graph[0].x = 0;
    Graph[0].y = 0;
    for(i=1;i<=number;i++)
        scanf("%d %d",&Graph[i].x,&Graph[i].y);
    if(jump>=Edge) Survive = true;
    else DFS(0);
    if(Survive) printf("Yes");
    else        printf("No");
    return 0;
}
