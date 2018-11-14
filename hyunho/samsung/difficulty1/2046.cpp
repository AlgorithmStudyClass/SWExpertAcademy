/*
2046. 스탬프 찍기 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QKdT6AyYDFAUq&categoryId=AV5QKdT6AyYDFAUq&categoryType=CODE

< input >
3

< output >
###

*/
#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	for( int i = inputNum ; i > 0 ; i-- ) {

		printf("#" ) ;
	}
	printf( "\n" ) ;

	return 0 ;
}


