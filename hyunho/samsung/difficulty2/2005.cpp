/*
2005. 파스칼의 삼각형
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5P0-h6Ak4DFAUq&categoryId=AV5P0-h6Ak4DFAUq&categoryType=CODE

< input >
1
4     
 
 

< output >
#1
1
1 1
1 2 1
1 3 3 1

*/
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {   

    int testSize = 0 ;
    scanf("%d" , &testSize ) ;

   	int T = 0 ;
    while( T < testSize ) {

    	int size = 0 ;
    	scanf( "%d" , &size ) ;

    	int pasArr[size][size] ;

   		for (int i = 0 ; i < size ; i++) {
        	for (int j = 0; j < i + 1 ; j++) {
         	   if (j == 0 || (j==i)) {
        	        pasArr[i][j] = 1;
      	          continue;
     	       }
      	      	pasArr[i][j] = pasArr[i - 1][j - 1] + pasArr[i - 1][j];
        	}
    	}

    	printf("#%d\n" , ( T + 1 ) ) ;
    	for (int i = 0; i < size ; i++) {
        	for (int j = 0; j < i + 1 ; j++) {
      	      printf("%d ", pasArr[i][j]);
    	    }
    	    printf("\n");
  	  	}
    	T++ ;
    }
    return 0;
}






















