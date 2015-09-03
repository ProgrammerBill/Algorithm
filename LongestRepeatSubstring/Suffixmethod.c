#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pstrcmp(const void *p,const void *q){
    return strcmp(*(char **)p,*(char **)q);
}

int comlen(char *a,char *b){
     int len = 0;
     while(*a && *b && *a++ == *b++){
        ++len;
     }
     return len;
}

void LRS_Suffix(char * arr){
    int len = strlen(arr);
    char *suff[30];

    int suff_index = 0 ;
    int maxlen = 0;
    int i;
    int size = strlen(arr);
    for(i = 0 ; i < size;i++){
        suff[i] = &arr[i]; 
    }
    qsort(suff,size,sizeof(char *),pstrcmp);
    //for(i = 0 ; i < size;i++){
    //    printf("%s\n",suff[i]);
    //}
    for(i = 0 ;i < len - 1;i++){
       int len = comlen(suff[i],suff[i+1]);
       if(len > maxlen){
           maxlen = len;
           suff_index = i;
       } 
    }
	    printf("%s",suff[suff_index]);
}


int main(){
 char a[] = "banana";
 LRS_Suffix(a);
 return 0;
}
