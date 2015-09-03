#include <stdio.h>
#include <string.h>
void LCS_dp(const char *a,const char *b);
int main(){
 char a[] = "aaaba";
 char b[] = "abaa";
 LCS_dp(a,b); 
 return 0;
}

void LCS_dp(const char *a,const char *b){
   int Cmap[1000][1000];
   int alen = strlen(a);
   int blen = strlen(b);
   int i,j;
   int maxlen = 0,maxindex = 0;
   for( i = 0 ;i <= alen;i++){
      for(j = 0; j <= blen;j++){
          if(a[i] == b[j]){
	      if(i && j){
	          Cmap[i][j] = Cmap[i - 1][j - 1] + 1;
	      }
	      if(i == 0 || j == 0){
	          Cmap[i][j] = 1;
	      }
              if(maxlen < Cmap[i][j]){
	          maxlen = Cmap[i][j];
		  maxindex = i - maxlen + 1;
	      }
	  }
	  else
	      Cmap[i][j] = 0;
      }
   }

   for(i = 0 ; i <= alen;i++){
       for(j = 0 ; j <= blen;j++){
           printf("%d ",Cmap[i][j]);
       }
       printf("\n");
   }


   printf("maxlen = %d\n",maxlen);
   printf("maxindex = %d\n",maxindex);

   for(i = 0;i < maxlen;i++)
	   printf("%c",a[maxindex + i]);
   printf("\n");
}
