#include<stdio.h>
void ShellSort(int unsort[],int len);

int main(){
 int i;
 int a[10] = {1,3,2,6,5,4,8,9,10,7}; 
 ShellSort(a,10);
 for(i = 0 ;i < 10;i++)
     printf("%d ",a[i]);
 return 0;
}

void ShellSort(int unsort[],int len){
    if(unsort == NULL || len <= 0) return;
    int i,j,step;
    int tmp;
    for(step = len / 2;step > 0;step /= 2){
        for(i = step; i < len; i++){
            tmp = unsort[i]; 
            for(j = i ;j >= step && unsort[j - step] > tmp;j -= step){
	         unsort[j] = unsort[j - step];
	    }	    
	    unsort[j] = tmp;
	}
        	
    }
}
