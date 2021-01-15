#include<stdio.h>
int a[50];
void max_heap(int a[],int i,int n);
void heap_sort(int a[],int n){
        int t,i;
        for(i=n/2;i>=0;i--)
                max_heap(a,i,n);
        for(i=n-1;i>0;i--){
                t=a[0];
                a[0]=a[i];
                a[i]=t;
                max_heap(a,0,i);
        }
}
void max_heap(int a[],int i,int n){
        int child,t;
        while(2*i+1<n){
                child=2*i+1;
                if(a[child+1]>a[child] && child<n-1)
                        child=child+1;
                if(a[child]>a[i]){
                        t=a[child];
                        a[child]=a[i];
                        a[i]=t;
                }
                i=child;
        }
}
void main(){
        int n,i;
        printf("Enter the size of the array\n");
        scanf("%d",&n);
        printf("Enter the elements to be sorted\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        heap_sort(a,n);
        printf("Sorted elements:\n");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
}