#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
/*
 *From bottom to top
 * */
int Matrix_Chain_Order(int *P,int **Table,int N,int **S);
void Print_Optimal_Parens(int **s,int i,int j);
/*
 *From top to bottom
 * */
int Memorized_Matrix_Chain(int *P,int **Table,int N);
int LookUp_Chain(int *P,int **Table,int i,int j);

int main(){
 int n = 6;	
 int *p = (int*)malloc(sizeof(int) * (n + 1));
 int **table = (int**)malloc(sizeof(int *) * n);
 int **record = (int **)malloc(sizeof(int *) * n);
 p[0] = 30;
 p[1] = 35;
 p[2] = 15;
 p[3] = 5;
 p[4] = 10;
 p[5] = 20;
 p[6] = 25;
 for(int i = 0 ; i < n ; i++){
   table[i] = (int *)malloc(sizeof(int) * n);
   record[i] = (int *)malloc(sizeof(int) * n);
 }
 cout<<"Basic Dyanmic Programming"<<endl;
 int ret = Matrix_Chain_Order(p,table,n,record);
 Print_Optimal_Parens(record,0,n -1);
 cout<<endl;
 cout<<"the calculate time = "<<ret<<endl;
 cout<<endl;
 cout<<"Memorized one"<<endl;
 ret = Memorized_Matrix_Chain(p,table,n); 
 cout<<ret<<endl;
 return 0;
}

int Matrix_Chain_Order(int *P,int ** Table,int N,int **S){
   /*
    *the link which length is 1 cost 0
    * */
   for(int i = 0 ;i < N;i++){
       Table[i][i] = 0; 
   }
   /*
    *l is the length of the link
    * */
   for(int l = 2;l <= N;l++){
     /*
      *i is always the first elemtn of the link
      * **/	   
     for(int i = 0;i <= N - l;i++){
        /**
	 *j is the last element of the link
	 * */
	int j = i + l - 1;
        /*initialized the value
	 * */
	Table[i][j] = INT_MAX; 
        for(int k = i ; k < j;k++){
          int tmp = Table[i][k] + Table[k+1][j] + P[i] * P[k + 1] * P[j + 1]; 
          if(tmp < Table[i][j]){
	    Table[i][j] = tmp;
	    S[i][j] = k;
	  } 
        }
     }   
   }
   return Table[0][N - 1];
}

void Print_Optimal_Parens(int **s,int i,int j){
    if(i == j){
      cout<<"A"<<i+1;    
    }
    else{
      cout<<"(";
      Print_Optimal_Parens(s,i,s[i][j]); 
      Print_Optimal_Parens(s,s[i][j] + 1,j); 
      cout<<")"; 
    }
}
int Memorized_Matrix_Chain(int *P,int **Table,int N){
   for(int i = 0 ; i < N;i++){
     for(int j = i ;j < N;j++){
         Table[i][j] = INT_MAX;           
     } 
   }
  return  LookUp_Chain(P,Table,0,N - 1);
}
int LookUp_Chain(int *P,int **Table,int i,int j){
   if (Table[i][j] < INT_MAX)
       return Table[i][j];
   if(i == j){
       Table[i][j] = 0;
   }
   else{
       for(int k = i; k < j;k++){
         int tmp = LookUp_Chain(P,Table,i,k) + LookUp_Chain(P,Table,k + 1,j) + P[i] * P[k + 1] * P[j + 1];
         if(tmp < Table[i][j]){
	   Table[i][j] = tmp;
	 }	 
       }
   }
   return Table[i][j];
}
