#include<stdio.h>
typedef enum{
 false,true
}bool;
void CockTail(int unsorted[],int len){
    bool swapped = true;
    int i,j;
    int bound = 0;
    int bottom = 0;
    int top = len - 1;
    while(swapped){
        swapped = false;
        for(i = bottom ; i < top;i++){
            if(unsorted[i] > unsorted[i + 1]){
                int tmp = unsorted[i];
                unsorted[i] = unsorted[i + 1];
                unsorted[i + 1] = tmp;		
	        swapped =true;
		bound = i;
	    }	    
	}
        for(i = 0;i < len;++i)
		printf("%d ",unsorted[i]);
        printf("\n");
	top = bound;
        for(j = top; j > bottom;j--){
	    if(unsorted[j] < unsorted[j - 1]){
	        int tmp = unsorted[j];		    
	        unsorted[j] = unsorted[j - 1];
	        unsorted[j - 1] = tmp;
	        swapped = true;	
		bound = i;
	    }
	}
        bottom = bound;	
        for(i = 0;i < len;++i)
		printf("%d ",unsorted[i]);
        printf("\n");
    }

}

int main(){
  int a[] = {6,2,4,1,5,9};
  CockTail(a,6);   
  int i;
  for(i = 0 ; i < 6;i++){
      printf("%d ",a[i]);
  }	
  return 0;
}
