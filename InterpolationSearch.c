#include<stdio.h>
#include<stdlib.h>
int inter(int arr[],int n,int x){
        int l=0,h=n-1;
        while(l<=h && x>=arr[l] && x<=arr[h]){
        if(l==h){
                if(arr[l]==x)
                        return l;
                else
                        return -1;
        }
        int pos=l+(((double)(h-l)/(arr[h]-arr[l]))*(x-arr[l]));
        if(arr[pos]==x)
                return pos;
        else if(arr[pos]<x)
                l=pos+1;
        else
                h=pos-1;
        }
        return -1;
}
void main(){
        int n,x,i;
        printf("Enter the seize of the array\n");
        scanf("%d",&n);
        int* arr=malloc(n*sizeof(int));
        printf("Enter the array elements\n");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf("Enter the element to search\n");
                scanf("%d",&x);
        int pos=inter(arr,n,x);
        if(pos==-1)
                printf("%d is not found",x);
        else
                printf("%d is found %d position\n",x,pos);
}

