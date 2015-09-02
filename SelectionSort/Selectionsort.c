#include<stdio.h>

void selectionsort(int unsorted[],int len);
void swap(int *a,int *b);
int main(){
 int a[] = {1,3,2,7,6,5,4,9,10,8};
 selectionsort(a,10);
     int i;
     for(i = 0 ;i < 10; i++){
         printf("%d ",a[i]); 
     }
 return 0;
}
void selectionsort(int unsorted[],int len){
  if(unsorted == NULL || len <= 0) return;
  int i,j,Mindex;
  for(i = 0 ; i < len; i++){
     Mindex = i;
     for(j = i + 1;j < len; j++){
         if(unsorted[Mindex] > unsorted[j]){
	     Mindex = j;
	 } 
     }
     swap(&unsorted[Mindex],&unsorted[i]);
  }
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
