#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b);
void QuickSort(int unsorted[],int len,int left,int right);
int Partition(int unsorted[],int len,int left,int right);
int main(){
   int a[] = {1,3,2,6,5,4,8,9,10,7};
   QuickSort(a,10,0,9);
   int i;
   for(i = 0;i < 10;++i)
       printf("%d ",a[i]);
   return 0;
}
void QuickSort(int unsorted[],int len,int left,int right){
   int pivot = Partition(unsorted,len,left,right);
   if(pivot < 0 )return;
   if(pivot > left)
        QuickSort(unsorted,len,left,pivot - 1);
   if(pivot < right)
        QuickSort(unsorted,len,pivot + 1,right);
}

int Partition(int unsorted[],int len,int left,int right){
   if(unsorted == NULL || len < 0 ||left < 0 || right >= len ) return -1;
   int size = right - left + 1;      
   srand(time(NULL)); 
   int index =left +  rand() % size;
   swap(&unsorted[index],&unsorted[right]);     
   int tmp = unsorted[right];
   int j = left - 1;
   int i;
   for(i = left;i < right;++i){
       if(unsorted[i] < tmp){
           ++j;
    	   if(i != j)
	       swap(&unsorted[i],&unsorted[j]);
       } 
   }
   ++j;
   swap(&unsorted[j],&unsorted[right]);
   return j;
}

void swap(int *a,int *b){
   int tmp = *a;
   *a = *b;
   *b = tmp;
}
