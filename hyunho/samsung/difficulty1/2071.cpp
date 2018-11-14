/*
2071. 평균값 구하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QRnJqA5cDFAUq&categoryId=AV5QRnJqA5cDFAUq&categoryType=CODE

< input >
3
3 17 1 39 8 41 2 32 99 2
22 8 5 123 7 2 63 7 3 46
6 63 2 3 58 76 21 33 8 1   

< output >
#1 24
#2 29
#3 27
 
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
			sum += num ;
		}

		double tmpResult = sum / 10.0 ;
		
		printf( "#%d %0.f\n" , ( i + 1 ) , tmpResult ) ;

		i++ ;
	}

	return 0 ;
}


