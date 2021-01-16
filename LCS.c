#include<stdio.h>
#include<string.h>
char s1[50],s2[50];
int table[50][50];
void LCS(char s1[50],char s2[50]){
        int i,j,index,flag=0;
        int x=strlen(s1);
        int y=strlen(s2);
        for(i=0;i<=x;i++)
                table[i][0]=0;
        for(j=0;j<=y;j++)
                table[0][j]=0;
        for(i=1;i<=x;i++){
                for(j=1;j<=y;j++){
                        if(s1[i-1]==s2[j-1])
                                table[i][j]=table[i-1][j-1]+1;
                        else if(table[i-1][j]>=table[i][j-1])
                                table[i][j]=table[i-1][j];
                        else
                                table[i][j]=table[i][j-1];
                }
        }
        index=table[x][y];
        char res[index+1];
        res[index]='\0';
        i=x,j=y;
        while(i>0 && j>0){
                if(s1[i-1]==s2[j-1]){
                        res[index-1]=s1[i-1];
                        i--;
                        j--;
                        index--;
                   }
                else if(table[i-1][j]>table[i][j-1])
                        i--;
                else
                        j--;
        }
        printf("String 1 entered:%s\n",s1);
        printf("String 2 entered:%s\n",s2);
        printf("Longest subsequence obtained from the string 1 and string 2 is %s\n",res);
        
}
void main(){
        printf("Enter the first string\n");
        scanf("%s",s1);
        printf("Enter the second string\n");
        scanf("%s",s2);
        LCS(s1,s2);
}