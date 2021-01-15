#include<stdio.h>
void quicksort(int a[],int l,int h){
        int pivot;
        int i,j;
        int r,t;
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
                        t=a[i];
                        a[i]=a[j];
                        a[j]=t;
                }
        }
        t=a[pivot];
        a[pivot]=a[j];
        a[j]=t;
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
        }

}
void main(){
        int a[30];
        int i,n;
	   printf("Enter the number of elements of array\n");
	   scanf("%d",&n);
        printf("Enter the elements of array\n");
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
        quicksort(a,0,n-1);
	   printf("Sorted array\n");
        for(i=0;i<n;i++)
                printf("%d",a[i]);
}