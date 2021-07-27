#include <iostream>
using namespace std;
#define maxsize 100
#define INF 99999
#include "queue"
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* nextarc;
    int info;

}ArcNode;
typedef struct Vnode{
    char data;
    ArcNode* firstarc;

}Vnode,AdjList[maxsize];

typedef struct {
    AdjList vertices;
    int vexnum,arcnum;
}ALGraph;
int Locate(ALGraph G,char v)
{
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data==v)
            return i;
    }
    return -1;
}
bool CreateUDG(ALGraph &G)
{
    int i,k;
    cin>>G.vexnum>>G.arcnum;
    for(i=0;i<G.vexnum;i++)
    {
        cin>>G.vertices[i].data;
        G.vertices[i].firstarc= nullptr;
    }
    for(k=0;k<G.arcnum;k++)
    {
        char v1,v2;
        int i,j;
        cin>>v1>>v2;
        i= Locate(G,v1);
        j= Locate(G,v2);
        ArcNode *p1=new ArcNode;
        ArcNode *p2=new ArcNode ;
        p1->adjvex=j;
        p1->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p1;
        p2->adjvex=i;
        p2->nextarc=G.vertices[j].firstarc;
        G.vertices[j].firstarc=p2;
    }
    return true;

}
void Print_ALGraph(ALGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++)
    {
        Vnode temp=G.vertices[i];
        ArcNode *p=temp.firstarc;
        if(!p)
        {
            cout<<G.vertices[i].data<<endl;
        } else{
            cout<<temp.data;
            while (p)
            {
                cout<<"->";
                cout<<p->adjvex;
                p=p->nextarc;
            }
        }
        cout<<endl;

    }

}
bool visited[maxsize];
void DFS(ALGraph G,int v)
{   ArcNode *p=new ArcNode ;

    cout<<v<<" ";
    visited[v]= true;

    p=G.vertices[v].firstarc;
    while (p)
    {
        int w=p->adjvex;
        if(!visited[w])
            DFS(G,w);
        p=p->nextarc;
    }

}
void BFS(ALGraph G,int v)
{
    int i=0;
    for(i=0;i<G.vexnum;i++)
        visited[i]= false;
    cout<<v<<" ";
    queue<int>Q;
    Q.push(v);
    ArcNode *p=new ArcNode ;
    while (!Q.empty())
    {
        int t=Q.front();
        Q.pop();
        for(p=G.vertices[t].firstarc;p!= nullptr;p=p->nextarc)
        {
            if(!visited[p->adjvex])
            {
                cout<<p->adjvex<<" ";
                visited[p->adjvex]= true;
                Q.push(p->adjvex);
            }
        }
    }

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    ALGraph G;
    CreateUDG(G);
    Print_ALGraph(G);

    BFS(G,0);
    int i=0;
    for(i=0;i<G.vexnum;i++)
        visited[i]= false;
    cout<<"\n"<<endl;cout<<"\n"<<endl;
    DFS(G,1);
    return 0;
}
