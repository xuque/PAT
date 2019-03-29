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
    //���ڽӾ����ʾͼ
    int i,j;
    int v1,v2;
    scanf("%d %d",&Nv,&Ne);
    for( i=0; i<Nv; i++)
    {
        for( j=0; j<Nv; j++)
        {
            G[i][j] = 0;  //��ʼ��
        }
    }
    for( i=0; i<Ne; i++)  //ע�������Ƕ����
    {
        scanf("%d %d",&v1,&v2);
        G[v1][v2] = 1;
        G[v2][v1]= G[v1][v2];  //����ͼ�Գ�
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
            //�������ij֮���������j��δ�����ʹ�
            DFS (j);
        }
    }
}
void DFSTraverse( )
{
    int i;

    for( i=0; i<Nv; i++)
    {
        visited[i] = 0;  //��ʼ�����ʾ���
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
    int q[MAXVEX]={0};  //�������ʾ����
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
            q[++rear] = i;  //���
            while( front<rear ){   //�ж϶����Ƿ�Ϊ��
                temp =q[++front];  //����
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
