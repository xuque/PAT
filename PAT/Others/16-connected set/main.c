
/******邻接矩阵******/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MaxVertexNum 10
#define Error -1

typedef int WeightType;
typedef int DataType;
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv; //顶点数
    int Ne; //边数
    WeightType G[MaxVertexNum][MaxVertexNum];
//    DataType Data[MaxVertexNum]; //存顶点的数据
};
typedef PtrToGNode MGraph; //以邻接矩阵存储的图类型

typedef int Vertex; //用顶点下标表示顶点
MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;
    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv=VertexNum;
    Graph->Ne=0;

    for(V=0;V<Graph->Nv;V++)
        for(W=0;W<Graph->Nv;W++)
            Graph->G[V][W]=0;
    return Graph;
}
typedef struct ENode *PtrToENode;
struct ENode{
    Vertex V1,V2;
//    WeightType Weight;
};
typedef PtrToENode Edge;
void InsertEdge(MGraph Graph, Edge E)
{
//    Graph->G[E->V1][E->V2]=E->Weight;
//    Graph->G[E->V2][E->V1]=E->Weight;
    Graph->G[E->V1][E->V2]=1;
    Graph->G[E->V2][E->V1]=1;
}
MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv,i;

    scanf("%d",&Nv);
    Graph=CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
//            scanf("%d %d %d",&E->V1, &E->V2, &E->Weight);
            scanf("%d %d",&E->V1, &E->V2);
            InsertEdge(Graph,E);
        }
    }
//    Vertex V;
//    for(V=0;V<Graph->Nv;V++)
//        scanf(" %c",&(Graph->Data[V]));
    return Graph;
}
/*************Queue****************/
typedef int Queue_Element;
struct Q_Node{
    Queue_Element *Data;
    int Front,Rear;
    int Maxsize;
};
typedef struct Q_Node *Queue;

Queue CreatQueue(int Maxsize)
{
    Queue Q = (Queue)malloc(sizeof(struct Q_Node));
    Q->Data=(Queue_Element *)malloc(Maxsize*sizeof(Queue_Element));
    Q->Front=Q->Rear=0;
    Q->Maxsize=Maxsize;
    return Q;
}
bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}
bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%Q->Maxsize==Q->Front);
}
void AddQ(Queue Q, Queue_Element number)
{
    if(IsFull(Q)){
        printf("Is Full, Error");
        return ;
    }
    else{
        Q->Data[Q->Rear]=number;
        Q->Rear=(Q->Rear+1)%Q->Maxsize;
        return ;
    }
}
Queue_Element DelQ(Queue Q)
{
    if(IsEmpty(Q)){
        printf("Is Empty, Error");
        return Error;
    }
    else{
        int number=Q->Data[Q->Front];
        Q->Front=(Q->Front+1)%Q->Maxsize;
        return number;
    }
}
/**************BFS*****************/
void BFS(Vertex v)
{
    visited[v]=true;

}


////////////////////////////////////

int main()
{
    MGraph Graph=BuildGraph();

}
