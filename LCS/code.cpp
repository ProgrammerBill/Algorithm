#include<iostream>
#include<string>
#include<vector>
using namespace std;
template <typename T>
void Longest_Common_SubSequence(const T&X,const T&Y,T&S);
int main(){
 string s1 = "ABCBDAB";
 string s2 = "BDCABA";
 string s3;
 Longest_Common_SubSequence(s1,s2,s3);
 cout<<s3<<endl;
 return 0;
}

template <typename T>
void Longest_Common_SubSequence(const T&X,const T&Y,T&S){
    const size_t len1 = X.size();
    const size_t len2 = Y.size();
    vector< vector<unsigned int> >A(len1+1,vector<unsigned int>(len2 + 1));
    vector< vector<unsigned int> >B(len1+1,vector<unsigned int>(len2 + 1));
    const int West = 1;
    const int North = 2;
    const int NorthWest = 3;
   
   
    for(int i = 0 ; i < len1;i++){
        for(int j = 0 ; j < len2;j++){
           if(X[i] == Y[j]){
             A[i + 1][j + 1] = A[i][j] + 1;	      
	     B[i + 1][j + 1] = NorthWest;
	   }
           else{
	     if(A[i][j + 1] >= A[i + 1][j]){
	         A[i + 1][j + 1] = A[i][j + 1];
		 B[i + 1][j + 1] = North; 
	     }
	     else{
	         A[i + 1][j + 1] = A[i + 1][j]; 
		 B[i + 1][j + 1] = West; 
	     } 
	   }	   
	}
    }


    S.resize(A[len1][len2]);
    int i = len1;
    int j = len2;
    int k = A[len1][len2] - 1;
    while(k >= 0 && i >=0 && j >=0){
        if(B[i][j] == NorthWest){
            S[k--] = X[i-1];
	    i--;
            j--;	    
	} 
        else if(B[i][j] == North){
	    i--;
	} 
	else if(B[i][j] == West){
	    j--;
	}
	else
           break;
    }
}
