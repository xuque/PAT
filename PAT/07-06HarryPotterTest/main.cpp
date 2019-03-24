#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#define  MaxNumber 101
#define  NoPath    9999
using namespace std;

int Graph[MaxNumber][MaxNumber];
int VertexNum,EdgeNum;
bool Visited[MaxNumber]={false};
void CreateGraph()
{
    int Vertex_1,Vertex_2,Weigh;
    scanf("%d %d",&VertexNum,&EdgeNum);
    for(int i=1;i<=VertexNum;i++){
        for(int j=1;j<=VertexNum;j++){
            Graph[i][j] = NoPath;
        }
    }
    for(int i=0;i<EdgeNum;i++){
        scanf("%d %d %d",&Vertex_1,&Vertex_2,&Weigh);
        Graph[Vertex_1][Vertex_2] = Weigh;
        Graph[Vertex_2][Vertex_1] = Weigh;
    }
}
void EveryAnimals(int i)
{
    int t = 1;
    Visited[i]=true;
    for(t=1;t<=VertexNum;t++){
        if(!Visited[t]&&Graph[i][t]!=NoPath)
            EveryAnimals(t);
    }
}
bool Check()
{
    for(int i=1;i<=VertexNum;i++){
        if(!Visited[i])
            return false;
    }
    return true;
}
int ShortestPath(int v0)
{
    int v,w,i;
    bool S[VertexNum+1]={false};
    int D[VertexNum+1],Path[VertexNum+1];
    for(v=1;v<=VertexNum;v++){
        S[v]=false;
        D[v]=Graph[v0][v];
        if(D[v]<NoPath) Path[v]=v0;
        else Path[v]=-1;
    }
    S[v0]=true;
    D[v0]=0;
    for(i=1;i<=VertexNum;i++){
        int minPath = NoPath;
        for(w=1;w<=VertexNum;w++){
            if(!S[w]&&D[w]<minPath){
                v=w;
                minPath=D[w];
            }
        }
        S[v]=true;
        for(w=1;w<=VertexNum;w++){
            if(!S[w]&&(D[v]+Graph[v][w]<D[w])){
                D[w]=D[v]+Graph[v][w];
                Path[w]=v;
            }
        }
    }
    int temp=0;
    for(i=1;i<=VertexNum;i++){
        if(D[i]>temp&&D[i]!=NoPath) temp = D[i];
    }
    return temp;
}
int main()
{
    bool Ok;
    CreateGraph();
    EveryAnimals(1);
    Ok = Check();
    if(Ok){
        int ShortPath=NoPath,Min,temp;
        for(int i=1;i<=VertexNum;i++){
            temp=ShortestPath(i);
            if(temp<ShortPath){
                Min = i;
                ShortPath = temp;
            }
        }
        printf("%d %d",Min,ShortPath);
    }
    else printf("0");
    return 0;
}
