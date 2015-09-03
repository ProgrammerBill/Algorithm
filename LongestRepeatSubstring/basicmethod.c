/*Longest Repeated Substring*/
#include <stdio.h>
#include <string.h>

int comlen(const char * a,const char *b);
void LRS_base(const char *a,int size);
void outputLRS(const char * arr,int maxindex,int maxlen);
int main(){
 char a[] = "banana";
 LRS_base(a,strlen(a)); 
 return 0;
}

int comlen(const char *a,const char *b){
    int len = 0 ;
    while(*a && *b && *a++ == *b++){
        ++len;
    }
    return len;
}

void LRS_base(const char *a,int size){
    int i,j;
    int maxlen = 0;
    int maxindex = 0;
    for(i = 0;i < size;i++){
        for(j = i + 1;j < size;j++){
	   int len = comlen(&a[i],&a[j]);
	   if(maxlen < len){
	       maxlen = len;
	       maxindex = i;
	   }
	} 
    }
    outputLRS(a,maxindex,maxlen);
}

void outputLRS(const char *arr,int maxindex,int maxlen){
    if(maxlen == 0){
        printf("NULL LRS\n");
	return;
    }
    printf("The len of LRS is %d\n",maxlen);
    int i = maxindex;
    while(maxlen--){
        printf("%c",arr[i++]); 
    }
    printf("\n");
}
