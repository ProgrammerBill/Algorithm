#include<stdio.h>
int Op(int a,char Op,int b);
int com(char exp[]);
const int maxSize = 1024;
int main(){
 char buf[1024];
 while(scanf("%s",buf) != EOF){
     printf("%d\n",com(buf));
 }

 return 0;
}
int Op(int a,char Op,int b){
    if(Op == '+') return a + b;
    if(Op == '-') return a - b;
    if(Op == '*') return a * b;
    if(Op == '/'){ 
        if(b == 0){
	    //Error
	    return 0;
	} 
	else
	    return a/b;
    }
}
int com(char exp[]){
    int i,a,b,c;
    int stack[maxSize];int top = -1;
    
    char op;
    for(i = 0;exp[i] != '\0';++i){
         if(exp[i] >= '0' && exp[i] <= '9')
		stack[ ++top ] = exp[i] - '0';  
         else{
	        op = exp[i];
                b = stack[ top-- ];
		printf("b = %d\n",b);
		a = stack[ top-- ];
		printf("a = %d\n",a);
                c = Op(a,op,b);
		printf("c = %d\n",c);
	        stack[ ++top ] = c; 
	 
	 }  
    }
    return stack[top];

}
