////#include <iostream>
////#include <stdlib.h>
////#include <stdio.h>
////#include <queue>
////using namespace std;
////
////typedef struct GraphNode *Graph;  // Matrix
////struct GraphNode{
////    int Nv;
////    int Ne;
////    int *GraphEdge; //array
////    int *VisitedDFS;
////    int *VisitedBFS;
////};
////Graph InitiaGraph(int vertex_num, int edge_num)
////{
////    int node_num = (vertex_num+1)*vertex_num/2;
////
////    Graph G = new GraphNode;
////    G->Nv   = vertex_num;
////    G->Ne   = edge_num;
////    G->GraphEdge = (int*)malloc(sizeof(int)*node_num);
////    G->VisitedDFS   = (int*)malloc(sizeof(int)*vertex_num);
////    G->VisitedBFS   = (int*)malloc(sizeof(int)*vertex_num);
////    for(int i=0;i<node_num;i++) G->GraphEdge[i]=0;
////    for(int i=0;i<vertex_num;i++) G->VisitedDFS[i]=1;
////    for(int i=0;i<vertex_num;i++) G->VisitedBFS[i]=1;
////    return G;
////}
////Graph Connect(Graph G, int edge_num)
////{
////    for(int i=0;i<edge_num;i++){
////        int vertex_1,vertex_2,index;
////        int line, column;
////        scanf("%d %d",&vertex_1,&vertex_2);
////        if(vertex_1>vertex_2){
////            line = vertex_1; column = vertex_2;
////        }
////        else {
////            line = vertex_2; column = vertex_1;
////        }
////        index = (line+1)*line/2+column;
////        G->GraphEdge[index]=1;
////    }
////    return G;
////}
////void DFS(Graph G, int i)
////{
////    if(G->VisitedDFS[i]){
////        printf("%d ",i);
////        G->VisitedDFS[i]=0;
////    }
////    else return ;
////
////    if(i<G->Nv/2){
////        int t=i+1;
////        while(t<G->Nv){
////            int index = (t+1)*t/2+i;
////            if(G->GraphEdge[index]) DFS(G,t);
////            t++;
////        }
////    }           //按列看
////    else{
////        int t=0;
////        while(t<i){
////            int index = (i+1)*i/2+t;
////            if(G->GraphEdge[index]) DFS(G,t);
////            t++;
////        }
////    }           //按行看
////}
////void BFS(Graph G, int i)
////{
//////    if(G->VisitedBFS[i]){
//////        printf("%d ",i);
//////        G->VisitedBFS[i]=0;
//////    }
//////    else return ;
////    int t=i+1;
////    queue<int>Q;
////    while(t<G->Nv){
////        int index = (t+1)*t/2+i;
////        if(G->GraphEdge[index]){
////            Q.push(t);
////            if(G->VisitedBFS[t]) printf("%d ",t);
////            G->VisitedBFS[t]=0;
////        }
////        t++;
////    }
////    while(!Q.empty()){
////        int a=Q.front();
////        BFS(G,a);
////        Q.pop();
////    }
////}
////
////int main()
////{
////    int vertex_num, edge_num;
////    scanf("%d %d",&vertex_num,&edge_num);
////    Graph G = InitiaGraph(vertex_num,edge_num);
////    G = Connect(G,edge_num);
////    for(int i=0;i<vertex_num;i++){
////        if(G->VisitedDFS[i]){
////            printf("{ ");
////            DFS(G,i);
////            printf("}\n");
////        }
////    }
////    for(int i=0;i<G->Nv;i++){
////        if(G->VisitedBFS[i]){
////            printf("{ %d ",i);
////            G->VisitedBFS[i]=0;
////            BFS(G,i);
////            printf("}");
////            bool flag=false;
////            for(int j=i;j<G->Nv;j++){
////                if(G->VisitedBFS[j]){
////                    flag=true;
////                    break;
////                }
////            }
////            if(flag) printf("\n");
////        }
////    }
////
////    return 0;
////}


////#include <iostream>
////#include <stdlib.h>
////#include <stdio.h>
////#include <queue>
////using namespace std;
////
////#define MAXVEX 15
////
////int Graph[MAXVEX][MAXVEX]={0},vertex,edge;
////int visited[MAXVEX]={0};
////
////void CreateGraph()
////{
////    for(int i=0;i<edge;i++){
////        int vertex1,vertex2;
////        scanf("%d %d",&vertex1,&vertex2);
////        Graph[vertex1][vertex2]=1;
////        Graph[vertex2][vertex1]=1;
////    }
////}
////void DFS(int i)
////{
////    visited[i]=0;
////    printf("%d ",i);
////    for(int j=0;j<vertex;j++)
////        if(visited[j]&&Graph[i][j]){
////            DFS(j);
////        }
////}
////void BFS(int i)
////{
////    queue<int>Q;
////    Q.push(i);
////    visited[i]=0;
////    while(!Q.empty()){
////        int t=Q.front();
////        printf("%d ",t);
////        Q.pop();
////        for(int j=0;j<vertex;j++){
////            if(visited[j]&&Graph[t][j]){
////                Q.push(j);
////                visited[j]=0;
////            }
////        }
////    }
////}
////int main()
////{
////    int i,j;
////    scanf("%d %d",&vertex,&edge);
////    CreateGraph();
////    //DFS
////    for(i=0;i<vertex;i++) visited[i]=1;
////    for(i=0;i<vertex;i++){
////        if(visited[i]){
////            printf("{ ");
////            DFS(i);
////            printf("}\n");
////        }
////    }
////    //BFS
////    for(i=0;i<vertex;i++) visited[i]=1;
////    for(i=0;i<vertex;i++){
////        if(visited[i]){
////            printf("{ ");
////            BFS(i);
////            printf("}\n");
////        }
////    }
////
////    return 0;
////}


