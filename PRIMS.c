#include<stdio.h>
int cost[100][100];
int tree[100];
void main(){
        int u,v,wt,i,n,j,total=0,v1,v2,k;
        printf("Enter the number of nodes\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++){
                printf("Enter the starting vertex\n");
                scanf("%d",&u);
                printf("Enter the ending vertex\n");
                scanf("%d",&v);
                printf("Enter the weight of %d and %d\n",u,v);
                scanf("%d",&wt);
                cost[u][v]=wt;
                cost[v][u]=wt;
        }
        printf("COST ADJACENCY MATRIX IS\n");
        for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                        printf("%d\t",cost[i][j]);
                }
                printf("\n");
        }
        for(i=1;i<=n;i++)
                tree[i]=0;
        tree[1]=1;
        printf("MINIMUM SPANNING TREE...\n");
        for(k=2;k<=n;k++){
                int min=999999;
                for(i=1;i<=n;i++){
                        for(j=1;j<=n;j++){
                                if(cost[i][j]!=0 && ((tree[i] && !tree[j])||(tree[j] && !tree[i]))){
                                if(cost[i][j]<min){
                                        min=cost[i][j];
                                        v1=i;
                                        v2=j;
                                }
                                }
	}
                }
                printf("%d -> %d = %d\n",v1,v2,min);
                tree[v1]=1;
                tree[v2]=1;
                total=total+min;
        }
        printf("Minimum cost of a spanning tree is %d\n",total);

}