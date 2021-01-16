#include<stdio.h>
int cost[100][100];
int parent[100];
int find(int i){
        while(i!=parent[i])
                i=parent[i];
        return i;
}
int uni(int i,int j){
        if(i!=j){
                parent[j]=i;
                return 1;
        }
        else
                return 0;
}
void main(){
        int u,v,x,y,wt,i,n,j,total=0,v1,v2,k;
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
                parent[i]=i;
        }
        printf("COST ADJACENCY MATRIX IS\n");
        for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                        printf("%d\t",cost[i][j]);
                }
                printf("\n");
        }
        printf("MINIMUM SPANNING TREE...\n");
	int e=0;
        while(e<n-1){
                int min=999999;
                for(i=1;i<=n;i++){
                        for(j=1;j<=n;j++){
                                if(cost[i][j]!=0){
                                if(find(i)!=find(j) && (cost[i][j]<min)){
                                        min=cost[i][j];
                                        v1=i;
                                        x=i;
                                        v2=j;
                                        y=j;
                                }

                        }
                        }
                        }
                if(uni(x,y)){
                        printf("%d -> %d = %d\n",v1,v2,min);
                        total=total+min;
                        e++;
			}
        }
        printf("Minimum cost of a spanning tree is %d\n",total);

}