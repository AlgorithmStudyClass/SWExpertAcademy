/*
2072. 홀수만 더하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QSEhaA5sDFAUq&categoryId=AV5QSEhaA5sDFAUq&categoryType=CODE

< input >
3
3 17 1 39 8 41 2 32 99 2
22 8 5 123 7 2 63 7 3 46
6 63 2 3 58 76 21 33 8 1   

< output >
#1 200
#2 208
#3 121

*/
#include<iostream>
#include<stdio.h>
using namespace std ;

int main() {

	int totalNum = 0 ;

	scanf( "%d" , &totalNum ) ;

	int i = 0 ;
	while( i < totalNum ) {

		int sum = 0 ;
		for( int j = 0 ; j < 10 ; j++ ) {

			int num = 0 ;
			scanf( "%d" , &num ) ;

			if( num % 2 == 1 )
				sum += num ;
		}

		printf( "#%d %d\n" , ( i + 1 ) , sum ) ;
		i++ ;
	}

	return 0 ;
}