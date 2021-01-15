#include<stdio.h>
int partition(int a[],int l,int h){
        int pivot,temp,i,j;
        if(l<h){
                pivot=l;
                i=l;
                j=h;
                while(i<j){
                while(a[i]<=a[pivot] && i<h)
                        i++;
                while(a[j]>a[pivot])
                        j--;
                if(i<j){
                        temp=a[i];
                        a[i]=a[j];
                        a[j]=temp;
                }
                }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        }
        return j;
}
int kthsmallele(int arr[],int start,int end,int k){
        int r;
        if(start==end){
                if(start==k)
                        return arr[start];
                else
                        return 0;
        }
else{
                r=partition(arr,start,end);
                if(r==k)
                        return arr[r];
                else if(r<k)
                        return kthsmallele(arr,r+1,end,k);
                else
                        return kthsmallele(arr,start,r-1,k);
        }
}
void main(){
        int n,ans,k,i;
        printf("Enter the array size:\n");
        scanf("%d",&n);
        int arr[n];
        printf("Enter the array elements:\n");
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
        printf("Enter the k value\n");
        scanf("%d",&k);
        ans=kthsmallele(arr,0,n-1,k);
        printf("%d th smallest element is %d",k,ans);
}

