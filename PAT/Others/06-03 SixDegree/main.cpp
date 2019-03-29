#include <iostream>
#include <stdio.h>
#include <queue>
#define MVNum 10001
using namespace std;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct VNode{
    ArcNode *FirstArc;
}VNode,AdjList[MVNum];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
void CreateGraph(ALGraph &G)
{
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++){
        G.vertices[i].FirstArc=NULL;
    }
    for(int i=0;i<G.arcnum;i++){
        int v1,v2;
        cin>>v1>>v2;
        ArcNode *NewArc_1 = new ArcNode;
        NewArc_1->adjvex = v2;
        NewArc_1->next   = G.vertices[v1].FirstArc;
        G.vertices[v1].FirstArc = NewArc_1;

        ArcNode *NewArc_2 = new ArcNode;
        NewArc_2->adjvex = v1;
        NewArc_2->next   = G.vertices[v2].FirstArc;
        G.vertices[v2].FirstArc = NewArc_2;
    }
}
int BFS(ALGraph G, int t)
{
    int cnt=1,level=0,last=t,tail=0;
    bool Visited[G.vexnum+1]={false};
    ArcNode *p = G.vertices[t].FirstArc;
    queue<int>Q;
    if(p==NULL) return cnt;
    else {
        Q.push(t);
        Visited[t]=true;
    }
    while(!Q.empty()){
        int flag = Q.front();
        Q.pop();
        p = G.vertices[flag].FirstArc;
        while(p!=NULL){
            int temp = p->adjvex;
            if(!Visited[temp]){
                cnt++;
                Q.push(temp);
                tail = temp;
                Visited[temp] = true;
            }
            p = p->next;
        }
        if(flag == last){
            level++;
            last=tail;
        }
        if(level==6) break;
    }
    return cnt;
}
int main()
{
    int cnt=0;
    double percent;
    ALGraph G;
    CreateGraph(G);
    for(int i=1;i<=G.vexnum;i++){
        cnt = BFS(G,i);
        percent = double(cnt) *100/ double(G.vexnum);
        printf("%d: %.2lf%%",i,percent);
        if(i!=G.vexnum) printf("\n");
    }

    return 0;
}
