#include<stdio.h>                                                                                                                      
#define INF 999                                                                                                                        
#define n 4  
void floyd(int mat[][n]){                                                                                                                      
	int k,i,j;                                                                                                                             
	for(k=0;k<n;k++){                                                                                                                              
		for(i=0;i<n;i++){                                                                                                                              
			for(j=0;j<n;j++){                                                                                                                             
 				if(mat[i][j]>(mat[i][k]+mat[k][j]))                                                                                                            
					mat[i][j]=mat[i][k]+mat[k][j];                                                                                         
			}                                                                                                                              
		}                                                                                                                              
	}
	for(i=0;i<n;i++){                                                                                                                              
		for(j=0;j<n;j++){                                                                                                                             
 			if(mat[i][j]==INF)                                                                                                                             
				printf("%4s\t","INF");                                                                                                         
			else                                                                                                                                   
				printf("%4d\t",mat[i][j]);                                                                                                     
		}                                                                                                                                      
		printf("\n");                                                                                                                  
	}                                                                                                                              
}  
void main(){                                                                                                                                  
	int mat[n][n]={{0, 3, INF, 5},
                             {2, 0, INF, 4},
                                          {INF, 1, 0, INF},
                                                       {INF, INF, 2, 0}};
        	floyd(mat);
}             