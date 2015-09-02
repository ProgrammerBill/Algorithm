#include<stdio.h>
typedef enum{
 false,true
}bool;

void swap(int *left,int *right);
void BubbleSort(int unsort[],int len);
void BubbleSort1(int unsort[],int len);
int main(){
 int a[10] = {1,3,32,26,17,99,10,18,24,65};
 int len = 10;
 //BubbleSort(a,len);
 BubbleSort1(a,len);
 int i;
 for(i = 0;i < len;i++){
    printf("%d ",a[i]); 
 }
}

void swap(int *left,int *right){
    int tmp = *left;
    *left = *right;
    *right = tmp;
}

void BubbleSort(int unsort[],int len){
    int i,j;
    for(i = 0;i < len;i++){
        for(j = 1;j < len - i;j++){
	    if(unsort[j - 1] > unsort[j])
		    swap(&unsort[j - 1],&unsort[j]);
	}
    }    
}

void BubbleSort1(int unsort[],int len){
   printf("Bubble sort 1\n");
   int j;
   int k = len;
   bool flag = true;
   while(flag){
     flag = false;
     for(j = 1;j < k;j++){
         if(unsort[j - 1] > unsort[j]){
		swap(&unsort[j - 1],&unsort[j]);
	        flag = true;
	 }
         k--;	 
     }   
   }
}
