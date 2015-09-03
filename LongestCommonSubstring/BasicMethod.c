/* Longest Common Substring*/
#include<stdio.h>
#include<string.h>
int comlen(const char *a,const char *b);
void LCS_basic(const char *a,const char *b);
int main(){
 char a[] = "aaaba";
 char b[] = "abaa";
 LCS_basic(a,b);
 return 0;
}

int comlen(const char *a,const char *b){
    int len = 0;
    while(*a && *a++ == *b++){
        ++len;
    }
    return len;
}

void LCS_basic(const char *a,const char *b){
    int alen = strlen(a);
    int blen = strlen(b);
    int i,j;
    int maxlen = 0;
    int maxindex = 0;
    for(i = 0 ; i < alen;i++){
        for(j = 0 ; j < blen;j++){
	    int len = comlen(&a[i],&b[j]);
	    if(len > maxlen){
		    maxlen = len;
	            maxindex = i;
	    }    
	} 
    }
    for(i = 0;i < maxlen;i++)
	    printf("%c",a[i + maxindex]);
    printf("\n");
}
