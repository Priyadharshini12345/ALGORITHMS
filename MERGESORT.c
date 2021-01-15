#include<stdio.h>
int arr[50];
void merge(int arr[], int beg,int mid,int end){
        int index,i,j;
        int t[50],k;
        index=beg;
        i=beg;
        j=mid+1;
        while((i<=mid) &&(j<=end)){
                if(arr[i]<arr[j]){
                        t[index]=arr[i];
                        i++;
                        index++;
                }
                else{
                        t[index]=arr[j];
                        j++;
                        index++;
                }
        }
        if(i>mid){
                while(j<=end){
                        t[index]=arr[j];
                        index++;
                        j++;
                }
        }
        else{
                while(i<=mid){
                        t[index]=arr[i];
                        index++;
                        i++;
                }
        }
        for(k=beg;k<index;k++)
                arr[k]=t[k];
}
void mergesort(int beg,int end,int arr[]){
        if(beg<end){
		int mid=(beg+end)/2;
        	mergesort(beg,mid,arr);
        	mergesort(mid+1,end,arr);
        	merge(arr,beg,mid,end);
	}
}
void main(){
        int n,i;
        printf("Enter the number of array elements\n");
        scanf("%d",&n);
        printf("Enter the array elements\n");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        mergesort(0,n-1,arr);
        printf("Sorted array elements\n");
        for(i=0;i<n;i++)
        printf("%d\t",arr[i]);
}