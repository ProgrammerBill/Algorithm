#include <stdio.h>
#include <string.h>

void LPS_DP(char * arr);
int main(){
  char a[] ="ananabhijk";
  LPS_DP(a);  
  return 0;
}

void LPS_DP(char *arr){
  if(arr == NULL) return;
  int maxlen = 0;
  int maxindex = 0 ;
  int TLen = strlen(arr);
  int Dp[TLen][TLen];
  int i;
  for(i = 0 ;i < TLen;i++){
      Dp[i][i] = 1;
      if(arr[i - 1] == arr[i] && i - 1 > 0){
          Dp[i - 1][i] = 1; 
      } 
  }
  int len,begin;
  for(len = 2;len < TLen;len++){
     for(begin = 0;begin < TLen - len;begin++){
         int end = begin + len;
         if((arr[begin] == arr[end]) && (Dp[begin + 1][end - 1]) == 1){
	      Dp[begin][end] = 1;
	      if(end - begin + 1 > maxlen){
	          maxlen = end - begin + 1; 
	          maxindex = begin;
	      }
	 }
     }
  }
  for(i = 0;i < maxlen;i++)
      printf("%c",arr[i + maxindex]);
  printf("\n");
}
