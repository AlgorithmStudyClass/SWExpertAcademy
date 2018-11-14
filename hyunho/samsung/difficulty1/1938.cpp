/*
1938. 아주 간단한 계산기
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PjsYKAMIDFAUq&categoryId=AV5PjsYKAMIDFAUq&categoryType=CODE

< input >
8 3

< output >
11
5
24
2

*/

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std ;

int main() {

	int inputNumArr[2] = { 0 } ;
	for( int i = 0 ; i < 2 ; i++ )
		scanf("%d" , &inputNumArr[i] ) ;

	printf("%d\n" , inputNumArr[0] + inputNumArr[1] ) ;
	printf("%d\n" , inputNumArr[0] - inputNumArr[1] ) ;
	printf("%d\n" , inputNumArr[0] * inputNumArr[1] ) ;
	printf("%d\n" , inputNumArr[0] / inputNumArr[1] ) ;

	return 0 ;
}


