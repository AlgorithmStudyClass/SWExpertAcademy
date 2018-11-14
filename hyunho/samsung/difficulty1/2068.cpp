/*
2068. 최대수 구하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QQhbqA4QDFAUq&categoryId=AV5QQhbqA4QDFAUq&categoryType=CODE

< input >
3 
3 17 1 39 8 41 2 32 99 2
22 8 5 123 7 2 63 7 3 46
6 63 2 3 58 76 21 33 8 1   

< output >
#1 99
#2 123
#3 76
 
*/
#include<iostream>
#include<stdio.h>
using namespace std ;

int main() {

	int totalNum = 0 ;
	scanf("%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int maxNum = 0 ; 
		scanf( "%d" , &maxNum ) ;
		for( int j = 1 ; j < 10 ; j++ ) {

			int num = 0 ;
			scanf("%d" , &num ) ;

			if( maxNum < num )
				maxNum = num ;
		}

		printf( "#%d %d\n" , ( i + 1 ) , maxNum ) ;

		i++ ;
	}
	return 0 ;
}


