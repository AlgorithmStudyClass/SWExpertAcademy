/*
2025. N줄덧셈
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QFZtaAscDFAUq&categoryId=AV5QFZtaAscDFAUq&categoryType=CODE

< input >
10

< output >
55

*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int main() {

	int inputNum = 0 ;
	scanf("%d" , &inputNum ) ;

	int sum = 0 ;
	for( int i = inputNum ; i >= 1 ; i-- )
		sum += i ;

	printf( "%d\n" , sum ) ;

	return 0 ;
}


