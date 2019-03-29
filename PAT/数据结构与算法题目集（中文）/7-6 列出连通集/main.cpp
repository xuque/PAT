#include<stdio.h>
#include<stdlib.h>

#define MAXVEX 15

void CreateGraph( );
void DFS( int i);
void DFSTraverse();
void BFSTraverse();

int G[MAXVEX][MAXVEX],Nv,Ne;
int visited[MAXVEX];

int main()
{
    CreateGraph();
    DFSTraverse();
    BFSTraverse();
    return 0;
}

void CreateGraph()
{
    //用邻接矩阵表示图
    int i,j;
    int v1,v2;
    scanf("%d %d",&Nv,&Ne);
    for( i=0; i<Nv; i++)
    {
        for( j=0; j<Nv; j++)
        {
            G[i][j] = 0;  //初始化
        }
    }
    for( i=0; i<Ne; i++)  //注意这里是读入边
    {
        scanf("%d %d",&v1,&v2);
        G[v1][v2] = 1;
        G[v2][v1]= G[v1][v2];  //无向图对称
    }
}

void DFS( int i)
{
    int j;

    visited[i] = 1;
    printf("%d ",i);
    for( j=0; j<Nv; j++)
    {
        if( G[i][j] && !visited[j])
        {
            //如果存在ij之间的连线且j并未被访问过
            DFS (j);
        }
    }
}
void DFSTraverse( )
{
    int i;

    for( i=0; i<Nv; i++)
    {
        visited[i] = 0;  //初始化访问矩阵
    }
    for ( i=0; i<Nv; i++)
    {
        if( !visited[i])
        {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }
    }
}

void BFSTraverse( )
{
    int q[MAXVEX]={0};  //用数组表示队列
    int rear=-1,front=-1;
    int i,j;
    int temp;

    for( i=0; i<Nv; i++)
    {
        visited[i] = 0;
    }

    for( i=0; i<Nv; i++){
        if( !visited[i]){
            printf("{ ");
            visited[i] =1;
            q[++rear] = i;  //入队
            while( front<rear ){   //判断队列是否为空
                temp =q[++front];  //出队
                printf("%d ",temp);
                for( j=0; j<Nv;j++){
                    if( G[temp][j] && !visited[j]){
                        visited[j] = 1;
                        q[++rear] = j;
                    }
                }
            }
            printf("}\n");
        }
    }

}
