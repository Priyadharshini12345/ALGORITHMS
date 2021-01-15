#include<stdio.h>
#include<stdlib.h>
struct node{
        int data;
        struct node* next;
};
struct node* head[50]={NULL},*c;
void insert(int s,int n){
        int hkey=s%n;
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=s;
        newnode->next=NULL;
        if(head[hkey]==NULL)
                head[hkey]=newnode;
        else{
                c=head[hkey];
                while(c->next!=NULL){
                        c=c->next;
                }
                c->next=newnode;
        }
}
void search(int s,int n){
        int hkey=s%n;
        int flag=1;
        c=head[hkey];
        while(c!=NULL){
                if(c->data==s){
                        flag=0;
                        printf("Search element is found at index %d\n",hkey);
                        break;
                }
 else
                        c=c->next;
        }
        if(flag==1)
                printf("Search element is not found\n");
}
void display(int n){
        int i;
        printf("ELEMENTS OF HASH TABLE:\n");
        for(i=0;i<n;i++){
                if(head[i]==NULL)
                        continue;
                else{
                        c=head[i];
                        while(c!=NULL){
                                printf("%d\t",c->data);
                                c=c->next;
                        }
                }
        }
        printf("\n");
}
void main(){
        int n,s,ch;
        printf("Enter the size of the hash table\n");
        scanf("%d",&n);
        do{
        printf("1.INSERT\t 2.DISPLAY\t 3.SEARCH\t 4.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
          switch(ch){
                case 1:
                        printf("Enter the element to insert\n");
                        scanf("%d",&s);
                        insert(s,n);
                        break;
                case 2:
                        display(n);
                        break;
                case 3:
                        printf("Enter the key element to search\n");
                        scanf("%d",&s);
                        search(s,n);
                        break;
        }
        }while(ch!=4);
}