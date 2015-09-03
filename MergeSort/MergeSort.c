#include <stdio.h>
#include <stdlib.h>
void MSort(int unsorted[],int TmpArray[],int left,int right);
void MergeSort(int unsorted[],int len);
void Merge(int unsorted[],int TmpArray[],int Lpos,int Rpos,int RightEnd);

int main(){
 int a[] = {1,9,10,2,5,4,6,7,3,8};
 MergeSort(a,10);
 int i;
 for(i = 0 ; i < 10;i++)
     printf("%d ",a[i]);
 return 0;
}

void MergeSort(int unsorted[],int len){
   if(unsorted == NULL || len <= 0) return;
   int *TmpArray = (int*)malloc(sizeof(int) * len); 
   if(TmpArray != NULL){
       MSort(unsorted,TmpArray,0,len - 1);
       free(TmpArray);
   }
   else{
       printf("No Space for tmp array!\n");
       exit(1);
   }    
}


void MSort(int unsorted[],int TmpArray[],int left,int right){
  int Center;
  if(left < right){
      Center =( left + right ) / 2; 
      MSort(unsorted,TmpArray,left,Center);
      MSort(unsorted,TmpArray,Center + 1,right);
      Merge(unsorted,TmpArray,left,Center + 1,right);
  }
}

void Merge(int unsorted[],int TmpArray[],int Lpos,int Rpos,int RightEnd){
   int i,LeftEnd,NumElements,TmpPos;
   LeftEnd = Rpos - 1;
   TmpPos = Lpos;
   NumElements = RightEnd - Lpos + 1;
   
   while(Lpos <= LeftEnd && Rpos <= RightEnd){
       if(unsorted[Lpos] <= unsorted[Rpos])           
           TmpArray[TmpPos++] = unsorted[Lpos++]; 
       else 
	   TmpArray[TmpPos++] = unsorted[Rpos++];    
   }
   while(Lpos <= LeftEnd)
	   TmpArray[TmpPos++] = unsorted[Lpos++];
   while(Rpos <= RightEnd)
	   TmpArray[TmpPos++] = unsorted[Rpos++];
   for(i = 0;i < NumElements;i++,RightEnd--)
	   unsorted[RightEnd] = TmpArray[RightEnd];
}
