#include<stdio.h>
int arr[10],w[10],sum,n;
int count=0;
int condition(int i,int wt,int total){
        return((wt+total>=sum) && ((wt==sum)||(wt+w[i+1]<=sum)));

}
void subset(int i,int wt,int total){
        int j;
        if(condition(i,wt,total)){
                if(wt==sum){
                        for(j=0;j<=i;j++){
                                if(arr[j])
                                printf("%d\t",w[j]);
                        }
                        printf("\n");
                        count++;
                }
                else{
                        arr[i+1]=1;
                        subset(i+1,wt+w[i+1],total-w[i+1]);
                        arr[i+1]=0;
                        subset(i+1,wt,total-w[i+1]);
                }
        }
}
void main(){
        int total=0;
        int i,j,temp;
        printf("Enter the number of elements of set\n");
        scanf("%d",&n);
        printf("Enter the elements/weights of the set\n");
	 for(i=0;i<n;i++)
                scanf("%d",&w[i]);
        printf("Enter the sum value:\n");
        scanf("%d",&sum);
        for(i=0;i<n;i++){
                for(j=i+1;j<n;j++){
                        if(w[i]>w[j]){
                                temp=w[i];
                                w[i]=w[j];
                                w[j]=temp;
                        }
                }
        }
        for(i=0;i<n;i++)
                total=total+w[i];
        if(total<sum)
                printf("Sum of subsets is not possible\n");
        else{
        for(i=0;i<n;i++)
                arr[i]=0;
        printf("Elements included in subset to obtain the sum are:\n");
        subset(-1,0,total);
        printf("Total number of solutions:%d\n",count);
        }
}