#include<stdio.h>
void main(){
        float weight[50],profit[50],ratio[50],temp,temp2,temp3;
        float total=0,x[50];
        int i,j,n;
        float capacity;
        printf("Enter the number of items to be added\n");
        scanf("%d",&n);
        for(i=0;i<n;i++){
                printf("Enter the weight of item %d\n",i+1);
                scanf("%f",&weight[i]);
                printf("Enter the profit of item %d\n",i+1);
                scanf("%f",&profit[i]);
        }
        printf("Enter the capacity of knapsack\n");
        scanf("%f",&capacity);
        printf("Weight of items\n");
        for(i=0;i<n;i++){
                printf("%f\t",weight[i]);
        }
        printf("\n");
        printf("Profit of items\n");
        for(i=0;i<n;i++){
                printf("%f\t",profit[i]);
        }
        printf("\n");
        for(i=0;i<n;i++)
                ratio[i]=profit[i]/weight[i];     
		for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                        if(ratio[i]<ratio[j]){
                                temp=ratio[j];
				ratio[j]=ratio[i];
                                ratio[i]=temp;
                                temp2=weight[j];
                                weight[j]=weight[i];
                                weight[i]=temp2;
                                temp3=profit[j];
                                profit[j]=profit[i];
                                profit[i]=temp3;
                        }
                }
        }
        for(i=0;i<n;i++)
                x[i]=0;
        for(i=0;i<n;i++){
                if(weight[i]>capacity)
                        break;
                else{
                        x[i]=1;
                        total=total+profit[i];
                        capacity=capacity-weight[i];
                }
        }
        if(i<n)
                x[i]=capacity/weight[i];
        total=total+(x[i]*profit[i]);
        printf("The maximum profit obtained is %f\n",total);
}