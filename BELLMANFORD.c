#include<stdio.h>
#include<stdlib.h>
#define INF 9999
struct Edge{
        int u;
        int v;
        int w;
};
struct graph{
        int v;
        int e;
        struct Edge* edge;
};
void belman(struct graph* g,int src){
        int i,j,u,v,w,cost[50];
        for(i=1;i<=g->v;i++)
                cost[i]=INF;
        cost[src]=0;
        for(i=1;i<=g->v-1;i++){
                for(j=0;j<g->e;j++){
                        u=g->edge[j].u;
                        v=g->edge[j].v;
                        w=g->edge[j].w;
                        if(cost[u]!=INF && cost[v]>cost[u]+w)
                                cost[v]=cost[u]+w;
                }
        }
for(i=0;i<g->e;i++){
                u=g->edge[i].u;
                v=g->edge[i].v;
                w=g->edge[i].w;
                if(cost[u]!=INF && cost[v]>cost[u]+w){
                        printf("Negative cycle detected\n");
                        return;
                }
        }
        printf("Shortest path distance\n");
        for(i=1;i<=g->v;i++)
                printf("%d\n",cost[i]);
}
void main(){
        int n,ed,v1,v2,e1,i;
        struct graph* g=(struct graph*)malloc(sizeof(struct graph));
        printf("Enter the number of vertices\n");
        scanf("%d",&n);
        printf("Enter the number of edges\n");
        scanf("%d",&ed);
        g->v=n;
        g->e=ed;
        g->edge=(struct Edge*)malloc(g->e*sizeof(struct Edge));
        for(i=0;i<g->e;i++){
                printf("Enter the start vertex\n");
                scanf("%d",&v1);
                printf("Enter the destination vertex\n");
                scanf("%d",&v2);
                printf("Enter the weight of the edge\n");
                scanf("%d",&e1);
                g->edge[i].u=v1;
                g->edge[i].v=v2;
                g->edge[i].w=e1;
        }
        belman(g,1);
}