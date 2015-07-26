#include <iostream>
#include <iomanip>
using namespace std;

const int Capacity = 10;
const int Weight[] = {0,2,2,6,5,4};
const int Value[] = {0,6,3,5,4,6};
const int Num = sizeof(Weight)/sizeof(int) - 1;
int X[Num + 1];
void PackageZero2One(int Table[][Capacity + 1],const int W[],const int V[],const int num);
void Answer(int Table[][Capacity + 1],const int num);
int main(){
 int table[6][11] = {0};
 PackageZero2One(table,Weight,Value,Num);
 for(int i = 0;i <= Num;i++){
   cout<<setfill('0');
   for(int j = 0 ;j <= Capacity;j++){
     cout<<setw(2)<<table[i][j]<<" ";
   }
   cout<<endl;
 }
 Answer(table,Num);
 for(int i = 1;i <= Num;i++)
    cout<< X[i]<<" ";

 return 0;
}

void PackageZero2One(int Table[][Capacity + 1],const int W[],const int V[],const int num){
      for(int i = 0;i <= Capacity; i++){
        if(i < W[num]) 
	    Table[num][i] = 0;
        else	
            Table[num][i] = V[num];
      }
      
      int i;
      for(i = num - 1;i >= 1; i--){
         for(int j = 0;j <= Capacity ; j++){
	    if(j < W[i])
                 Table[i][j] = Table[i + 1][j]; 
	    else{
	         if(Table[i + 1][j] > Table[i + 1][j - W[i]] + V[i])
		     Table[i][j] = Table[i + 1][j];
		 else
                     Table[i][j] = Table[i + 1][j - W[i]] + V[i];
	    } 
	 }
      }
}

void Answer(int Table[][Capacity + 1],const int num){
    int j = Capacity;
    int i;
    for(i = 1;i <= num - 1; i++){
        if(Table[i][j] == Table[i + 1][j])
	    X[i] = 0; 	
        else{
	    X[i] = 1;
	    j = j - Weight[i];
	}
        X[num] = Table[i][j] ? 1 : 0;
    }
}

