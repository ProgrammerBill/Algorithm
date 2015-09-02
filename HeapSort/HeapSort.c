#include<stdio.h>
#define leftchild(i) ((2)*(i)) 
void swap(int *a,int *b);
void HeapSort(int unsorted[],int len);
void PercDown(int unsorted[],int i,int len);
int main(){
 int a[] = {1,3,5,4,7,8,10,6,2,9};
 HeapSort(a,10);
 int i;
 for(i = 0 ;i < 10;i++)
     printf("%d ",a[i]);
 return 0;
}
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void HeapSort(int unsorted[],int len){
    if(unsorted == NULL || len <= 0) return;
    int i;
    for(i = len / 2 ;i >= 0;i--){
       PercDown(unsorted,i,len); 
    }
    for(i = len - 1;i > 0 ;i--){
      swap(&unsorted[0],&unsorted[i]);
      PercDown(unsorted,0,i);
    }

}

void PercDown(int unsorted[],int i,int len){
    int Child;
    int tmp;
    for(tmp = unsorted[i];leftchild(i) + 1 < len;i = Child){
        Child = leftchild(i);
        if(Child != len - 1 && unsorted[Child + 1] > unsorted[Child] ){
	    ++Child;
	}
        if(tmp < unsorted[Child]){
	    unsorted[i] = unsorted[Child]; 
	}
        else
	    break;	
    }
    unsorted[i] = tmp;
}

