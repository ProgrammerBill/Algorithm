#include<stdio.h>
void swap(int *a,int *b);
void InsertionSort(int unsorted[],int len);
int main(){
 int a[10] = {1,3,2,6,9,10,5,4,7,8};
 InsertionSort(a,10);
 int i;
 for(i = 0;i < 10;i++)
     printf("%d ",a[i]);
 return 0;
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void InsertionSort(int unsorted[],int len){
     if(unsorted == NULL || len <= 0) return;
     int i,j;
     for(i = 1;i < len;i++){
	 int tmp = unsorted[i];
         for(j = i ; j > 0 && unsorted[j - 1] > tmp;j--){
	     unsorted[j] = unsorted[j - 1];    
	 }
	 unsorted[j] = tmp;
     }
}
