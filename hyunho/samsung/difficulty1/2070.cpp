/*
2071. 큰 놈, 작은 놈, 같은 놈
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQ6qqA40DFAUq&categoryId=AV5QQ6qqA40DFAUq&categoryType=CODE

< input >
3
3 8 
7 7 
369 123 

< output >
#1 <
#2 =
#3 >
 
*/
#include<iostream>
#include<stdio.h>
using namespace std ;

int main() {

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int numArr[2] = { 0 };
		for( int j = 0 ; j < 2 ; j++ ) {
			scanf("%d" , &numArr[j] ) ;
		}

		printf( "#%d " , ( i + 1 ) ) ;

		if( numArr[0] < numArr[1] )
			printf("<\n") ;
		else if( numArr[0] == numArr[1] )
			printf("=\n") ;
		else
			printf(">\n") ;

		i++ ;
	}
	return 0 ;
}


