#include<stdio.h>
int a[50];
void insert(int key,int n){
        int h=key%n;
        int i=0;
        while(a[(h+i)%n]!=0 && i<n){
                i++;
        }
        if(i==n)
                printf("Hash table is full\n");
        else
                a[(h+i)%n]=key;
}
void search(int key,int n){
        int i=0;
        int found=0;
        int h=key%n;
        while(a[(h+i)%n]!=0 && i<n){
                if(a[(h+i)%n]==key){
                        printf(" Search element %d is found at index %d\n",key,(h+i)%n);
                        found=1;
                        break;
                }
                else
                i++;
        }
        if(i==n || found==0)
                printf("Search element %d is not found\n",key);
}
void display(int n){
        int i=0;
        for(i=0;i<n;i++)
printf("%d\t",a[i]);
        printf("\n");
}
void main(){
        int n,opt,key;
        printf("Enter the table size\n");
        scanf("%d",&n);
        do{
        printf("1.INSERTION\t");
        printf("2.SEARCH\t");
        printf("3.DISPLAY\t");
        printf("4.EXIT\t");
        printf("\n");
        printf("Enter your choice\n");
        scanf("%d",&opt);
        switch(opt){
                case 1:
                        printf("Enter the element to insert\n");
                        scanf("%d",&key);
                        insert(key,n);
                        break;
                case 2:
                        printf("Enter the element to search\n");
                        scanf("%d",&key);
                        search(key,n);
                        break;
                case 3:
                        printf("Elements of hash table are:\n");
                        display(n);
                        break;
                }
        }while(opt!=4);
    }                           