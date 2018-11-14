/*
2029. 몫과 나머지 출력하기 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QGNvKAtEDFAUq&categoryId=AV5QGNvKAtEDFAUq&categoryType=CODE

< input >
3   
9 2  
15 6 
369 15        

< output >
#1 4 1
#2 2 3
#3 24 9
 

*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	int size = 0 ;
	scanf("%d" , &size ) ;

	int i = 0 ;
	while( i < size ) {

		int numArr[2] = { 0 } ;
		for( int j = 0 ; j < 2 ; j++ )
			scanf("%d" , &numArr[j] ) ;

		int resultDivideArr[2] = { 0 } ;
		
		resultDivideArr[0] = numArr[0] / numArr[1] ;
		resultDivideArr[1] = numArr[0] % numArr[1] ;

		printf("#%d %d %d\n" , ( i + 1 ) , resultDivideArr[0] , resultDivideArr[1] ) ;
		i++ ;
	}

	return 0 ;
}


