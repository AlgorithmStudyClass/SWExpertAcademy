/*
1989. 초심자의 회문 검사
https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PyTLqAf4DFAUq&categoryId=AV5PyTLqAf4DFAUq&categoryType=CODE

< input >
3
level     
samsung
eye        
 
 

< output >
#1 1
#2 0
#3 1
 
 
 
*/


#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std ;

int main() {

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		char A[11] = "" ;
		char B[11] = "" ;

		scanf( "%s" , A ) ;

		for( int j = 0 ; j < strlen( A ) ; j++ )
			B[j] = A[ ( strlen( A ) -1 ) - j ] ;

		printf("#%d " , ( i + 1 ) ) ;
		if( strcmp( A , B ) == 0  )
			printf("1\n" ) ;
		else
			printf("0\n" ) ;

		i++ ;
	}

	return 0 ;
}













