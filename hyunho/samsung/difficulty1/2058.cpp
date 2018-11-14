/*
2058. 자릿수 더하기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QPRjqA10DFAUq&categoryId=AV5QPRjqA10DFAUq&categoryType=CODE

< input >
6789
< output >
30
 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	int num = 0 ;
	scanf("%d" , &num ) ;

	int divideArr[4] = { 1000 , 100 , 10 , 1 } ;
	int resultArr[4] = { 0 } ;
	int sum = 0 ;
	for( int i = 0 ; i < 4 ; i++ ) {

		resultArr[i] = num / divideArr[i] ;
		num = num % divideArr[i] ;

		sum += resultArr[i] ;
	}

	printf( "%d\n" , sum ) ;

	return 0 ;
}


