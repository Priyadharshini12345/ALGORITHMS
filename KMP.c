#include<stdio.h>
#include<string.h>
void psa(char* pat,int m,int* pps){
        int len=0;
        pps[0]=0;
        int i=1;
        while(i<m){
                if(pat[i]==pat[len]){
                        len++;
                        pat[i]=len;
                        i++;
                }
                else{
                        if(len!=0)
                                len=pps[len-1];
                        else{
                                pps[i]=0;
                                i++;
                        }
                }
        }
}
void kmp(char* text,char* pattern){
        int m=strlen(pattern);
        int n=strlen(text);
        int pps[m];
        psa(pattern,m,pps);
        int i=0,j=0;
        while(i<n){
                if(pattern[j]==text[i]){
                        i++;
                        j++;
                }
                if(j==m){
                        printf("Pattern found at %d",i-j);
                        j=pps[j-1];
                        }
                else if(i<n && pattern[j]!=text[i]){
                        if(j!=0)
                                j=pps[j-1];
                        else
                                i++;
                }
        }
}
void main(){
        char text[]="aaaabcdefab";
        char pattern[]="abc";
        kmp(text,pattern);
}
         